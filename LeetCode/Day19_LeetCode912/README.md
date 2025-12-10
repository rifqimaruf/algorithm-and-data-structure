# Sort an Array

## Soal

Dikasih sebuah array angka `nums`, tugas kita adalah mengurutkan array tersebut secara **ascending** (dari kecil ke besar) dan mengembalikannya.

Tapi ada syaratnya:
- Nggak boleh pakai fungsi bawaan buat sorting (kayak `sort()`).
- Harus selesai dalam waktu **O(n log n)** (cepat banget!).
- Pakai ruang tambahan seminim mungkin.

### Contoh Soal

**Contoh 1**  
**Input**:  
`nums = [5, 2, 3, 1]`  
**Output**:  
`[1, 2, 3, 5]`  
**Penjelasan**:  
Angka-angka diurutkan dari kecil ke besar.

**Contoh 2**  
**Input**:  
`nums = [5, 1, 1, 2, 0, 0]`  
**Output**:  
`[0, 0, 1, 1, 2, 5]`  
**Penjelasan**:  
Array bisa aja ada angka yang sama, hasilnya tetep diurutkan.

## Batasan
- 1 <= nums.length <= 5 * 10^4
- -5 * 10^4 <= nums[i] <= 5 * 10^4 

## Metode Penyelesaian: Merge Sort

Buat nyelesain soal ini, kita pakai **Merge Sort**, algoritma yang terkenal buat sorting cepat dan efisien. Konsepnya sederhana: **bagi, urutkan, gabung**.

### Cara Kerja Merge Sort

1. **Bagi**  
   Array dibagi dua terus sampai jadi subarray kecil-kecil (ukuran 1 elemen).
2. **Gabung**  
   Dua subarray yang udah diurutkan digabung jadi satu subarray besar, juga dalam urutan yang benar.

### Kenapa Merge Sort?

- Waktu komputasinya konsisten di **O(n log n)**.
- Ruang tambahan yang dipakai nggak boros, cuma buat sementara waktu pas proses merging.

## Penjelasan Kode

1. **Class `Solution`**  
   Semua fungsi diletakkan di dalam class ini. Biasanya format kayak gini dipakai di platform kayak LeetCode.

2. **Fungsi `merge`**  
   Digunakan buat gabungin dua bagian array yang udah diurutkan. Ini langkah penting dalam Merge Sort.

3. **Fungsi `mergeSort`**  
   Fungsi rekursif buat ngebagi array jadi lebih kecil dan menggabungkannya lagi dengan bantuan fungsi `merge`.

4. **Fungsi `sortArray`**  
   Ini fungsi publik yang dipanggil buat mulai sorting. Tinggal panggil fungsi ini, hasilnya array udah diurutkan.


## Contoh Input dan Output

**Input**:  
`nums = [5, 1, 1, 2, 0, 0]`

**Proses**:
1. Array dibagi-bagi sampai jadi subarray kecil:  
   `[5, 1, 1]` → `[5]` & `[1, 1]`  
   `[2, 0, 0]` → `[2]` & `[0, 0]`  
2. Gabung subarray kecil:  
   `[1, 1]` & `[5]` jadi `[1, 1, 5]`  
   `[0]` & `[0]` jadi `[0, 0]`  
3. Gabung dua bagian besar:  
   `[1, 1, 5]` & `[0, 0, 2]` jadi `[0, 0, 1, 1, 2, 5]`.

**Output**:  
`[0, 0, 1, 1, 2, 5]`