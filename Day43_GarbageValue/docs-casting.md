(void*) adalah casting (konversi tipe) 

### Kenapa menggunakan (void*)?
Di C, fungsi printf dengan format `%p` (untuk mencetak alamat pointer) mengharapkan argumennya bertipe `void*`, jadi perlu mengonversi pointer lain ke `void*` agaer sesuai kebutuhan fungsi itu. 

### Contoh kode dan penjelasan
```
#include <stdio.h>

int main()
{
    int angka = 42;
    printf("Alamat angka: %p\n", (void*)&angka);
    return 0;
}
```

**Apa yang terjadi?**
1. `&angka`: Operator ini menghasilkan alamat memori dari `angka`, dan tipenya `int*`(pointer ke integer).

2. (void*)&angka: kita "mengemas ulang" pointer `int*` menjadi `void*` dengan casting. ini memberitahu `printf` bahwa kita cuman ingin mencetak alamatnya sebagai lokasi generik, bukan sebagai pointer ke tipe tertentu

3. `%p`: Format khusus mencetak alamat memori dalam bentuk heksadesimal.

### Kapan (void*) Berguna?
1. Fleksibiltas: `void*` memungkinkan menyimpan alamat apa saja tanpa harus tahu tipenya saat itu. Contohnya dalam fungsi generic seperti `malloc`.

```
int *ptr = (int*)malloc(sizeof(int));
```

`malloc` mengembalikan `void*`, yang bisa kita ubah ke tipe apa saja (int*, char*, dll)

2. Interoperabilitas: saat berurusan dengan library atau fungsi yang tidak peduli tipe data `void*` jadi "jembatan".

3. Mencetak alamat

### Batasan `void*`
- **Tidak Bisa Dereference Langsung**: Kita tidak bisa langsung pakai `*` pada `void*` untuk mengakses isi memori, karena kompiler tidak tahu ukuran atau tipe datanya. Harus di-cast dulu ke tipe spesifik:

```
int *ptr = (int*)mallloc(sizeof(int));
*ptr = 10
```

- **Hanya Alamat**: `void*` cuman menyimpan alamat, bukan informasi tentang apa yang ada di alamat itu.


### Eksperimen 
Untuk memahami secara praktikal atau visual, coba kode ini
```
#include <stdio.h>
int main()
{
    int a = 100;
    char b = 'x';
    void *ptr;

    ptr = &a;
    printf("Alamat a: %p\n", ptr);

    ptr = &b;
    printf("Alamat b: %p\n", ptr);

    return 0;
}
```

- `ptr` bisa menunjuk ke `a` (integer) maupun `b` (char) tanpa masalah, karena `void*` tidak peduli tipe data
- Tapi kalo coba print dari (*ptr) tanpa cast, kompiler akan error:

```
printf("Isi: %d\n", *ptr);
```

### Kesimpulan
`(void*)` itu seperti "kunci master" untuk alamat memori bisa membuka pintu ke lokasi mana saja, tapi tidak memberi tahu apa yang ada di dalam sampai kamu bilang "ini kamar integer" atau "ini kamar char" dengan cast. Dalam kasus `printf`, kita pakai `(void*)` supaya alamatnya bisa ditampilkan dengan benar tanpa ribet soal tipe aslinya


*helped by grok 3*
