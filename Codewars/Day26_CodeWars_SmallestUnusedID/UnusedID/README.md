# README: Penjelasan Code

Solusi ini digunakan untuk mencari ID berikutnya yang belum ada dalam sebuah array ID yang sudah ada. Misalnya, jika kamu punya array ID seperti `[0, 1, 2, 3, 5]`, maka ID berikutnya yang belum digunakan adalah `4`.

### Penjelasan Code:

1. **Sorting Array**:
   - Pertama-tama, array ID diurutkan menggunakan `Array.Sort(ids)`. Hal ini untuk memudahkan pencarian ID yang hilang.

2. **Mencari ID yang Hilang**:
   - Setelah array diurutkan, kita cek satu per satu ID-nya.
   - Jika ID di indeks ke-`i` tidak sama dengan `i` (misalnya `ids[3] != 3`), berarti ID yang hilang adalah `i`.
   - Kalau ditemukan ID yang hilang, langsung dikembalikan.

3. **Jika Semua ID Ada**:
   - Kalau semua ID dari `0` sampai panjang array ada, ID berikutnya adalah angka yang setara dengan panjang array tersebut (misalnya array dengan panjang 5, ID berikutnya adalah 5).


### Catatan:
- Program ini bergantung pada array yang sudah terurut. Kalau arraynya belum terurut, fungsi ini akan mengurutkannya terlebih dahulu.
- Hasilnya adalah ID yang pertama kali hilang (ID berikutnya yang bisa digunakan).

