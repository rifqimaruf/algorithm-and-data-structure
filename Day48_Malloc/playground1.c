// variable primitif
// tipe data primitif merujuk pada tipe data dasar yang disediakan bahasa pemro
// graman. di C ada `int`, `char`, `float`, variansi lainnya `short`, `long`,
// `unsigned int`, dll.

// struct 
// banyak hal permasalahan di dunia ini punya properti tertentu yang ngga bisa 
// di buat dengan variable primitif aja, sehingga diperlukan variable komposit / 
// user defined varible yg dinamakan struct. Misan Mahasiswa punya properti nama,
// nrp, dan nilai. Dengan Struct kita bisa mengelompokan suatu object dengan lebih
// rapi. di dalam Bahasa C mendefinisikan struct diawali dengan nama `struct` itu sendiri
// misal
// struct Mahasiswa 
// { 
// }

// pointer
// secara bahasa ada potongan kata point, atau penunjuk, di dalam bahasa C ini diarti
// kan sebagai petunjuk yang berada di memori komputer. variable yang di definisikan 
// sebagai pointer (baik primitif atau struct) akan memiliki fleksibilitas membaca alamatnya
// Beda dengan variable biasa (`x`) adlaah misal suatu kotak itu sendiri. sedangkan pointer
// petunjuk ke kotak kamu, jadi bukan kotaknya yang kamu pegang tapi alamat dari kotaknya.

// malloc 
// kependekan dari memory allocation.
// banyak struktur data seperti linked list, stack, queue yang butuh ukuran
// yang bisa berubah - ubah tergantung kebutuhan. Dengan Malloc kita bisa membuat
// node baru, menambahkan elemen, atau memperluas struktur tanpa harus mendefinisi-
// kan ukuran yang tetap (statis di awal)

// Ada tanggung jawab yang menyertai penggunaan `malloc`. Memori yang dialokasikan 
// secara dinamis tidak akan otomatis dibersihkan oleh sistem seperti variable local.
// Secara eksplisit harus dibebaskan menggunakan `free` agar tidak terjadi memori leak.

# include <stdio.h>
# include <stdlib.h>

int main()
{
    // playground1
    // ketika mendifisikan suatu variable, ada atribut atau properti fundamental yg pasti
    // melekat, seperti nilai / isi dari variable tersebut, ukuran, dan alamat yang dimana
    // variable disimpan di dalam memori (RAM)

    // 1. Variabel biasa (tanpa pointer)
    int var = 10;
    printf("Variabel biasa:\n");
    printf("Nilai var: %d\n", var);
    printf("Alamat var: %p\n", (void*)&var);
    printf("Ukuran var: %zu bytes\n\n", sizeof(var));

    // 2. Pointer ke variabel statis
    int* ptr = &var;
    printf("Pointer ke variabel statis:\n");
    printf("Nilai yang ditunjuk ptr: %d\n", *ptr);
    printf("Alamat yang disimpan di ptr: %p\n", (void*)ptr);
    printf("Alamat ptr itu sendiri: %p\n", (void*)&ptr);
    printf("Ukuran pointer: %zu bytes\n\n", sizeof(ptr));

    // 3. Pointer dengan malloc (memori dinamis)
    int* dynamicPtr = malloc(sizeof(int));
    *dynamicPtr = 20; // Isi nilai ke memori yang dialokasikan
    printf("Pointer dengan malloc (memori dinamis):\n");
    printf("Nilai yang ditunjuk dynamicPtr: %d\n", *dynamicPtr);
    printf("Alamat yang disimpan di dynamicPtr: %p\n", (void*)dynamicPtr);
    printf("Alamat dynamicPtr itu sendiri: %p\n", (void*)&dynamicPtr);
    printf("Ukuran pointer: %zu bytes\n\n", sizeof(dynamicPtr));

    // Ubah nilai melalui pointer
    *ptr = 15;         // Ubah var melalui pointer statis
    *dynamicPtr = 25;  // Ubah nilai di memori dinamis
    printf("Setelah diubah:\n");
    printf("var (via ptr): %d\n", var);
    printf("dynamicPtr: %d\n", *dynamicPtr);

    // Bebaskan memori dinamis
    free(dynamicPtr);
    printf("\nMemori dinamis dibebaskan.\n");

    // %p specifier cetak alamat memori dalam bentuk hexadecimal
    // %zu specifier format untuk cetak nilai bertipe size_t
    // (void*) type casting menjadi tipe pointer (generic) / tidak 
    // terkait ke tipe data tertentu
    return 0;
}
