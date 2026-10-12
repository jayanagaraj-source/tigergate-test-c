/* Single C fixture for the 5 new custom code-quality rules.
 * Each section targets exactly one rule; patterns are RE2 + line-by-line safe.
 *   custom:empty-function
 *   custom:boolean-equality      (replaces the noisy magic-number)
 *   custom:unreachable-code      (same-line form)
 *   custom:commented-out-code
 *   custom:duplicate-string-literal
 */
#include <stdbool.h>
#include <stdio.h>

/* ---- custom:empty-function : empty bodies on one line ---- */
void on_init(void) {}
static void teardown(void) { }

/* ---- custom:boolean-equality : redundant comparison to a bool literal ---- */
int check(int ready, int done, int active) {
    if (ready == true) return 1;
    if (done != false) return 2;
    while (active == false) active = 1;
    return ready != true;
}

/* ---- custom:unreachable-code : dead code after a terminator on the SAME line ---- */
int get_value(int x) {
    return x + x; log_value(x);
}
int pick(int n) {
    while (n > 0) { break; next_step(); }
    return n;
}

/* ---- custom:commented-out-code : real code left inside comments ---- */
int run(int x) {
    // int old = compute(x);
    // old = old + x;
    // cache_store(old);
    return x;
}

/* ---- custom:duplicate-string-literal : same literal repeated 3+ times ---- */
void log_events(int code) {
    fprintf(stderr, "connection failed");
    if (code > 0) fprintf(stderr, "connection failed");
    fprintf(stderr, "connection failed");
}
