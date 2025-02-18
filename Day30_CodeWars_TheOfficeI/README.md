## Struktur Dasar

#include <iostream>, #include <string>, #include <map>, #include <vector>: Ini adalah baris-baris yang memasukkan (include) library atau pustaka yang diperlukan oleh program.

iostream: Untuk input dan output (misalnya, menampilkan teks ke layar dan membaca input dari keyboard).

string: Untuk bekerja dengan teks (string).

map: Untuk membuat struktur data yang menyimpan pasangan kunci-nilai (seperti kamus). Dalam kasus ini, kunci adalah nama karyawan (string), dan nilai adalah tingkat kebahagiaan (integer).

vector: Untuk membuat array dinamis (ukuran array bisa berubah).

using namespace std;: Ini untuk menghindari keharusan menulis std:: di depan setiap elemen dari library standar (seperti std::cout, std::string, dll.).

2. Fungsi outed(const map<string, int> &meet, const string &boss)

Tujuan: Fungsi ini menghitung rata-rata kebahagiaan dan menentukan apakah acara kantor berhasil atau tidak.

Input:

meet: Ini adalah map yang berisi data kebahagiaan karyawan. const berarti fungsi tidak bisa mengubah map ini. & (reference) berarti fungsi bekerja langsung dengan map aslinya (tanpa membuat salinan), sehingga lebih efisien.

boss: Ini adalah nama bos. const dan & memiliki arti yang sama seperti di atas.

## Cara Kerja:

double sum = 0.0;: Inisialisasi variabel sum untuk menyimpan total kebahagiaan. Tipe data double digunakan untuk menghindari pembulatan saat menghitung rata-rata.

for (const auto& pair : meet) { ... }: Ini adalah loop range-based for loop yang berjalan melalui setiap pasangan kunci-nilai (nama karyawan dan tingkat kebahagiaan) dalam map meet. auto secara otomatis menentukan tipe data dari elemen map (yaitu, pair<string, int>). const auto& digunakan untuk efisiensi dan mencegah perubahan data.

if (pair.first == boss) { ... } else { ... }: Ini adalah percabangan if-else. pair.first adalah nama karyawan saat ini (kunci), dan pair.second adalah tingkat kebahagiaannya (nilai).

if (pair.first == boss): Jika nama karyawan saat ini sama dengan nama bos, maka tingkat kebahagiaannya dikali dua dan ditambahkan ke sum. Ini karena kebahagiaan bos dianggap lebih penting.

else: Jika bukan bos, maka tingkat kebahagiaannya langsung ditambahkan ke sum.

double averageHappiness = sum / meet.size();: Menghitung rata-rata kebahagiaan dengan membagi total kebahagiaan (sum) dengan jumlah karyawan (meet.size()).

if (averageHappiness > 5.0) { ... } else { ... }: Ini adalah percabangan if-else yang menentukan hasil akhir berdasarkan rata-rata kebahagiaan.

if (averageHappiness > 5.0): Jika rata-rata kebahagiaan lebih besar dari 5, maka fungsi mengembalikan string "Nice Work Champ!".

else: Jika tidak, fungsi mengembalikan string "Get Out Now!".