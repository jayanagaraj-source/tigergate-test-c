/* RULE: swallowed-error (MEDIUM) | lang: c
 * Error / return value assigned and then discarded, or ignored entirely. */
#include <stdio.h>

int do_thing(void);

void run(void) {
    int err = do_thing();
    (void)err;                  /* <-- error assigned then discarded */
    do_thing();                 /* <-- return value (possible error) ignored */
    FILE *f = fopen("/tmp/y", "r");
    (void)f;                    /* errno set on failure, never checked */
}
