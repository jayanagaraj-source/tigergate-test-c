/* RULE: console-debug (INFO) | lang: c
 * Debug print statements left in code (C analog of console.log/console.debug). */
#include <stdio.h>

void handle(int x) {
    printf("DEBUG: value = %d\n", x);            /* <-- debug console statement */
    fprintf(stderr, "DEBUG: trace x=%d\n", x);   /* <-- debug console statement */
    puts("DEBUG: reached handle()");             /* <-- debug console statement */
}
