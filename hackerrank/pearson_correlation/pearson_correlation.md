# Penjelasan

## Apa itu Korelasi Pearson
Korelasi Pearson (r) mengukur kekuatan dan arah hubungan *linear* antara dua variabel.

Untuk mengukur hubungan antara dua variabel **X** dan **Y**, kita melakukan transformasi data melalui tiga tahapan logika matematis:

**1. Sentralisasi (Centering)**  
Langkah pertama adalah menggeser seluruh titik data sehingga titik pusatnya berada di:

(0, 0)

Kita melakukannya dengan menghitung deviasi setiap titik dari rata-ratanya:

$$
(x_i - x̄), (y_i - ȳ)
$$

Jika nilainya positif, berarti data berada di atas rata-rata.  
Jika negatif, data berada di bawah rata-rata.


**2. Akumulasi Searah (Cross-Product)**  
Kita mengalikan kedua deviasi tersebut:

$$
(x_i - x̄)(y_i - ȳ)
$$

Secara matematis, perkalian ini berfungsi sebagai **detektor keselarasan**:

- **Hasil positif**: terjadi jika kedua variabel setuju  
  (sama-sama di atas rata-rata (+ × +) atau sama-sama di bawah rata-rata (− × −)).

- **Hasil negatif**: terjadi jika kedua variabel bertolak belakang  
  (satu di atas dan satu di bawah rata-rata (+ × −)).

Jika kita menjumlahkan seluruh hasil perkalian ini:
$$
Σ (x_i - x̄)(y_i - ȳ)
$$
kita memperoleh **covariance**.  
Nilai yang besar dan positif menunjukkan kecenderungan kuat untuk bergerak searah.


**3. Normalisasi (Scaling)**  
Masalahnya, nilai covariance sangat bergantung pada satuan  
(misalnya, hasil dalam meter akan berbeda dengan centimeter).

Untuk menghilangkan pengaruh satuan dan membatasi nilai ke dalam rentang:

[-1, 1]

kita membaginya dengan total variasi gabungan dari kedua variabel.

Secara geometris, ini mirip dengan menghitung cosinus sudut antara dua vektor dalam ruang berdimensi-n.  
Jika sudutnya:

0°

maka kedua vektor bergerak identik, sehingga:

r = 1

```
Nilai r berada di rentang -1 sampai 1:
- r mendekati 1: hubungan linear positif kuat
- r mendekati -1: hubungan linear negatif kuat
- r mendekati 0: tidak ada hubungan linear
```



## Rumus
$$
\displaystyle
r = \frac{\sum (x_i - \bar{x})(y_i - \bar{y})}
{\sqrt{\sum (x_i - \bar{x})^2 \; \sum (y_i - \bar{y})^2}}
$$



## Langkah
1. Hitung rata-rata Fisika dan Sejarah.
2. Hitung pembilang: jumlah perkalian deviasi tiap pasangan.
3. Hitung penyebut: akar dari hasil kali jumlah kuadrat deviasi.
4. Bagi pembilang dengan penyebut.
5. Cetak 3 angka desimal.

## Kompleksitas
Waktu O(n), memori tambahan O(1).

## Output
Program langsung mencetak nilai koefisien dengan format tiga desimal.

## Referensi
- [Britannica: Pearson's correlation coefficient](https://www.britannica.com/topic/Pearsons-correlation-coefficient)
