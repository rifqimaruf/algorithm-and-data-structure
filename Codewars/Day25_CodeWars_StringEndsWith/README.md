## Deskripsi

Program sederhana untuk mengecek apakah sebuah string diakhiri dengan string tertentu menggunakan bahasa cpp dengan memanfaatkan fungsi **compare** pada library string.

## Fungsi Compare

Fungsi `compare` dalam C++ adalah fungsi yang digunakan untuk membandingkan dua string atau substring. Fungsi ini sangat berguna ketika kita ingin memeriksa apakah dua string sama atau untuk menentukan urutan leksikografis (berdasarkan urutan alfabet) antara dua string.

Berikut adalah penjelasan tentang parameter-parameter yang bisa digunakan dalam fungsi `compare`:

### 1. **Bentuk Dasar Fungsi `compare`**
Fungsi `compare` memiliki beberapa bentuk (overloads), tetapi yang paling umum digunakan adalah:

```cpp
int compare(size_t pos, size_t len, const string& str) const;
```

### 2. **Parameter-Parameter Fungsi `compare`**

#### a. **`pos` (Position)**
- **Tipe**: `size_t`
- **Deskripsi**: Parameter ini menentukan posisi awal di dalam string utama (`this`) di mana perbandingan akan dimulai.
- **Contoh**: Jika `pos = 5`, maka perbandingan akan dimulai dari indeks ke-5 string utama.

#### b. **`len` (Length)**
- **Tipe**: `size_t`
- **Deskripsi**: Parameter ini menentukan panjang substring dari string utama yang akan dibandingkan.
- **Contoh**: Jika `len = 3`, maka hanya 3 karakter dari string utama (mulai dari `pos`) yang akan dibandingkan.

#### c. **`str` (String to Compare)**
- **Tipe**: `const string&`
- **Deskripsi**: Parameter ini adalah string yang akan dibandingkan dengan substring dari string utama.
- **Contoh**: Jika `str = "abc"`, maka string "abc" akan dibandingkan dengan substring dari string utama.

### 3. **Return Value (Nilai Kembalian)**
Fungsi `compare` mengembalikan nilai bertipe `int` yang memiliki arti sebagai berikut:
- **`0`**: Jika substring dari string utama sama dengan string `str`.
- **`< 0`**: Jika substring dari string utama secara leksikografis lebih kecil dari string `str`.
- **`> 0`**: Jika substring dari string utama secara leksikografis lebih besar dari string `str`.

### 4. **Contoh Penggunaan**

Mari kita lihat contoh penggunaan fungsi `compare` dalam konteks program yang sudah diberikan:

```cpp
bool solution(string const &str, string const &ending)
{
    if (str.size() >= ending.size())
    {
        return str.compare(str.size() - ending.size(), ending.size(), ending) == 0;
    }
    else{
        return false;
    }
}
```

#### Penjelasan:
- **`str.size() - ending.size()`**: Ini adalah parameter `pos`. Kita mulai membandingkan dari posisi di mana panjang string utama (`str`) dikurangi panjang string `ending`. Ini memastikan kita membandingkan bagian akhir dari `str`.
- **`ending.size()`**: Ini adalah parameter `len`. Kita membandingkan sebanyak `ending.size()` karakter dari string utama.
- **`ending`**: Ini adalah parameter `str`. Kita membandingkan substring dari string utama dengan string `ending`.

#### Contoh:
Misalkan:
- `str = "hello"`
- `ending = "llo"`

Maka:
- `str.size() - ending.size()` = `5 - 3` = `2` (kita mulai membandingkan dari indeks ke-2).
- `ending.size()` = `3` (kita membandingkan 3 karakter).
- `ending` = `"llo"`.

Jadi, `str.compare(2, 3, "llo")` akan membandingkan substring `"llo"` dari `str` dengan `"llo"`. Karena keduanya sama, fungsi `compare` akan mengembalikan `0`, dan fungsi `solution` akan mengembalikan `true`.

### 5. **Overload Lain dari Fungsi `compare`**

Selain bentuk dasar di atas, fungsi `compare` juga memiliki beberapa overload lainnya, seperti:
- **Membandingkan dengan C-string (array karakter)**:
  ```cpp
  int compare(size_t pos, size_t len, const char* s) const;
  ```
- **Membandingkan dengan substring dari C-string**:
  ```cpp
  int compare(size_t pos, size_t len, const char* s, size_t n) const;
  ```
- **Membandingkan seluruh string**:
  ```cpp
  int compare(const string& str) const;
  ```

