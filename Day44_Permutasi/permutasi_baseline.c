#include <stdio.h>
#include <stdlib.h>

// Deklarasi variabel global
int n;
int permut[100];

void printKombinasi() {
    for (int i = 0; i < n; i++) {
        printf("%d ", permut[i]);
    }
    printf("\n");
}

void kombinasi(int digit_ke) {
    if (digit_ke == n) {
        printKombinasi();
        return;
    }

    for (int i = 1; i <= n; i++) {
        permut[digit_ke] = i; // Mengisi digit ke-digit_ke dengan nilai i
        kombinasi(digit_ke + 1); // Rekursif untuk digit berikutnya
    }
}

int main() {
    printf("n = ");
    scanf("%d", &n);

    kombinasi(0); // Memulai dari digit ke-0

    return 0;
}