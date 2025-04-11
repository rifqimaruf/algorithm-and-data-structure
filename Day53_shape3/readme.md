# Kalkulator Ekspresi Postfix
Permasalahan ini berfokus pada evaluasi ekspresi postfix (Reverse Polish Notation) menggunakan bahasa C. Ekspresi postfix adalah notasi di mana operator mengikuti operan, misalnya `5 3 +` berarti `5 + 3`. Dalam konteks bahasa C, karena tidak ada struktur data stack bawaan, kita perlu membuat implementasi stack secara manual menggunakan alokasi dinamis dengan `malloc`.

## Logika dan Intuisi Penyelesaian
### 1. Memahami Masalah
Langkah pertama adalah memahami mekanisme ekspresi postfix:
- Ekspresi terdiri dari operan (angka) dan operator (`+`, `-`, `*`, `/`) yang dipisahkan spasi, misalnya `[5 3 + 2 *]`.
- Aturan evaluasi:
  - Ketika menemui operan, simpan ke tempat sementara.
  - Ketika menemui operator, ambil dua operan terakhir, lakukan operasi, lalu simpan hasilnya.
- Tujuan: Hitung hasil akhir dari ekspresi, seperti `(5 + 3) * 2 = 16`.
- Kita perlu struktur data untuk menyimpan operan sementara, dan stack (LIFO) adalah pilihan ideal.

### 2. Pendekatan Awal: Simulasi Manual
Ide awal adalah mengevaluasi ekspresi seperti manusia:
- Baca ekspresi dari kiri ke kanan.
- Jika operan, simpan ke stack.
- Jika operator, ambil dua operan dari stack, hitung, lalu masukkan hasilnya kembali.
- Contoh untuk `[5 3 + 2 *]`:
  - Baca `5`: Push ke stack → `[5]`.
  - Baca `3`: Push ke stack → `[5, 3]`.
  - Baca `+`: Pop `3`, pop `5`, hitung `5 + 3 = 8`, push `8` → `[8]`.
  - Baca `2`: Push ke stack → `[8, 2]`.
  - Baca `*`: Pop `2`, pop `8`, hitung `8 * 2 = 16`, push `16` → `[16]`.
  - Hasil akhir: Pop `16`.

Namun, kita perlu memikirkan:
- Bagaimana menangani input string dengan spasi?
- Bagaimana mendeteksi angka vs operator?
- Bagaimana menangani kesalahan seperti pembagian dengan nol?

### 3. Menyederhanakan Implementasi
Daripada memproses token secara kompleks, kita sederhanakan:
- Gunakan stack berbasis array untuk menyimpan operan.
- Baca ekspresi karakter demi karakter:
  - Jika digit, kumpulkan semua digit berurutan untuk membentuk angka (misalnya, `12` bukan `1` dan `2`).
  - Jika operator, ambil dua operan dari stack, hitung, lalu push hasil.
- Tambahkan validasi:
  - Cek pembagian dengan nol.
  - Cek operator tidak valid.
  - Cek ekspresi kosong.

Pendekatan ini efisien karena:
- Stack cocok untuk LIFO, sesuai kebutuhan postfix.
- Parsing sederhana dengan fungsi `isdigit` untuk deteksi angka.
- Tidak perlu struktur tambahan seperti queue atau list.

### 4. Menangani Input String
Masalah: Input pengguna berupa string (misalnya `"5 3 + 2 *"`). Solusi:
- Gunakan `fgets` untuk baca input aman (hindari buffer overflow).
- Hapus newline dengan `strcspn`.
- Proses string karakter demi karakter:
  - Lewati spasi.
  - Kumpulkan digit untuk angka.
  - Tangani operator langsung.
- Kapasitas stack dibatasi (misalnya, 100) untuk hindari overflow.

### 5. Membangun Logika Utama
- **Inisialisasi**:
  - Buat stack dengan `malloc` untuk array dinamis (`items`).
  - Set kapasitas stack (misalnya, 100).
  - Inisialisasi `top` ke `-1` untuk stack kosong.

- **Fungsi Stack**:
  - `push`: Tambah operan ke stack.
  - `pop`: Ambil operan dari stack.
  - `isEmpty`: Cek apakah stack kosong.

- **Evaluasi Ekspresi**:
  - Baca ekspresi dalam loop:
    - Jika digit, kumpulkan angka (misalnya, `123` → `num = num * 10 + digit`).
    - Push angka ke stack.
    - Jika operator:
      - Pop dua operan (`op2`, `op1`).
      - Hitung sesuai operator (`op1 + op2`, dll.).
      - Push hasil ke stack.
    - Validasi pembagian dengan nol dan operator tidak valid.
  - Setelah loop selesai, pop hasil akhir dari stack.

- **Pembersihan**:
  - Bebaskan memori stack (`items` dan `stack`) dengan `free` untuk hindari kebocoran memori.

- **Main Program**:
  - Baca input pengguna.
  - Cek ekspresi kosong.
  - Panggil `evaluatePostfix` dan tampilkan hasil dengan format dua desimal.

