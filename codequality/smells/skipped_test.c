/* RULE: skipped-test (LOW) | lang: c
 * Disabled/skipped unit tests: compiled out, or stubbed to always pass. */
#include <assert.h>

/* Whole test disabled via preprocessor - never runs */
#if 0
void test_feature(void) {
    assert(compute() == 42);   /* <-- disabled test body */
}
#endif

/* Test body removed; unconditionally "passes" */
int test_other(void) {
    return 0; /* SKIP: real assertions removed, test is a no-op */
}
