/* RULE: broad-catch (MEDIUM) | lang: c
 * C has no exceptions. Closest = a catch-all that handles every distinct
 * failure the same way, hiding the specific cause. */
#include <signal.h>
#include <setjmp.h>
#include <stdio.h>

static jmp_buf env;

/* One handler installed for ALL signals - overly broad */
static void catch_all(int sig) {
    (void)sig;
    longjmp(env, 1);
}

void risky(void) {
    signal(SIGSEGV, catch_all);
    signal(SIGFPE,  catch_all);
    signal(SIGILL,  catch_all);
    signal(SIGBUS,  catch_all);
    if (setjmp(env) != 0) {
        /* <-- broad handler: every different failure treated identically */
        printf("something failed\n");
    }
}
