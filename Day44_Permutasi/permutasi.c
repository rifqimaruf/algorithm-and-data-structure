#include <stdio.h>
#include <stdlib.h>

void printPermutasi(int n, int *permut) {
    for (int i = 0; i < n; i++) {
        printf("%d ", permut[i]);
    }
    printf("\n");
}

void permutasi(int n, int digit_ke, int *permut, int *used) {
    if (digit_ke == n) {
        printPermutasi(n, permut);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = 1;
            permut[digit_ke] = i + 1;
            permutasi(n, digit_ke + 1, permut, used);
            used[i] = 0; // Backtracking
        }
    }
}

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    int permut[100];
    int used[100] = {0}; // Array untuk menandai angka yang sudah digunakan

    permutasi(n, 0, permut, used);

    return 0;
}