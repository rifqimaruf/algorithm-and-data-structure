#include <stdio.h>
#include <stdbool.h>

#define ll long long

ll find_missing(ll m[], ll n) {
    // Asumsi: m diisi dengan n-1 elemen
    for (int p = 1; p <= n; p++) {
        bool found = false;
        for (int j = 0; j < n - 1; j++) {
            if (m[j] == p) {
                found = true;
                break;
            }
        }
        if (!found) {
            return p;
        }
    }
    return 0; // Catatan: Ini mungkin tidak tercapai
}

int main() {
    ll n;
    if (scanf("%lld", &n) != 1 || n <= 0 || n > 1000000) {
        fprintf(stderr, "Invalid array size\n");
        return 1;
    }

    ll m[1000000];
    for (int i = 0; i < n - 1; i++) {
        if (scanf("%lld", &m[i]) != 1) {
            fprintf(stderr, "Invalid input at index %d\n", i);
            return 1;
        }
    }

    printf("%lld\n", find_missing(m, n));
    return 0;
}
