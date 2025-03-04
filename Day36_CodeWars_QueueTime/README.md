# Queue Time Duration
Permasalahan ini berfokus pada perhitungan waktu yang dibutuhkan seseorang dalam antrean untuk mendapatkan semua tiket yang diinginkan, di mana setiap orang hanya dapat membeli satu tiker per giliran lalu kembali ke akhir antrean hika masih membutuhkan tiket. Dalam konteks bahasa C, karena tidak ada struktur data queue bawaan, kita perlu membuat simulasi antrean secara manual menggunakan alokasi dinamis menggunakan `malloc`.

## Logika dan Intuisi Penyelesaian
### 1. Memahami Masalah
Langkah pertama adalah memahami mekanisme antrean:
- Ada antrean orang, masing-masing dengan jumlah tiket yang diinginkan (misalnya '[2, 5, 3, 4, 6]')
- Setiap giliran, orang di depan beli 1 tiket (1 menit), lalu:
    - Jika masih butuh tiket, kembali ke belakang antrean dengan kondisi tiket berkurang 1.
    - Jika tidak mereka keluar dari antrean
- Tujuan: Hitung waktu yang dibutuhkan sampai teman kita selesai

### 2. Pendekatan Awal: Simulasi Brute Force
Ide awal adalah mensimulasikan antrean seperti di dunia nyata:
- Ambil orang pertama, kurangi tiketnya, pindahkan ke belakang jika perlu.
- Ulangi sampai teman selesai.
- Ini mirip queue (FIFO), tapi kita tidak punya queue bawaan di C, jadi kita pikirkan cara lain.

Namun, setelah dicoba secara manual:
- Menit 1: `[2, 5, 3, 4, 6]` → `[1, 5, 3, 4, 6]` → `[5, 3, 4, 6, 1]`.
- Menit 2: `[5, 3, 4, 6, 1]` → `[4, 3, 4, 6, 1]` → `[3, 4, 6, 1, 4]`.
- Menit 3: `[3, 4, 6, 1, 4]` → `[2, 4, 6, 1, 4]` → `[4, 6, 1, 4, 2]`.

Ini menunjukkan pola: Kita bisa lacak tiket yang tersisa tanpa benar-benar "memindahkan" orang, cukup kurangi di tempat dan ulang.

### 3. Menyederhanakan Simulasi
Daripada memindahkan elemen (yang rumit di array C), kita ubah pendekatan:
- Gunakan array untuk lacak sisa tiket setiap orang.
- Tiap "ronde", periksa semua orang:
  - Jika sisa tiket > 0, kurangi 1, tambah 1 menit ke waktu.
  - Jika itu teman kita, perbarui jumlah tiket yang dia masih butuh.
- Berhenti saat teman selesai (sisa tiketnya 0).

Ini lebih sederhana karena:
- Tidak perlu struktur queue formal (hemat memori dan kode).
- Kita tahu panjang array tetap, jadi cukup ulang sampai kondisi terpenuhi.

### 4. Menangani Input `const`
Masalah: Parameter `queue` bertipe `const unsigned*`, jadi tidak boleh diubah. Solusi:
- Buat salinan dengan `malloc` untuk array sementara (`temp_queue`).
- Salin data awal ke `temp_queue`, lalu gunakan itu untuk simulasi.

### 5. Membangun Logika Utama
- **Inisialisasi**:
  - Salin `queue` ke `temp_queue`.
  - Simpan jumlah tiket teman (`friendTickets`) dan lacak sisa (`friendRemaining`).
  - Set waktu awal ke 0 (`time`).

- **Loop Utama**:
  - Selama `friendRemaining > 0` (teman belum selesai):
    - Cek setiap elemen di `temp_queue`.
    - Jika `temp_queue[i] > 0`:
      - Kurangi 1 (beli tiket).
      - Tambah 1 ke `time`.
      - Jika `i` adalah indeks teman (`idx`):
        - Kurangi `friendRemaining`.
        - Jika `friendRemaining == 0`, kembalikan `time`.

- **Pembersihan**:
  - Bebaskan `temp_queue` dengan `free` untuk hindari kebocoran memori.

