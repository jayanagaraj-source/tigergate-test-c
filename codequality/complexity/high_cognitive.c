/* RULE: high-cognitive-complexity | lang: c */
int process(int *arr, int n) {
    int score = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            for (int j = i; j < n; j++) {
                if (arr[j] % 2 == 0 && arr[j] > arr[i]) {
                    while (arr[j] > 0) {
                        if (arr[j] % 3 == 0 || arr[j] % 5 == 0) { score += arr[j]; }
                        else if (arr[j] % 7 == 0) { score -= 1; }
                        arr[j] -= 2;
                    }
                }
            }
        }
    }
    return score;
}
