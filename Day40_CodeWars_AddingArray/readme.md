## Deskripsi Masalah
Dalam masalah ini, kita diminta untuk membuat fungsi yang mengambil array 2D huruf dan menggabungkannya menjadi kata-kata dalam sebuah kalimat. Setiap kolom dalam array membentuk satu kata, dan kata-kata tersebut dipisahkan oleh spasi.

Contoh:
- Input: 
```
[
['J', 'L', 'L', 'M'],
['u', 'i', 'i', 'a'],
['s', 'v', 'f', 'n'],
['t', 'e', 'e', '\0']
]
```

Output: `"Just Live Life Man"`
- Kolom 0: `J-u-s-t` → "Just"
- Kolom 1: `L-i-v-e` → "Live"
- Kolom 2: `L-i-f-e` → "Life"
- Kolom 3: `M-a-n-\0` → "Man"

**Batasan:**
- Input: Array 2D karakter (`const char *`).
- Output: String (`char *`) yang dialokasikan oleh pemanggil.
- Karakter null (`\0`) menandakan akhir kata atau bagian yang tidak terisi.

## Logika dan Intuisi Penyelesaian

### 1. Memahami Masalah
Langkah pertama adalah memahami apa yang diminta:
- Kita punya array 2D, misalnya 4x4 untuk "Just Live Life Man".
- Setiap kolom membentuk satu kata: kolom 0 = "Just", kolom 1 = "Live", dll.
- Karakter null (`\0`) menunjukkan akhir kata atau bagian kosong.
- Hasil akhir adalah kalimat dengan spasi antar kata.

Ini seperti "membaca" array secara vertikal per kolom, lalu "menyusun" kata-kata menjadi kalimat.

### 2. Pendekatan Awal: Membaca per Kolom
Ide awal adalah:
- Iterasi per kolom untuk membentuk kata.
- Untuk setiap kolom, ambil karakter dari setiap baris.
- Tambahkan spasi antar kata, kecuali setelah kata terakhir.
- Gunakan array 1D (`string`) untuk menyimpan hasil.

Contoh manual untuk:
```
['J', 'L', 'L', 'M']
['u', 'i', 'i', 'a']
['s', 'v', 'f', 'n']
['t', 'e', 'e', '\0']
```

- Kolom 0: `J-u-s-t` → "Just "
- Kolom 1: `L-i-v-e` → "Live "
- Kolom 2: `L-i-f-e` → "Life "
- Kolom 3: `M-a-n-\0` → "Man"

### 3. Menyederhanakan dengan Pointer Tunggal
Karena parameter fungsi adalah `const char *matrix`:
- Array 2D diakses sebagai array 1D.
- Indeks dihitung dengan `j * cols + i` (baris * jumlah kolom + kolom).
- Contoh: `matrix[0 * 4 + 0] = 'J'`, `matrix[1 * 4 + 0] = 'u'`.

### 4. Menangani Proses Penggabungan
- **Iterasi Kolom**: Loop luar untuk setiap kolom (`i`).
- **Iterasi Baris**: Loop dalam untuk setiap baris (`j`) dalam kolom.
- **Filter Null**: Hanya tambahkan karakter jika bukan `\0`.
- **Spasi**: Tambahkan spasi setelah kata selesai, kecuali untuk kolom terakhir.
- **Akhir String**: Tambahkan `\0` setelah semua karakter diproses.

Contoh untuk "Just":
- `matrix[0 * 4 + 0] = 'J'` → tambah ke `string`.
- `matrix[1 * 4 + 0] = 'u'` → tambah.
- `matrix[2 * 4 + 0] = 's'` → tambah.
- `matrix[3 * 4 + 0] = 't'` → tambah.
- Tambah spasi karena bukan kolom terakhir.

### 5. Membangun Logika Utama
- **Inisialisasi**:
  - `pos = 0` untuk melacak posisi dalam `string`.
- **Proses Utama**:
  - Loop kolom (`i` dari 0 ke `cols - 1`).
  - Loop baris (`j` dari 0 ke `rows - 1`).
  - Tambah karakter jika bukan `\0`.
  - Tambah spasi jika `i < cols - 1`.
- **Penutup**:
  - Tambah `\0` di akhir `string`.

## Penemuan Masalah

1. **Output Salah ("J L L M")**:
   - **Masalah**: Loop salah (indeks `i * cols + j` alih-alih `j * cols + i`) dan spasi di dalam loop dalam.
   - **Dampak**: Hanya kolom pertama diproses, spasi antar huruf.
   - **Solusi**: Perbaiki indeks ke `j * cols + i`, pindahkan spasi ke luar loop dalam.

2. **Return Prematur**:
   - **Masalah**: `return` di dalam loop menyebabkan hanya satu kolom diproses.
   - **Dampak**: Output tidak lengkap.
   - **Solusi**: Pindahkan `return` ke luar loop.

3. **Spasi Berlebih**:
   - **Masalah**: Spasi ditambahkan setelah setiap karakter.
   - **Dampak**: "J u s t" alih-alih "Just".
   - **Solusi**: Tambah spasi hanya setelah kata selesai dan jika bukan kata terakhir.

4. **Akses Memori Salah**:
   - **Masalah**: Indeks terbalik menyebabkan akses elemen yang salah.
   - **Dampak**: Kata-kata tidak terbentuk sesuai kolom.
   - **Solusi**: Gunakan `j * cols + i` untuk akses kolom yang benar.

5. **String Tidak Valid**:
   - **Masalah**: Tanpa `\0` di akhir, string bisa berisi data acak.
   - **Dampak**: Output tak terduga saat dicetak.
   - **Solusi**: Tambahkan `string[pos] = '\0'` di akhir.

## Hasil Output
```
Input:
[
['J', 'L', 'L', 'M'],
['u', 'i', 'i', 'a'],
['s', 'v', 'f', 'n'],
['t', 'e', 'e', '\0']
]
Hasil: "Just Live Life Man"
```