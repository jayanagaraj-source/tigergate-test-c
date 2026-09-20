# tigergate-test-c

Security-test fixture for **C**, extended into a full multi-scanner playground.

This repository **deliberately** contains vulnerable code, hard-coded secrets,
outdated dependencies, and insecure infrastructure so you can validate:

| Category | What it exercises | Where |
|----------|-------------------|-------|
| **SAST** | Injection, memory safety, weak crypto, unsafe code patterns | `src/*.c` |
| **Secrets** | Cloud keys, tokens, connection strings, PEM | `src/secrets.h`, `.env`, `.npmrc`, `terraform/`, `Dockerfile` |
| **SCA** | Known-CVE deps across 6 ecosystems | `conanfile.txt`, `package.json`, `requirements.txt`, `go.mod`, `Gemfile`, `pom.xml` |
| **IaC** | Public buckets, open SGs, privileged pods, wildcard IAM | `terraform/`, `kubernetes/`, `cloudformation/`, `ansible/`, `docker-compose.yml` |
| **Container** | Old base image, root user, baked secrets | `Dockerfile` |
| **SBOM** | CycloneDX + SPDX documents | `sbom/` |

> ⚠️ Everything here is a fixture. Secrets are fake or public examples; do not
> deploy any of this, and do not copy these patterns into real code.

## Build & run

```bash
make            # build build/tigergate
make test       # run unit tests (should PASS)
make asan       # run memory-corruption probes under ASan (should ABORT)
make run        # tigergate version
```

The CLI routes each subcommand into one vulnerability class:

```bash
./build/tigergate login admin password123     # hard-coded creds
./build/tigergate find "bob' OR 1=1--"        # SQL built with sprintf
./build/tigergate ping "8.8.8.8; id"          # system() injection
./build/tigergate log '%x %x %x'              # format-string leak
./build/tigergate hash hunter2                # weak password hash
```

## Run the scanners

```bash
make scan       # runs whichever of semgrep/trivy/gitleaks/checkov/flawfinder are installed
make sbom       # regenerate SBOMs with syft (if installed)
```

CI runs the full matrix in `.github/workflows/security.yml`.

See **FINDINGS.md** for the complete inventory mapping every fixture to its
scanner category and CWE/CVE.
# tigergate-test-c
# tigergate-test-c
