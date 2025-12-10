# Pass The Pillow

[Source](https://leetcode.com/problems/pass-the-pillow/description/?envType=daily-question&envId=2024-07-06)

## Problem

Terdapat n orang yang berbaris dari 1 hingga n. Orang pertama adalah orang yang pertama kali memegang banta. Setiap detik, orang yang memegang bantal akan memberikan bantal tersebut kepada orang berikutnya yang berbaris di dalam barisan. Setelah bantal berada pada baris terakhir, arahnya berubah. Dan setiap orang akan memberikan bantal ke arah yang beralawanan.

Example 1:

> -   Input: n = 4, time = 5
> -   Output: 2
> -   Penjelasan: Orang-orang melempar bantal sebagai berikut: 1 -> 2 -> 3 -> 4 -> 3 -> 2. Setelah lima detik, orang kedua yang memegang bantal.

Example 2:

> -   Input: n = 3, time = 2
> -   Output: 3
> -   Orang-orang melempar bantal sebagai berikut: 1 -> 2 -> 3. Setelah dua detik, orang ketiga yang memegang bantal.

**Constrains**

-   2 <= n <= 1000
-   1 <= time <= 1000
