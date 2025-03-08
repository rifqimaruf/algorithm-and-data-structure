## Deskripsi Masalah
Dalam kata ini, kita diminta untuk mengkuadratkan setiap digit dari sebuah angka dan menggabungkannya menjadi satu bilangan bulat. Contoh:
- Input: `9119` → Output: `811181` (karena `9² = 81`, `1² = 1`, `1² = 1`, `9² = 81` → `81-1-1-81`).
- Input: `765` → Output: `493625` (karena `7² = 49`, `6² = 36`, `5² = 25` → `49-36-25`).
- Input: `3210987654` → Output: `9410816449362516`.

**Batasan:**
- Input: Bilangan bulat (`unsigned`).
- Output: Bilangan bulat (`unsigned long long`).

## Logika dan Intuisi Penyelesaian

### 1. Memahami Masalah
Langkah pertama adalah memahami apa yang diminta:
- Kita punya angka, misalnya `9119`, yang terdiri dari digit-digit `9, 1, 1, 9`.
- Setiap digit harus dikuadratkan: `9² = 81`, `1² = 1`, dll.
- Hasil kuadrat digabungkan jadi satu angka: `811181`.
- Tujuan: Hitung hasil akhir sebagai bilangan bulat.

Ini seperti "memecah" angka, "mengubah" setiap bagian, lalu "menyusun ulang" menjadi satu.

### 2. Pendekatan Awal: Memecah Angka Secara Matematis
Ide awal adalah memisahkan digit dengan operasi matematika:
- Ambil digit paling kanan dengan `% 10` (misalnya, `9119 % 10 = 9`).
- Hapus digit itu dengan `/ 10` (misalnya, `9119 / 10 = 911`).
- Ulangi sampai angka habis.
- Simpan digit dalam array untuk diproses lebih lanjut.

Contoh manual untuk `9119`:
- Menit 1: `9119 % 10 = 9`, sisa `911`.
- Menit 2: `911 % 10 = 1`, sisa `91`.
- Menit 3: `91 % 10 = 1`, sisa `9`.
- Menit 4: `9 % 10 = 9`, sisa `0`.
- Digit: `[9, 1, 1, 9]` (dari kanan ke kiri).

Ini menunjukkan kita bisa pakai array untuk menyimpan digit, tapi kita perlu tahu jumlah digit dulu.

### 3. Menyederhanakan dengan Hitung Digit Terlebih Dahulu
Daripada langsung ekstraksi, hitung dulu jumlah digit:
- Gunakan perulangan untuk bagi angka dengan 10 sampai jadi 0.
- Contoh untuk `9119`:
  - `9119 / 10 = 911` (1 digit).
  - `911 / 10 = 91` (2 digit).
  - `91 / 10 = 9` (3 digit).
  - `9 / 10 = 0` (4 digit).
- Jumlah digit = 4.

Dengan ini, kita bisa alokasikan array dengan ukuran pasti menggunakan `malloc`.

### 4. Menangani Proses Ekstraksi dan Pengkuadratan
- **Ekstraksi**: Isi array dari kanan ke kiri (indeks tertinggi ke terendah).
- **Pengkuadratan**: Setelah digit ada di array, kuadratkan satu per satu.
- **Penggabungan**: Gabungkan hasil kuadrat dengan menggeser hasil sebelumnya:
  - Jika kuadrat dua digit (misalnya `81`), geser dengan `* 100`.
  - Jika satu digit (misalnya `1`), geser dengan `* 10`.

Contoh untuk `9119`:
- Digit: `[9, 1, 1, 9]`.
- Kuadrat: `[81, 1, 1, 81]`.
- Gabung: `0 * 100 + 81 = 81`, `81 * 10 + 1 = 811`, `811 * 10 + 1 = 8111`, `8111 * 100 + 81 = 811181`.

### 5. Membangun Logika Utama
- **Inisialisasi**:
  - Hitung jumlah digit.
  - Alokasikan array dengan `malloc`.
  - Isi array dengan digit.
- **Proses Utama**:
  - Mulai dengan `result = 0`.
  - Untuk setiap digit di array:
    - Kuadratkan.
    - Geser `result` ( `* 100` atau `* 10`).
    - Tambahkan kuadrat ke `result`.
- **Pembersihan**:
  - Bebaskan memori array dengan `free`.

## Penemuan Masalah

1. **Perulangan Tak Berujung**:
   - **Masalah**: Awalnya ada kode `while (temp > 0);` dengan titik koma, menyebabkan perulangan tak terbatas.
   - **Dampak**: Program tidak pernah menghitung digit.
   - **Solusi**: Hapus titik koma agar blok penghitungan masuk dalam perulangan.

2. **Array Tidak Terinisialisasi (SIGSEGV)**:
   - **Masalah**: Setelah menghitung digit, `temp` sudah `0`, tapi digunakan lagi di perulangan ekstraksi, sehingga array tidak terisi.
   - **Dampak**: Segmentation fault karena akses memori acak.
   - **Solusi**: Reset `temp = n` sebelum ekstraksi digit.

3. **Hasil Tidak Konsisten**:
   - **Masalah**: Output berbeda setiap kali (misalnya, `18446691235953213712`) karena array berisi nilai acak.
   - **Dampak**: Hasil salah dan tak terduga.
   - **Solusi**: Pastikan array terisi dengan digit yang benar.

4. **Hasil Nol untuk Angka Besar**:
   - **Masalah**: Untuk `3210987654`, dapat `0` alih-alih `9410816449362516`.
   - **Dampak**: Diduga overflow, tapi sebenarnya karena array tidak terisi.
   - **Solusi**: Perbaiki logika ekstraksi; overflow tidak jadi masalah karena hasil akhir muat di `unsigned long long`.

5. **Urutan Terbalik**:
   - **Masalah**: Percobaan memproses dari kanan ke kiri menghasilkan `1625364964810149` alih-alih `9410816449362516`.
   - **Dampak**: Hasil terbalik dari yang diharapkan.
   - **Solusi**: Kembali ke proses kiri-ke-kanan sesuai spesifikasi.


## Hasil Output
```
Input: 9119, Hasil: 811181
Input: 765, Hasil: 493625
Input: 3210987654, Hasil: 9410816449362516
```
