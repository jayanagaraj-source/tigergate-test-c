/* RULE: debugger-statement (HIGH) | lang: c
 * C has no `debugger` keyword. Closest = a hard-coded breakpoint/trap left in
 * the code. Tests whether TigerGate flags debug traps in C. */
#include <signal.h>
#include <assert.h>

void process(int data) {
    __builtin_trap();                 /* <-- hard-coded debug trap */
    raise(SIGTRAP);                   /* <-- programmatic breakpoint */
    __asm__("int3");                  /* <-- x86 breakpoint instruction */
    assert(0 && "debug breakpoint");  /* <-- debug-only abort left in code */
    (void)data;
}
