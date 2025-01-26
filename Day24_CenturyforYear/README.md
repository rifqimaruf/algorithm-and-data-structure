**README.md (Bahasa Indonesia)**

# Menentukan Abad dari Tahun Tertentu

## Masalah
Abad pertama dimulai dari tahun 1 hingga 100, abad kedua dari tahun 101 hingga 200, dan seterusnya. Tugas Anda adalah menentukan abad untuk suatu tahun tertentu berdasarkan aturan ini.

### Contoh:
- Tahun 1705 → Abad 18
- Tahun 1900 → Abad 19
- Tahun 2000 → Abad 20
- Tahun 2742 → Abad 28

---

## Cara Menyelesaikan Masalah

### Pendekatan Solusi
Untuk menentukan abad dari suatu tahun, kita dapat menggunakan operasi matematika sederhana:
1. **Tambahkan 99 ke tahun yang diberikan**.
2. **Bagi hasilnya dengan 100**.
3. **Bulatkan ke bawah** untuk mendapatkan nilai abad.

**Rumus**:  
```
Abad = (Tahun + 99) // 100
```

#### Mengapa Menambahkan 99?
- Jika tahun adalah **kelipatan 100** (misalnya 1900), tahun tersebut berada di akhir abad.  
  Contoh:  
  `1900 + 99 = 1999` → `1999 // 100 = 19` (Abad 19).  

- Jika tahun **bukan kelipatan 100** (misalnya 1705), tambahan 99 memastikan tahun "didorong" ke abad berikutnya sebelum dibagi.  
  Contoh:  
  `1705 + 99 = 1804` → `1804 // 100 = 18` (Abad 18).

---

## Penjelasan Kode (C++)

```cpp
int centuryFromYear(int year) {
    return (year + 99) / 100;
}
```

### Langkah-Langkah Kode:
1. **Tambahkan 99 ke tahun**:  
   Ini mengatasi kasus di mana tahun adalah kelipatan 100 (misalnya 1900 → 1999) atau bukan (1705 → 1804).

2. **Bagi dengan 100**:  
   Pembagian integer (tanpa desimal) secara otomatis membulatkan ke bawah.  
   Contoh:  
   - `1999 / 100 = 19`  
   - `1804 / 100 = 18`

---

## Contoh Penggunaan

### Contoh 1: Tahun 1900
```
1900 + 99 = 1999  
1999 // 100 = 19  
Abad = 19
```

### Contoh 2: Tahun 1705
```
1705 + 99 = 1804  
1804 // 100 = 18  
Abad = 18
```

### Contoh 3: Tahun 2000
```
2000 + 99 = 2099  
2099 // 100 = 20  
Abad = 20
```

---

## Kompleksitas Waktu
- **O(1)**: Solusi ini hanya melibatkan operasi matematika sederhana, sehingga waktu eksekusi konstan.