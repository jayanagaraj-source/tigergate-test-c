/* RULE: custom:unreachable-code | dead code after a terminator on the SAME line
 * (works with the line-by-line engine; the next-line case needs multi-line support). */
int get_value(int x) {
    return x + x; log_value(x);              /* unreachable: after return */
}

int pick(int n) {
    while (n > 0) { break; next_step(); }     /* unreachable: after break */
    for (;;) { continue; cleanup(); }         /* unreachable: after continue */
    return n;
}
