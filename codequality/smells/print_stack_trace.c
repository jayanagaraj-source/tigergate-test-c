/* RULE: print-stack-trace (LOW) | lang: c
 * Stack trace dumped straight to stderr instead of going through a logger. */
#include <execinfo.h>
#include <stdio.h>

void on_error(void) {
    void *bt[64];
    int n = backtrace(bt, 64);
    backtrace_symbols_fd(bt, n, 2);   /* <-- stack trace printed to stderr, not logged */
}
