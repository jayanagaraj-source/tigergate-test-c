/* RULE: empty-catch (MEDIUM) | lang: c
 * C has no try/catch. Closest = an error branch with an empty body: the
 * failure is detected but silently swallowed. */
#include <stdio.h>

int do_thing(void);

void risky(void) {
    int rc = do_thing();
    if (rc != 0) {
        /* <-- empty error handler: failure detected but swallowed */
    }
    FILE *f = fopen("/tmp/x", "r");
    if (f == NULL) {
        /* <-- empty error handler */
    }
}
