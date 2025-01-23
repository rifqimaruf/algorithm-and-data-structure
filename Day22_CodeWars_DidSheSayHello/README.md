
# Solusi Soal "Did She Say Hello?"

Pada soal ini, kita diminta untuk membuat sebuah fungsi yang dapat memverifikasi apakah sebuah kalimat berisi ucapan "hello" dalam berbagai bahasa. Kalimat yang diberikan bisa jadi mengandung tanda baca, huruf besar/kecil, atau bahkan beberapa kata tambahan, seperti "hallo, bagaimana kabarmu?" atau "hombre! Hola!".

## Penjelasan Solusi

### 1. Menangani Input yang Berbeda-beda
Untuk menangani variasi input yang bisa saja mengandung tanda baca atau huruf kapital, kita perlu memastikan bahwa input tersebut dapat diproses dengan benar sebelum melakukan perbandingan. Misalnya, kalimat `"hombre! Hola!"` harus dapat cocok dengan kata `"hola"`, meskipun ada tanda baca di dalamnya.

### 2. Menggunakan `Contains()` untuk Memeriksa Substring
Solusi terbaru menggunakan metode `Contains()` untuk memeriksa apakah ucapan "hello" dalam berbagai bahasa muncul sebagai substring di dalam kalimat. Ini mengatasi masalah ketika ucapan tersebut bagian dari kalimat yang lebih panjang atau memiliki tanda baca.

### 3. Menggunakan `ToLower()` untuk Menjamin Perbandingan Tidak Sensitif Huruf Kapital
Agar perbandingan tidak terpengaruh oleh huruf kapital, kita mengubah seluruh kalimat menjadi huruf kecil menggunakan `ToLower()` sebelum melakukan pencocokan dengan daftar ucapan yang valid.

### Penjelasan Kode
1. **Perbandingan dengan Daftar Kata**: Kita memiliki daftar ucapan "hello" dalam berbagai bahasa yang kita anggap valid. Fungsi akan mengembalikan `true` jika input cocok dengan salah satu kata dalam daftar, baik sebagai substring atau bagian dari kalimat yang lebih panjang.
2. **Penggunaan `ToLower()`**: Menggunakan `ToLower()` agar perbandingan tidak terpengaruh oleh kapitalisasi huruf (besar/kecil).
3. **Menggunakan `Contains()`**: Kita memeriksa apakah ucapan yang valid terdapat dalam kalimat menggunakan `Contains()`. Ini memungkinkan kita untuk mendeteksi ucapan tersebut meskipun ada tanda baca atau kata tambahan lainnya.

### Perbandingan Solusi

| **Aspek**                          | **Solusi Sebelumnya**                                             | **Solusi Terbaru**                                               |
|------------------------------------|------------------------------------------------------------------|------------------------------------------------------------------|
| **Metode yang Digunakan**          | Regex atau pemisahan kata, dan kemudian perbandingan langsung     | Menggunakan `Contains()` untuk mencari substring yang cocok      |
| **Penggunaan `ToLower()`**         | Mengubah seluruh input menjadi huruf kecil                       | Mengubah seluruh input menjadi huruf kecil                       |
| **Kemampuan Menangani Punctuation**| Menggunakan regex untuk menangani tanda baca                     | Secara otomatis menangani tanda baca dengan `Contains()`         |
| **Kecepatan**                       | Sedikit lebih rumit karena menggunakan regex dan pemisahan kata | Lebih cepat karena menggunakan `Contains()` langsung            |
| **Kompleksitas Kode**               | Lebih kompleks dengan regex dan pemisahan kata                   | Lebih sederhana dan efisien dengan `Contains()`                  |

## Note
Solusi yang sebelumnya gagal karena memeriksa kecocokan yang sangat ketat dan tidak menangani variasi tanda baca atau kata tambahan. Dengan menggunakan Contains(), solusi terbaru lebih fleksibel dan dapat menangani kasus di mana kata "hello" berada di dalam kalimat yang lebih panjang atau mengandung tanda baca, sehingga dapat lolos pada semua test case.