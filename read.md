Karena saya tidak dapat langsung membuat file Word, berikut adalah teks yang diformat agar dapat Anda salin ke Microsoft Word. Anda dapat menyalin teks ini ke dalam dokumen Word dan menyesuaikan formatnya sesuai kebutuhan.

---

**Penyelesaian Soal Prediksi Kelas dengan K-Nearest Neighbor (KNN)**

**Data yang Diketahui**  
Data ke-11 memiliki fitur:  
- SepalLength = 5.7  
- SepalWidth = 3.0  
- PetalLength = 4.2  
- PetalWidth = 1.2  
- Class = ?  

Kita akan menghitung jarak Euclidean dari data ke-11 ke semua data lainnya (data 1-10), lalu menentukan kelas berdasarkan mayoritas kelas dari K tetangga terdekat.

**Langkah 1: Rumus Jarak Euclidean**  
Jarak Euclidean antara dua titik \( (x_1, y_1, z_1, w_1) \) dan \( (x_2, y_2, z_2, w_2) \) adalah:  
$$
\text{Jarak} = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2 + (z_2 - z_1)^2 + (w_2 - w_1)^2}
$$  
Di sini, \( x \), \( y \), \( z \), dan \( w \) masing-masing adalah SepalLength, SepalWidth, PetalLength, dan PetalWidth.

**Langkah 2: Hitung Jarak Euclidean**  
1. **Ke data 1 (4.6, 3.2, 1.4, 0.2, Iris-setosa):**  
$$
\sqrt{(5.7 - 4.6)^2 + (3.0 - 3.2)^2 + (4.2 - 1.4)^2 + (1.2 - 0.2)^2} = \sqrt{(1.1)^2 + (-0.2)^2 + (2.8)^2 + (1.0)^2} = \sqrt{1.21 + 0.04 + 7.84 + 1.0} = \sqrt{10.09} \approx 3.18
$$

2. **Ke data 2 (5.3, 3.7, 1.5, 0.1, Iris-setosa):**  
$$
\sqrt{(5.7 - 5.3)^2 + (3.0 - 3.7)^2 + (4.2 - 1.5)^2 + (1.2 - 0.1)^2} = \sqrt{(0.4)^2 + (-0.7)^2 + (2.7)^2 + (1.1)^2} = \sqrt{0.16 + 0.49 + 7.29 + 1.21} = \sqrt{9.15} \approx 3.02
$$
3. **Ke data 3 (5.0, 3.3, 1.4, 0.2, Iris-setosa):**  
$$
\sqrt{(5.7 - 5.0)^2 + (3.0 - 3.3)^2 + (4.2 - 1.4)^2 + (1.2 - 0.2)^2} = \sqrt{(0.7)^2 + (-0.3)^2 + (2.8)^2 + (1.0)^2} = \sqrt{0.49 + 0.09 + 7.84 + 1.0} = \sqrt{9.42} \approx 3.07
$$

4. **Ke data 4 (7.0, 3.2, 4.7, 1.4, Iris-versicolor):**  
$$
\sqrt{(5.7 - 7.0)^2 + (3.0 - 3.2)^2 + (4.2 - 4.7)^2 + (1.2 - 1.4)^2} = \sqrt{(-1.3)^2 + (-0.2)^2 + (-0.5)^2 + (-0.2)^2} = \sqrt{1.69 + 0.04 + 0.25 + 0.04} = \sqrt{2.02} \approx 1.42
$$

5. **Ke data 5 (6.4, 3.2, 4.5, 1.5, Iris-versicolor):**  
$$
\sqrt{(5.7 - 6.4)^2 + (3.0 - 3.2)^2 + (4.2 - 4.5)^2 + (1.2 - 1.5)^2} = \sqrt{(-0.7)^2 + (-0.2)^2 + (-0.3)^2 + (-0.3)^2} = \sqrt{0.49 + 0.04 + 0.09 + 0.09} = \sqrt{0.71} \approx 0.84
$$

6. **Ke data 6 (6.9, 3.1, 4.9, 1.5, Iris-versicolor):**  
$$
\sqrt{(5.7 - 6.9)^2 + (3.0 - 3.1)^2 + (4.2 - 4.9)^2 + (1.2 - 1.5)^2} = \sqrt{(-1.2)^2 + (-0.1)^2 + (-0.7)^2 + (-0.3)^2} = \sqrt{1.44 + 0.01 + 0.49 + 0.09} = \sqrt{2.03} \approx 1.42
$$

7. **Ke data 7 (6.5, 3.0, 5.8, 2.2, Iris-virginica):**  
$$
\sqrt{(5.7 - 6.5)^2 + (3.0 - 3.0)^2 + (4.2 - 5.8)^2 + (1.2 - 2.2)^2} = \sqrt{(-0.8)^2 + (0.0)^2 + (-1.6)^2 + (-1.0)^2} = \sqrt{0.64 + 0.0 + 2.56 + 1.0} = \sqrt{4.2} \approx 2.05
$$

8. **Ke data 8 (7.6, 3.0, 6.6, 2.1, Iris-virginica):**  
$$
\sqrt{(5.7 - 7.6)^2 + (3.0 - 3.0)^2 + (4.2 - 6.6)^2 + (1.2 - 2.1)^2} = \sqrt{(-1.9)^2 + (0.0)^2 + (-2.4)^2 + (-0.9)^2} = \sqrt{3.61 + 0.0 + 5.76 + 0.81} = \sqrt{10.18} \approx 3.19
$$

9. **Ke data 9 (4.9, 2.5, 4.5, 1.7, Iris-virginica):**  
$$
\sqrt{(5.7 - 4.9)^2 + (3.0 - 2.5)^2 + (4.2 - 4.5)^2 + (1.2 - 1.7)^2} = \sqrt{(0.8)^2 + (0.5)^2 + (-0.3)^2 + (-0.5)^2} = \sqrt{0.64 + 0.25 + 0.09 + 0.25} = \sqrt{1.23} \approx 1.11
$$

10. **Ke data 10 (7.3, 2.9, 6.3, 1.8, Iris-virginica):**  
$$
\sqrt{(5.7 - 7.3)^2 + (3.0 - 2.9)^2 + (4.2 - 6.3)^2 + (1.2 - 1.8)^2} = \sqrt{(-1.6)^2 + (0.1)^2 + (-2.1)^2 + (-0.6)^2} = \sqrt{2.56 + 0.01 + 4.41 + 0.36} = \sqrt{7.34} \approx 2.71
$$

**Langkah 3: Urutkan Jarak dari Terkecil ke Terbesar**  
- Data 5: 0.84 (Iris-versicolor)  
- Data 9: 1.11 (Iris-virginica)  
- Data 4: 1.42 (Iris-versicolor)  
- Data 6: 1.42 (Iris-versicolor)  
- Data 7: 2.05 (Iris-virginica)  
- Data 10: 2.71 (Iris-virginica)  
- Data 2: 3.02 (Iris-setosa)  
- Data 3: 3.07 (Iris-setosa)  
- Data 1: 3.18 (Iris-setosa)  
- Data 8: 3.19 (Iris-virginica)

**Langkah 4: Prediksi Kelas dengan K=3 dan K=5**  
#### K=3 (3 tetangga terdekat):  
- Data 5: Iris-versicolor  
- Data 9: Iris-virginica  
- Data 4: Iris-versicolor  

Mayoritas: 2 Iris-versicolor, 1 Iris-virginica.  
**Prediksi kelas (K=3): Iris-versicolor.**

#### K=5 (5 tetangga terdekat):  
- Data 5: Iris-versicolor  
- Data 9: Iris-virginica  
- Data 4: Iris-versicolor  
- Data 6: Iris-versicolor  
- Data 7: Iris-virginica  

Mayoritas: 3 Iris-versicolor, 2 Iris-virginica.  
**Prediksi kelas (K=5): Iris-versicolor.**

**Jawaban Akhir**  
Prediksi kelas untuk data ke-11:  
- Dengan K=3: **Iris-versicolor**  
- Dengan K=5: **Iris-versicolor**

---

**Instruksi:**  
1. Salin teks di atas ke dalam dokumen Microsoft Word.  
2. Sesuaikan font, ukuran teks, dan pemformatan (misalnya, judul dengan tebal dan spasi) sesuai kebutuhan.  
3. Tambahkan nomor halaman atau elemen lain jika diperlukan.