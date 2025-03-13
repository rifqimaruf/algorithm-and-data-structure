Pointer adalah inti dari kekuatan bahasa C karena dapat mengontrol langsung atas memori. 

**Analogi**
Bayangkan pointer sebagai **GPS**. GPS tidak menyimpan mobilnya (data), tetapi memberi koordinat tempat mobil itu parkir (alamat memori). Dengan GPS, kita bisa:
- Pergi ke lokasi itu (mengakses data).
- Mengganti mobil di lokasi itu (mengubah data).
- Memberikan koordinat ke orang lain (mengoper pointer)

### Anatomi Pointer
- **Deklarasi**: `int *ptr;` artinya `ptr` adalah pointer yang bisa menunjuk ke alamat integer
- **Alamat**: `ptr = &variabel;` menyimpan alamat variabel ke pointer.
- **Dereference**: `*ptr` mengakses atau mengubah isi di alamat yang ditunjuk


**Contoh Dasar**
```
#include <stdio.h>

int main() {
    int angka = 42;
    int *ptr = &angka; // ptr menyimpan alamat angka

    printf("Nilai angka: %d\n", angka);
    printf("Alamat angka: %p\n", (void*)&angka);
    printf("Nilai yang ditunjuk ptr: %d\n", *ptr);

    *ptr = 99; // Ubah isi di alamat yang ditunjuk
    printf("Nilai angka setelah diubah: %d\n", angka);

    return 0;
}
```

1. `int *ptr = &angka;`: `ptr` jadi GPS menunjuk ke "parkiran" `angka`.
2. `*ptr`: kita ke lokasi itu dan lihat isinya (42)
3. `*ptr = 99`: kita ganti "mobil" di parkiran itu jadi 99. Karena `angka` ada di alamat yang sama, nilai `angka` ikut berubah

```
Nilai angka: 42
Alamat angka: 0x7fff5fbff4ac (contoh)
Nilai yang ditunjuk ptr: 42
Nilai angka setelah diubah: 99
```

### Pointer dan Array
Pointer dan array punya hubungan erat, karena nama array itu sendiri adalah pointer ke elemen pertamanya.
```
#include <stdio.h>

int main() {
    int arr[3] = {10, 20, 30};
    int *ptr = arr; // arr adalah alamat elemen pertama

    printf("Elemen 0: %d\n", *ptr);      // 10
    printf("Elemen 1: %d\n", *(ptr + 1)); // 20
    printf("Elemen 2: %d\n", *(ptr + 2)); // 30

    return 0;
}
```

- `arr` sama dengan `&arr[0]`, jadi `ptr = arr` menunjuk ke alamat elemen peratama. 
- `ptr + 1` geser alamat sebanyak ukuran `int` (biasanya 4 byte), jadi kita bisa akses elemen berikutnya dengan `*(ptr + 1)`


### Pointer ke Pointer
```
#include <stdio.h>

int main() {
    int arr[3] = {10, 20, 30};
    int *ptr = arr; // arr adalah alamat elemen pertama

    printf("Elemen 0: %d\n", *ptr);      // 10
    printf("Elemen 1: %d\n", *(ptr + 1)); // 20
    printf("Elemen 2: %d\n", *(ptr + 2)); // 30

    return 0;
}
```


### Fungsi `malloc` dan Memori Dinamis
