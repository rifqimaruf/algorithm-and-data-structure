## Deskripsi Masalah
Program ini bertujuan untuk menghasilkan semua kombinasi angka dari `1` hingga `n`, di mana `n` adalah input dari pengguna. Setiap kombinasi akan ditampilkan sebagai deret angka yang dipisahkan oleh spasi. Contoh:
- Input: `n = 2` → Output:  
  ```
  1 1
  1 2
  2 1
  2 2
  ```
- Input: `n = 3` → Output:  
  ```
  1 1 1
  1 1 2
  1 1 3
  1 2 1
  1 2 2
  1 2 3
  1 3 1
  1 3 2
  1 3 3
  2 1 1
  2 1 2
  2 1 3
  2 2 1
  2 2 2
  2 2 3
  2 3 1
  2 3 2
  2 3 3
  3 1 1
  3 1 2
  3 1 3
  3 2 1
  3 2 2
  3 2 3
  3 3 1
  3 3 2
  3 3 3
  ```

**Batasan:**
- Input: Bilangan bulat positif `n` (diasumsikan `n ≤ 100` berdasarkan ukuran array global).
- Output: Semua kombinasi angka dari `1` hingga `n` dengan panjang `n`.

## Logika dan Intuisi Penyelesaian

### 1. Memahami Masalah
Program ini diminta untuk:
- Menerima input `n` dari pengguna.
- Menghasilkan semua kombinasi angka dari `1` hingga `n`, dengan panjang kombinasi sama dengan `n`.
- Menampilkan setiap kombinasi dalam baris terpisah.

Ini adalah masalah kombinasi sederhana di mana setiap posisi dalam deret dapat diisi dengan angka dari `1` hingga `n`, dan pengulangan angka diperbolehkan.

### 2. Pendekatan Awal: Rekursi
Untuk menghasilkan kombinasi:
- Gunakan pendekatan rekursif untuk mengisi setiap posisi (digit) dalam kombinasi.
- Mulai dari posisi pertama (indeks 0) hingga posisi terakhir (indeks `n-1`).
- Untuk setiap posisi, coba semua nilai dari `1` hingga `n`.

Contoh untuk `n = 2`:
- Posisi 0: Coba `1`, lalu isi posisi 1 dengan `1` atau `2` → `1 1`, `1 2`.
- Posisi 0: Coba `2`, lalu isi posisi 1 dengan `1` atau `2` → `2 1`, `2 2`.

### 3. Struktur Data
- Gunakan array global `permut[100]` untuk menyimpan kombinasi sementara.
- Variabel global `n` menyimpan panjang kombinasi yang diinginkan.

### 4. Membangun Logika Utama
- **Fungsi `printKombinasi`**:
  - Cetak isi array `permut` saat satu kombinasi lengkap (panjang = `n`).
- **Fungsi `kombinasi`**:
  - Rekursif, dengan parameter `digit_ke` yang menunjukkan posisi saat ini.
  - Basis: Jika `digit_ke == n`, kombinasi selesai, cetak.
  - Rekurens: Untuk setiap nilai dari `1` hingga `n`, isi posisi `digit_ke`, lalu lanjut ke posisi berikutnya.
- **Fungsi `main`**:
  - Ambil input `n` dari pengguna.
  - Panggil `kombinasi(0)` untuk memulai dari posisi pertama.

### 5. Alur Eksekusi
Untuk `n = 2`:
1. `kombinasi(0)`:
   - `permut[0] = 1`, panggil `kombinasi(1)`.
     - `permut[1] = 1`, panggil `kombinasi(2)` → cetak `1 1`.
     - `permut[1] = 2`, panggil `kombinasi(2)` → cetak `1 2`.
   - `permut[0] = 2`, panggil `kombinasi(1)`.
     - `permut[1] = 1`, panggil `kombinasi(2)` → cetak `2 1`.
     - `permut[1] = 2`, panggil `kombinasi(2)` → cetak `2 2`.

## Penemuan Masalah

1. **Batasan Ukuran Array**:
   - **Masalah**: Array `permut[100]` membatasi `n ≤ 100`.
   - **Dampak**: Jika `n > 100`, akan terjadi buffer overflow.
   - **Solusi Potensial**: Tambahkan pengecekan input atau gunakan alokasi dinamis dengan `malloc`.

2. **Input Negatif atau Nol**:
   - **Masalah**: Tidak ada validasi untuk `n ≤ 0`.
   - **Dampak**: Perilaku tidak terdefinisi (loop kosong atau crash).
   - **Solusi Potensial**: Tambahkan validasi di `main` untuk memastikan `n > 0`.

3. **Efisiensi**:
   - **Masalah**: Jumlah kombinasi adalah `n^n`, yang tumbuh eksponensial.
   - **Dampak**: Untuk `n` besar (misalnya `n = 10`), output sangat banyak dan lambat.
   - **Solusi Potensial**: Beri peringatan untuk `n` besar atau batasi maksimum `n`.

## Hasil Output
```
Input: n = 2
1 1
1 2
2 1
2 2

Input: n = 3
1 1 1
1 1 2
1 1 3
1 2 1
1 2 2
1 2 3
1 3 1
1 3 2
1 3 3
2 1 1
2 1 2
2 1 3
2 2 1
2 2 2
2 2 3
2 3 1
2 3 2
2 3 3
3 1 1
3 1 2
3 1 3
3 2 1
3 2 2
3 2 3
3 3 1
3 3 2
3 3 3
```