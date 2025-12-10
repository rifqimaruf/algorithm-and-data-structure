Berikut adalah format README untuk masalah "Segitiga Pascal" sesuai dengan struktur yang Anda berikan:

# Segitiga Pascal

## Soal

Diberikan sebuah integer `numRows`

Di segitiga Pascal, setiap angka adalah jumlah dari dua angka yang berada tepat di atasnya.

### Contoh Soal

**Contoh 1**  
**Input**:  
`numRows = 5`  
**Output**:  
`[[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]`  
**Penjelasan**:  
Segitiga Pascal untuk 5 baris adalah sebagai berikut:  
     1
    1 1
   1 2 1
  1 3 3 1
 1 4 6 4 1



## Batasan
- 1 <= numRows <= 30

## Metode Penyelesaian: Iterasi

Untuk menyelesaikan soal ini, kita akan menggunakan pendekatan **iteratif** untuk membangun segitiga Pascal baris demi baris.

### Cara Kerja

1. **Inisialisasi**  
   Mulai dengan baris pertama yang selalu berisi angka `1`.
   
2. **Bangun Baris Selanjutnya**  
   Untuk setiap baris berikutnya:
   - Setiap baris dimulai dan diakhiri dengan `1`.
   - Setiap elemen di antara dua `1` dihitung sebagai jumlah dari dua elemen di baris sebelumnya (baris sebelumnya dengna index yang sama dan baris sebelumnya dengan index - 1).

## Hint Idea
   - row[j] start dengan angka 1 lalu dicoba untuk overite value dari vector row, tidak dimulai dari angka 0 karena indeks pertama pasti memiliki value 1.
   - two dimentional vector is basically a vector of vector.
   - vector<int>: this is one dimentional vector.
   - vector<vector<int>>: this is two dimetional vector.
   - vector is like resizeable array, its cpp library called STL (standart template library) that help us to address dynamic size of management.
   