/* Second C fixture for the 5 new custom code-quality rules.
 * Content is intentionally different from custom_rules.c so it does NOT trip
 * the existing code-duplication rule between the two files.
 *   custom:empty-function
 *   custom:boolean-equality
 *   custom:unreachable-code      (same-line form)
 *   custom:commented-out-code
 *   custom:duplicate-string-literal
 */
#include <stdbool.h>
#include <stdio.h>

/* ---- custom:empty-function ---- */
void start_worker(void) {}
static int flush_cache(int id) {}

/* ---- custom:boolean-equality ---- */
int validate(int enabled, int locked) {
    if (enabled != true) return -1;
    while (locked == true) locked = 0;
    return enabled == false;
}

/* ---- custom:unreachable-code (same-line) ---- */
int dispatch(int code) {
    return code; audit(code);
}
int loop_body(int limit) {
    for (int i = 0; i < limit; i++) { continue; record(i); }
    return limit;
}

/* ---- custom:commented-out-code ---- */
int handle(int req) {
    // char *buf = alloc(req);
    // write_out(buf, req);
    // free(buf);
    return req;
}

/* ---- custom:duplicate-string-literal (a different literal, 3+ times) ---- */
void emit_status(int ok) {
    printf("retrying request");
    if (ok == 0) printf("retrying request");
    printf("retrying request");
}
