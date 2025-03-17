## Deskripsi Masalah
Program ini bertujuan untuk mendekripsi sebuah string yang telah dienkripsi menggunakan Caesar Cipher. Caesar Cipher adalah metode enkripsi sederhana yang menggeser setiap huruf dalam teks dengan jumlah posisi tertentu dalam alfabet. Dalam kasus ini, kita diminta untuk mendekripsi string dengan menggeser huruf kembali berdasarkan nilai shift yang diberikan. Contoh:
- Input: `khoor`, Shift: `3` → Output: `hello` (karena `k` digeser mundur 3 menjadi `h`, `h` menjadi `e`, dst.).
- Input: `XYZ`, Shift: `2` → Output: `VWX` (karena `X` digeser mundur 2 menjadi `V`, `Y` menjadi `W`, `Z` menjadi `X`).
- Input: `abc`, Shift: `-1` → Output: `bcd` (karena shift negatif berarti geser maju, `a` menjadi `b`, dst.).

**Batasan:**
- Input: String dengan panjang maksimum 100.000 karakter, hanya huruf alfabet (A-Z, a-z) yang akan diubah, karakter lain tetap.
- Shift: Bilangan bulat (positif atau negatif).
- Output: String yang telah didekripsi.

## Logika dan Intuisi Penyelesaian

### 1. Memahami Masalah
Langkah awal adalah memahami mekanisme Caesar Cipher:
- Enkripsi menggeser huruf maju dalam alfabet (misalnya, shift 3: `a` jadi `d`).
- Dekripsi menggeser huruf mundur (misalnya, shift 3: `d` jadi `a`).
- Alfabet memiliki 26 huruf, jadi semua pergeseran bersifat modular (mod 26).
- Huruf besar dan kecil dipertahankan; karakter non-alfabet tidak diubah.

Tujuan: Ubah string input dengan menggeser setiap huruf alfabet mundur sebanyak `shift`.

### 2. Pendekatan Awal: Menangani Shift
Shift bisa positif (geser mundur) atau negatif (geser maju):
- Ambil `shift % 26` untuk memastikan pergeseran dalam rentang 0-25.
- Jika `shift` negatif, ubah ke pergeseran positif ekuivalen dengan `shift + 26`.
- Contoh: Shift `-1` → `-1 % 26 = -1`, lalu `-1 + 26 = 25` (geser mundur 25 = geser maju 1).

### 3. Proses Dekripsi per Karakter
Untuk setiap karakter dalam string:
- Cek apakah huruf kecil (`a-z`) atau besar (`A-Z`).
- Hitung posisi relatif terhadap huruf awal (`a` atau `A`), kurangi shift, lalu ambil modulo 26.
- Contoh untuk `k` (shift 3):
  - `k` = 10 (0-based dari `a`).
  - Mundur 3: `10 - 3 = 7`.
  - Modulo 26: `7 % 26 = 7`.
  - Hasil: `a + 7 = h`.

### 4. Menangani Input dan Output
- Input: String dari `fgets` (termasuk newline), lalu hapus newline dengan `strcspn`.
- Shift: Dibaca dengan `scanf`.
- Proses: Panggil fungsi `decrypt` untuk ubah string.
- Output: Cetak string hasil dengan `printf`.

### 5. Membangun Logika Utama
- **Fungsi `decrypt`**:
  - Normalisasi `shift` ke 0-25.
  - Iterasi string, ubah hanya huruf alfabet.
  - Gunakan `(c - base - shift + 26) % 26` untuk hitung posisi baru (`base` = `a` atau `A`).
- **Main**:
  - Ambil input string dan shift.
  - Panggil `decrypt`, lalu cetak hasil.

## Penemuan Masalah

1. **Shift Negatif Salah Perhitungan**:
   - **Masalah**: Jika shift negatif besar (misalnya `-27`), `% 26` tetap negatif.
   - **Dampak**: Pergeseran salah arah.
   - **Solusi**: Tambah `if(shift < 0) shift += 26` setelah modulo.

2. **Newline pada Input**:
   - **Masalah**: `fgets` menyertakan `\n`, menyebabkan output aneh.
   - **Dampak**: String output mengandung karakter tak diinginkan.
   - **Solusi**: Hapus `\n` dengan `str[strcspn(str, "\n")] = '\0'`.

3. **Karakter Non-Alfabet Berubah**:
   - **Masalah**: Awalnya semua karakter digeser, termasuk spasi atau simbol.
   - **Dampak**: Output salah untuk input seperti `hello world!`.
   - **Solusi**: Tambah kondisi `if` untuk proses hanya huruf alfabet.

4. **Buffer Overflow**:
   - **Masalah**: Input lebih dari `MAX_LEN` bisa menyebabkan overflow.
   - **Dampak**: Program crash atau perilaku tak terduga.
   - **Solusi**: Batasi input dengan `MAX_LEN` di `fgets`.

## Hasil Output
Input: "khoor", Shift: 3, Hasil: "hello"
Input: "XYZ", Shift: 2, Hasil: "VWX"
Input: "abc", Shift: -1, Hasil: "bcd"