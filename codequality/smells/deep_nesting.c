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
