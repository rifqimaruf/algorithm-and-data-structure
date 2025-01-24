# Integral ke Polinomial

## Penjelasan Fungsi `to_string` dalam C++

Fungsi `to_string` adalah salah satu fungsi bawaan di C++ yang digunakan untuk mengonversi tipe data numerik (seperti `int`, `float`, `double`, dll.) menjadi tipe data `string`. Fungsi ini sangat berguna ketika kamu perlu menggabungkan angka dengan teks atau membangun string yang berisi nilai numerik.

### Cara Kerja `to_string`

1. **Input**: Fungsi `to_string` menerima sebuah nilai numerik sebagai argumen. Misalnya, sebuah bilangan bulat (`int`), bilangan desimal (`float` atau `double`), atau tipe numerik lainnya.
   
2. **Proses**: `to_string` akan mengambil nilai numerik tersebut dan mengubahnya menjadi representasi stringnya. Proses ini melibatkan konversi angka menjadi karakter yang membentuk string.

3. **Output**: Hasil dari fungsi ini adalah sebuah `string` yang berisi representasi teks dari angka yang diberikan.

### Contoh Penggunaan dalam Kode

Mari kita lihat bagaimana `to_string` digunakan dalam fungsi `integrate` pada kode kamu:

```cpp
string integrate (int coeff, int expp)
{
    string result = to_string(coeff/(expp+1)) + "x^" + to_string(expp+1);
    return result;
}
```

#### Langkah demi Langkah:

1. **Menghitung Koefisien Baru**:
   - `coeff/(expp+1)`: Ini menghitung koefisien hasil integrasi.
   - Contoh: Jika `coeff = 3` dan `expp = 2`, maka `3/(2+1) = 1`.

2. **Mengonversi Koefisien ke String**:
   - `to_string(coeff/(expp+1))`: Mengubah hasil perhitungan di atas menjadi string.
   - Contoh: `to_string(1)` menghasilkan `"1"`.

3. **Membuat Bagian Variabel dari Polinomial**:
   - `"x^"`: Ini adalah bagian tetap dari string yang menunjukkan variabel dan pangkatnya.

4. **Mengonversi Eksponen Baru ke String**:
   - `to_string(expp+1)`: Mengubah eksponen baru setelah integrasi menjadi string.
   - Contoh: `to_string(2+1)` menghasilkan `"3"`.

5. **Menggabungkan Semua Bagian**:
   - `to_string(coeff/(expp+1)) + "x^" + to_string(expp+1)`: Menggabungkan semua bagian menjadi satu string.
   - Contoh: `"1" + "x^" + "3"` menghasilkan `"1x^3"`.
