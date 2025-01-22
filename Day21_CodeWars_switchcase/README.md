
# Panduan Membuat Proyek C# dengan Test NUnit di Visual Studio Code

Halo! Berikut adalah panduan singkat bagaimana cara membuat proyek C# dengan test menggunakan NUnit di Visual Studio Code (VSCode). Kita juga akan bahas kenapa penting untuk menambahkan `break` di dalam `switch-case`.

### 1. **Persiapan**
Sebelum mulai, pastikan kamu sudah menginstal .NET SDK dan Visual Studio Code di komputer. Kamu juga perlu menginstal extension C# di VSCode, agar bisa menulis dan menjalankan kode C# dengan nyaman.

### 2. **Buat Proyek C# Baru**
Untuk mulai, buka terminal di VSCode dan buat proyek C# baru menggunakan perintah berikut:

```bash
dotnet new console -n SwitchCaseApp
cd SwitchCaseApp
```

Ini akan membuat proyek C# baru bernama `SwitchCaseApp` dan masuk ke dalam folder proyek.

### 3. **Buat Kode Utama**
Buka file `Program.cs` yang sudah ada, dan ganti isinya dengan kode berikut:

```csharp
using System;

public class Kata
{
    public static double EvalObject(double value1, double value2, char operation)
    {
        double result = 0;
        switch (operation)
        {
            case '+':
                result = value1 + value2;
                break;
            case '-':
                result = value1 - value2;
                break;
            case '/':
                result = value1 / value2;
                break;
            case '*':
                result = value1 * value2;
                break;
            case '%':
                result = value1 % value2;
                break;
            case '^':
                result = Math.Pow(value1, value2);
                break;
            default:
                throw new ArgumentException("Invalid operation");
        }
        return result;
    }
}
```

**Kenapa perlu `break`?**

Di dalam `switch-case`, setiap `case` perlu diakhiri dengan `break` agar eksekusi keluar dari blok `switch`. Tanpa `break`, program akan "terjatuh" ke case berikutnya (fall-through), yang bisa menyebabkan hasil yang tidak diinginkan. Misalnya, jika kamu tidak menambahkan `break` setelah `case '+'`, program akan terus mengevaluasi case berikutnya dan mengubah hasilnya.

### 4. **Buat Proyek untuk Test (Unit Test)**
Untuk menambahkan unit test, kita perlu membuat proyek test terpisah. Di folder proyek utama (misalnya `SwitchCaseApp`), jalankan perintah berikut untuk membuat proyek test:

```bash
dotnet new nunit -n SwitchCaseApp.Tests
cd SwitchCaseApp.Tests
```

Ini akan membuat proyek NUnit baru yang bisa digunakan untuk menulis dan menjalankan test.

### 5. **Tambahkan Referensi Proyek Utama ke Proyek Test**
Agar bisa mengakses kode dari proyek utama di proyek test, kita perlu menambahkan referensi ke proyek utama. Di folder `SwitchCaseApp.Tests`, jalankan perintah ini:

```bash
dotnet add reference ../SwitchCaseApp/SwitchCaseApp.csproj
```

### 6. **Tulis Test dengan NUnit**
Sekarang, buka file `SwitchCaseApp.Tests.cs` dan tulis kode test untuk memastikan fungsi `EvalObject` bekerja dengan benar:

```csharp
using System;
using NUnit.Framework;

[TestFixture]
public class Tests
{
    [Test]
    public static void FixedTest()
    {
        Assert.That(Kata.EvalObject(1, 1, '+'), Is.EqualTo(2));
        Assert.That(Kata.EvalObject(1, 1, '-'), Is.EqualTo(0));
        Assert.That(Kata.EvalObject(1, 1, '/'), Is.EqualTo(1));
        Assert.That(Kata.EvalObject(1, 1, '*'), Is.EqualTo(1));
        Assert.That(Kata.EvalObject(1, 1, '%'), Is.EqualTo(0));
        Assert.That(Kata.EvalObject(1, 1, '^'), Is.EqualTo(1));
    }
}
```

Test ini akan mengecek apakah operasi dasar seperti penjumlahan, pengurangan, pembagian, dll, berfungsi dengan benar.

### 7. **Restore dan Build Proyek**
Sekarang, kembali ke folder proyek utama (`SwitchCaseApp`), jalankan perintah ini untuk mengembalikan paket dan membangun proyek:

```bash
dotnet restore --> mengunduh dependecies yang ada pada .csproj atau .sln
dotnet build
```

Setelah itu, jalankan unit test:

```bash
dotnet test
```

### 8. **Menjalankan Test**
Jika semuanya sudah benar, kamu akan melihat output seperti ini:

```bash
Test Run Successful.
```

Itu artinya test kamu berhasil dijalankan dengan baik.

