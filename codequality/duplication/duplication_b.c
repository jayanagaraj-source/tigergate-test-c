/* RULE: code-duplication (LOW) | lang: c (all languages) */
#include <stdio.h>

int validate_and_sum(const int *items, int count) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        if (items[i] < 0) {
            fprintf(stderr, "negative value at %d\\n", i);
            continue;
        }
        if (items[i] > 1000) {
            fprintf(stderr, "value too large at %d\\n", i);
            continue;
        }
        total += items[i];
    }
    return total;
}

int entry_b(const int *v, int n) { return validate_and_sum(v, n) * 2; }
