### Question
Complete the solution so that it splits the string into pairs of two characters. If the string contains an odd number of characters then it should replace the missing second character of the final pair with an underscore ('_').

### Methode 
Kode ini berfungsi untuk memecah sebuah teks (string) menjadi pasangan-pasangan dua huruf. Jika teks memiliki jumlah huruf yang ganjil, huruf terakhir akan dipasangkan dengan tanda garis bawah ("_").

## Metode Penyelesaian

Kode ini berfungsi untuk memecah sebuah teks (string) menjadi pasangan-pasangan dua huruf. Jika teks memiliki jumlah huruf yang ganjil, huruf terakhir akan dipasangkan dengan tanda garis bawah ("_").

## Metode Penyelesaian

Kode ini menggunakan dua metode utama:

1.  **List Comprehension:** Cara ringkas untuk membuat list baru berdasarkan iterable (dalam hal ini, string). Menghasilkan list pasangan huruf lebih efisien dari loop `for` biasa.

    *   **Kode dengan List Comprehension (Ringkas):**

        ```python
        def solution(s):
            result = [s[i:i+2] for i in range(0, len(s), 2)]
            if len(s) % 2 != 0:
                result[-1] += "_"
            return result
        ```

    *   **Kode Tanpa List Comprehension (Lebih Panjang):**

        ```python
        def solution_tanpa_comprehension(s):
            result = []
            for i in range(0, len(s), 2):
                pair = s[i:i+2]
                result.append(pair)

            if len(s) % 2 != 0:
                result[-1] += "_"
            return result
        ```

    *   **Penjelasan List Comprehension:**
        *   `[s[i:i+2] for i in range(0, len(s), 2)]`: Iterasi melalui indeks string (`i`) dengan langkah 2, mengambil potongan string (`s[i:i+2]`) pada setiap iterasi, dan menambahkannya ke list `result`.
        *   **String Slicing (s[i:i+2]):** Mengambil bagian dari string `s`. `i` adalah indeks awal (termasuk), dan `i+2` adalah indeks akhir (tidak termasuk). Jika `i+2` melebihi panjang string, slice akan berhenti di akhir string.

2.  **Negative Indexing:** Mengakses elemen terakhir dari list dengan indeks `-1`. Berguna memodifikasi elemen terakhir (jika perlu) ketika panjang string ganjil.

    *   **Contoh Negative Indexing:**

        ```python
        result = ['ab', 'cd', 'ef', 'g']
        result[-1] += "_"  # Mengubah elemen terakhir menjadi 'g_'
        print(result)  # Output: ['ab', 'cd', 'ef', 'g_']
        ```

