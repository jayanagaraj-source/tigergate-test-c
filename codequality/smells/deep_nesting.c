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
