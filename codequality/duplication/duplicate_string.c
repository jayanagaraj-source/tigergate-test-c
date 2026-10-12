/* RULE: custom:duplicate-string-literal | same literal repeated 3+ times */
#include <stdio.h>
void log_events(int code) {
    fprintf(stderr, "connection failed");
    if (code > 0) fprintf(stderr, "connection failed");
    fprintf(stderr, "connection failed");
}
