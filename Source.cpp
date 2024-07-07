//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MOD 12345

int count_sequences(int n) {
    if (n == 1) {
        return 2;
    }
    else if (n == 2) {
        return 4;
    }
    else if (n == 3) {
        return 7;
    }

    int f1 = 2, f2 = 4, f3 = 7, fn;

    for (int i = 4; i <= n; i++) {
        fn = (f1 + f2 + f3) % MOD;
        f1 = f2;
        f2 = f3;
        f3 = fn;
    }

    return f3;
}

int main() {
    int n;
    printf("Enter the length of the sequence: ");
    scanf_s("%d", &n);
    if (n < 1 || n>10000) {
        printf("Error");
        return 13;
    }

    printf("%d\n", count_sequences(n));
    return 0;
}

