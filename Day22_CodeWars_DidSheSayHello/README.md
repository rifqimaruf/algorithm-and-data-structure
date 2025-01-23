# Solusi Soal "Did She Say Hello?"

Pada soal ini, kita diminta untuk membuat sebuah fungsi yang dapat memverifikasi apakah sebuah kalimat berisi ucapan "hello" dalam berbagai bahasa. Kalimat yang diberikan bisa jadi mengandung tanda baca, huruf besar/kecil, atau bahkan beberapa kata tambahan, seperti "hallo, bagaimana kabarmu?" atau "hombre! Hola!".

## Tujuan

Kita ingin memverifikasi apakah sebuah kalimat mengandung ucapan "hello" dalam bahasa tertentu, meskipun kalimat tersebut bisa memiliki variasi dalam hal tanda baca atau format huruf (besar/kecil).

## Penjelasan Solusi

### 1. Menangani Input yang Berbeda-beda
Untuk menangani variasi input yang bisa saja mengandung tanda baca atau huruf kapital, kita perlu membersihkan input terlebih dahulu sebelum melakukan perbandingan. Misalnya, kalimat `"hombre! Hola!"` harus dapat cocok dengan kata `"hola"`, meskipun ada tanda baca di dalamnya.

### 2. Menggunakan Regex untuk Menghilangkan Tanda Baca
Solusinya adalah dengan mengubah seluruh huruf menjadi kecil (`ToLower()`) 

### 3. Membandingkan dengan Daftar Kata yang Dikenali
Setelah input dibersihkan, kita bandingkan hasilnya dengan daftar ucapan "hello" dalam berbagai bahasa yang telah kita tentukan.


### Penjelasan Kode
1. **Perbandingan dengan Daftar Kata**: Kita memiliki daftar ucapan "hello" dalam berbagai bahasa yang kita anggap valid. Jika input cocok dengan salah satu kata dalam daftar, fungsi akan mengembalikan `true`.
2. **Penggunaan ToLower()**: Menggunakan `ToLower()` agar perbandingan tidak terpengaruh oleh kapitalisasi huruf (besar/kecil).

### Cara Penggunaan
1. Jalankan program ini di IDE atau terminal.
2. Masukkan kalimat yang ingin dicek (misalnya `"hombre! Hola!"` atau `"hallo, bagaimana kabarmu?"`).
3. Program akan mengembalikan `true` jika kalimat tersebut berisi ucapan "hello" dalam berbagai bahasa, dan `false` jika tidak.
