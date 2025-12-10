## Deskripsi Masalah
Program ini bertujuan untuk mengulang sebuah string sebanyak jumlah tertentu yang ditentukan oleh pengguna. Fungsi utama, `repeat_str`, menerima sebuah string dan jumlah pengulangan, lalu mengembalikan string baru yang merupakan hasil pengulangan tersebut. Contoh:
- Input: String `"abc"`, Count: `3` → Output: `"abcabcabc"`.
- Input: String `"hi"`, Count: `2` → Output: `"hihi"`.
- Input: String `"x"`, Count: `5` → Output: `"xxxxx"`.

**Batasan:**
- Input: String dengan panjang maksimum 99 karakter (ditentukan oleh buffer `str[100]` di `main`) dan jumlah pengulangan (`count`) bertipe `size_t` (bilangan bulat positif).
- Output: String baru yang dialokasikan secara dinamis, atau `NULL` jika alokasi gagal atau input tidak valid.
- Karakter null terminator (`\0`) harus ada di akhir string hasil.

## Logika dan Intuisi Penyelesaian

### 1. Memahami Masalah
Tujuan adalah membuat string baru yang merupakan pengulangan string input sebanyak `count` kali:
- String input harus digandakan secara berurutan.
- Memori untuk string hasil harus dialokasikan secara dinamis sesuai kebutuhan.
- Harus menangani kasus khusus seperti input `NULL` atau kegagalan alokasi memori.

### 2. Pendekatan Awal: Menghitung Panjang dan Alokasi
- Hitung panjang string input (`src_len`) menggunakan `strlen`.
- Total panjang string hasil = `src_len * count + 1` (tambahan 1 untuk null terminator).
- Alokasi memori menggunakan `malloc` berdasarkan total panjang.

### 3. Proses Pengulangan String
- Gunakan loop untuk menyalin string input sebanyak `count` kali ke memori yang dialokasikan.
- Setiap iterasi menyalin string pada posisi offset yang sesuai (`i * src_len`).
- Contoh untuk `"abc"`, `count = 3`:
  - Iterasi 0: Salin `"abc"` ke posisi 0.
  - Iterasi 1: Salin `"abc"` ke posisi 3.
  - Iterasi 2: Salin `"abc"` ke posisi 6.
  - Hasil: `"abcabcabc"`.

### 4. Menangani Input dan Output
- Input: String dibaca dengan `scanf` ke buffer `str`, dan jumlah pengulangan (`count`) juga dibaca dengan `scanf`.
- Proses: Panggil `repeat_str` dengan parameter `count` dan `str`.
- Output: Cetak string hasil dengan `printf`, lalu bebaskan memori dengan `free`.

### 5. Membangun Logika Utama
- **Fungsi `repeat_str`**:
  - Cek apakah `src` adalah `NULL`, kembalikan `NULL` jika iya.
  - Hitung panjang total dan alokasi memori dengan `malloc`.
  - Jika alokasi gagal, kembalikan `NULL`.
  - Salin string input sebanyak `count` kali menggunakan `strcpy`.
  - Tambahkan null terminator di akhir.
- **Main**:
  - Deklarasi buffer `str` dan variabel `count`.
  - Ambil input pengguna, panggil `repeat_str`, cetak hasil, dan bebaskan memori.

## Penemuan Masalah

1. **Input NULL**:
   - **Masalah**: Jika `src` adalah `NULL`, `strlen(src)` akan menyebabkan error.
   - **Dampak**: Program crash.
   - **Solusi**: Tambah pengecekan `if (src == NULL)` dan kembalikan `NULL`.

2. **Kegagalan Alokasi Memori**:
   - **Masalah**: Jika `malloc` gagal (misalnya, `count` terlalu besar), `result` menjadi `NULL`.
   - **Dampak**: Akses memori tidak valid jika tidak diperiksa.
   - **Solusi**: Cek `if (result == NULL)` dan kembalikan `NULL`.

3. **Buffer Overflow di Input**:
   - **Masalah**: `scanf("%s", str)` tidak membatasi panjang input, bisa melebihi 99 karakter.
   - **Dampak**: Buffer overflow, perilaku tak terduga.
   - **Solusi Potensial**: Gunakan `scanf("%99s", str)` untuk membatasi panjang (belum diimplementasikan).

4. **Null Terminator Hilang**:
   - **Masalah**: Awalnya tidak ada jaminan null terminator ditambahkan dengan benar.
   - **Dampak**: String hasil bisa berisi data acak setelah akhir.
   - **Solusi**: Tambah `result[total_len - 1] = '\0'` secara eksplisit.

5. **Memori Tidak Dibebaskan**:
   - **Masalah**: Jika `result` tidak dibebaskan, terjadi memory leak.
   - **Dampak**: Pemborosan memori pada eksekusi berulang.
   - **Solusi**: Tambah `free(result)` di `main` (sudah ada).

## Hasil Output
Input: String "abc", Count: 3, Hasil: "abcabcabc"
Input: String "hi", Count: 2, Hasil: "hihi"
Input: String "x", Count: 5, Hasil: "xxxxx"