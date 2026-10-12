/* RULE: deep-nesting (LOW) | lang: c (all languages) */
int deeply_nested(int a, int b, int c, int d) {
    if (a > 0) {                       /* 1 */
        for (int i = 0; i < a; i++) {  /* 2 */
            if (b > 0) {               /* 3 */
                while (b > i) {        /* 4 */
                    if (c > 0) {       /* 5 */
                        switch (d) {   /* 6 */
                            case 1:
                                if (d == 1) {   /* 7 - excessively nested */
                                    return i;
/* RULE: deep-nesting | lang: c */
int deeply_nested(int a, int b, int c, int d, int e) {
    if (a > 0) {
        for (int i = 0; i < a; i++) {
            if (b > 0) {
                while (b > i) {
                    if (c > 0) {
                        switch (d) {
                            case 1:
                                if (e > 0) {
                                    for (int j = 0; j < e; j++) {
                                        return i + j;   /* ~8 levels deep */
                                    }
                                }
                        }
                    }
                    b--;
                }
            }
        }
    }
    return 0;
}
