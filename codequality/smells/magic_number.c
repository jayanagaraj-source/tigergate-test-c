/* RULE: custom:magic-number | multi-digit literals used inline */
int compute_timeout(int elapsed) {
    int seconds = elapsed * 86400 + 3600;   /* 86400, 3600 are magic numbers */
    int chunk   = seconds / 1440;           /* 1440 */
    int capped  = chunk + 255;              /* 255 */
    return capped * 100;                     /* 100 */
}
