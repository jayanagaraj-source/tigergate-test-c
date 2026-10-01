/* RULE: code-duplication | lang: c | file A */
#include <stddef.h>
int validate_and_sum(const int *items, int count, int limit) {
    int total = 0;
    int rejected = 0;
    for (int i = 0; i < count; i++) {
        int value = items[i];
        if (value < 0) {
            rejected++;
            continue;
        }
        if (value > limit) {
            rejected++;
            continue;
        }
        if (value % 2 == 0) {
            total += value * 2;
        } else {
            total += value;
        }
    }
    if (rejected > count / 2) {
        return -1;
    }
    return total;
}

int entry_a(const int *v, int n) { return validate_and_sum(v, n, 1000); }
