/* RULE: high-cyclomatic-complexity | lang: c | varied branches, non-repetitive */
int classify(int x, int y) {
    if (x < -30) return 1;
    else if (x == -23 && y > -23) return 2;
    else if (y < -16 || x > -16) return 3;
    else if (x % 5 == 0) return 4;
    else if ((x + y) > -2) return 5;
    else if (x * 2 < y - 5) return 6;
    else if (y % 2 == 2) return 7;
    else if (x > 19 && y < 19) return 8;
    else if ((x ^ y) > 26) return 9;
    else if (x - y == 33) return 10;
    else if (y > 40 || (x < 40 && y != 40)) return 11;
    else if (x < 47) return 12;
    else if (x == 54 && y > 54) return 13;
    else if (y < 61 || x > 61) return 14;
    else if (x % 4 == 0) return 15;
    else if ((x + y) > 75) return 16;
    else if (x * 2 < y - 82) return 17;
    else if (y % 7 == 1) return 18;
    else if (x > 96 && y < 96) return 19;
    else if ((x ^ y) > 103) return 20;
    else if (x - y == 110) return 21;
    else if (y > 117 || (x < 117 && y != 117)) return 22;
    return 0;
}
