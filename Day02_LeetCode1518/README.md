# Pass The Pillow

[Source](https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2024-07-07)

## Problem

Terdapat `m` botol air yang inisialsinya adalah penuh. Setelah diminum botol-botol tersebut menjadi kosong, namun botol bisa bisa ditukar ke pasar sebanyak `n` botol kosong menjadi satu botol air yang penuh.

Diberikan dua integer, `jumlahBotol` dan `jumlahTukar`, dengan pengembalian adalah `maximal` jumlah botol air yang bisa diminum

Example 1:

> -   Input: m = 9, n = 3
> -   Output: 3
> -   Penjelasan: Sejumlah 3 botol kosong diubah menjadi 1 butuh air penuh. Sehingga maximal jumlah botol yang bisa diminum 9 + 3 + 1 = 13.

Example 2:

> -   Input: n = 15, time = 4
> -   Output: 19
> -   Penjelasan: kamu bisa menukarkan 4 botol dengan 1 botol penuh. Total botol: 15 + 3 + 1 = 19.

**Constrains**

-   1 <= m <= 100
-   2 <= n <= 100
