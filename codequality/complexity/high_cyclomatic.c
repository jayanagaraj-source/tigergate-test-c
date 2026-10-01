/* RULE: high-cyclomatic-complexity | lang: c */
int classify(int x, int y) {
    if (x == 1 || y == 1 || (x > 1 && y < 1)) return 1;
    else if (x == 2 || y == 2 || (x > 2 && y < 2)) return 2;
    else if (x == 3 || y == 3 || (x > 3 && y < 3)) return 3;
    else if (x == 4 || y == 4 || (x > 4 && y < 4)) return 4;
    else if (x == 5 || y == 5 || (x > 5 && y < 5)) return 5;
    else if (x == 6 || y == 6 || (x > 6 && y < 6)) return 6;
    else if (x == 7 || y == 7 || (x > 7 && y < 7)) return 7;
    else if (x == 8 || y == 8 || (x > 8 && y < 8)) return 8;
    else if (x == 9 || y == 9 || (x > 9 && y < 9)) return 9;
    else if (x == 10 || y == 10 || (x > 10 && y < 10)) return 10;
    else if (x == 11 || y == 11 || (x > 11 && y < 11)) return 11;
    else if (x == 12 || y == 12 || (x > 12 && y < 12)) return 12;
    else if (x == 13 || y == 13 || (x > 13 && y < 13)) return 13;
    else if (x == 14 || y == 14 || (x > 14 && y < 14)) return 14;
    else if (x == 15 || y == 15 || (x > 15 && y < 15)) return 15;
    else if (x == 16 || y == 16 || (x > 16 && y < 16)) return 16;
    else if (x == 17 || y == 17 || (x > 17 && y < 17)) return 17;
    else if (x == 18 || y == 18 || (x > 18 && y < 18)) return 18;
    else if (x == 19 || y == 19 || (x > 19 && y < 19)) return 19;
    else if (x == 20 || y == 20 || (x > 20 && y < 20)) return 20;
    return 0;
}
