# tigergate-test-c build. Warnings are left enabled on purpose: several of
# them are the findings this fixture exists to produce.
CC      ?= cc
CFLAGS  ?= -std=gnu11 -O0 -g -Wall -Wextra -Wformat-security -Wno-unused-result
BUILD   ?= build
BIN     := $(BUILD)/tigergate
TEST    := $(BUILD)/test_app

SRC     := $(filter-out src/main.c,$(wildcard src/*.c))
OBJ     := $(patsubst src/%.c,$(BUILD)/%.o,$(SRC))

.PHONY: all test asan run sbom scan clean

all: $(BIN)

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/%.o: src/%.c src/tigergate.h src/secrets.h | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(OBJ) src/main.c
	$(CC) $(CFLAGS) src/main.c $(OBJ) -o $@

$(TEST): $(OBJ) tests/test_app.c
	$(CC) $(CFLAGS) tests/test_app.c $(OBJ) -o $@

test: $(TEST)
	./$(TEST)

# Runs the memory-corruption fixtures under AddressSanitizer. Expected to
# report errors; useful for checking that a DAST/runtime tool catches them.
asan: | $(BUILD)
	$(CC) $(CFLAGS) -fsanitize=address,undefined -DTIGERGATE_ASAN tests/asan_probe.c $(SRC) -o $(BUILD)/asan_probe
	-./$(BUILD)/asan_probe

run: $(BIN)
	./$(BIN) version

# Regenerates sbom/ from the manifests when syft is installed; the committed
# documents are the fixture and stay in place otherwise.
sbom:
	@command -v syft >/dev/null 2>&1 && syft dir:. -o cyclonedx-json=sbom/bom.cdx.json -o spdx-json=sbom/sbom.spdx.json \
	  || echo "syft not installed; using committed SBOMs in sbom/"

# Convenience wrapper around whichever scanners are on PATH.
scan:
	@command -v semgrep  >/dev/null && semgrep scan --config auto . || echo "skip: semgrep"
	@command -v trivy    >/dev/null && trivy fs --scanners vuln,secret,misconfig,license . || echo "skip: trivy"
	@command -v gitleaks >/dev/null && gitleaks detect --no-git -v || echo "skip: gitleaks"
	@command -v checkov  >/dev/null && checkov -d . || echo "skip: checkov"
	@command -v flawfinder >/dev/null && flawfinder src/ || echo "skip: flawfinder"

clean:
	rm -rf $(BUILD) test_app
