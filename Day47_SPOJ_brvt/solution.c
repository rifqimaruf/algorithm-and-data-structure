#include <stdio.h>
#include <math.h>

typedef long long ll;

void solve(ll k) {
    ll N = (-1 + sqrt(1 + 8 * k)) / 2;  
    if (N * (N + 1) / 2 < k) N++;      
    ll prev = N * (N - 1) / 2;    
    ll s = k - prev;                   
    ll m = s - 1;                       
    ll n = N;                           
    printf("%lld %lld\n", m, n);        
}

int main() {
    int T;
    scanf("%d", &T);                  
    while (T--) {
        ll k;
        scanf("%lld", &k);             
        solve(k);                       
    }
    return 0;
}

/* 
 * Cara kerja kode ini mirip seperti mencari nomor urut di daftar yang sudah diatur dari kecil ke besar.
 * Angka-angka di daftar ini dibuat dari 2^m + 2^n, misalnya 3 (2^0 + 2^1), 5 (2^0 + 2^2), dst.
 * Kita pakai rumus matematika (sqrt) untuk tebak kelompok mana (N) yang punya angka ke-k.
 * Setelah ketemu kelompoknya, kita hitung posisi di dalam kelompok itu untuk dapat m.
 * n itu sama dengan nomor kelompoknya (N).
 * Contoh: k = 5, N = 3, posisi ke-2 di kelompok N=3, jadi m = 1, n = 3, hasilnya 2^1 + 2^3 = 10.
 */