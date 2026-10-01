/* RULE: custom:unreachable-code | statements after a control-flow exit */
int get_value(int x) {
    return x + x;
    log_value(x);          /* unreachable: after return */
}

int pick(int n) {
    if (n > 0) {
        break;
        next_step();       /* unreachable: after break */
    }
    return n;
}
