# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahasa C++ (Bagian Pertama)</h1>

<p align="center">Hassan Donny Darmawan - 109082500030</p>

## Dasar Teori

Bagian ini membahas konsep dasar yang digunakan dalam praktikum, mulai dari pengenalan *tool* dan bahasa pemrograman, tipe data dan variabel, input/output, hingga operator dan struktur kontrol program.
 
---
 
### A. Code::Blocks dan Bahasa C++<br/>
 
Sub-bagian ini membahas *tool* yang digunakan dalam praktikum beserta bahasa pemrograman yang dipakai.
 
#### 1. Code::Blocks
 
Code::Blocks adalah IDE (*Integrated Development Environment*) gratis dan *open-source* untuk bahasa C/C++/Fortran yang menyediakan *editor*, *compiler*, dan *debugger* dalam satu aplikasi, dengan alur kerja dasar berupa membuat *project*, menulis kode, *build* (kompilasi), lalu *run* (eksekusi).
 
#### 2. Sejarah Singkat Bahasa C++
 
Bahasa C++ dikembangkan oleh Bjarne Stroustrup pada awal 1980-an sebagai pengembangan dari bahasa C, dengan tambahan fitur pemrograman berorientasi objek.
 
#### 3. Struktur Program C++
 
Struktur program C++ umumnya terdiri dari: *header* (`#include`), fungsi `main()` sebagai titik awal eksekusi, dan pernyataan yang diakhiri tanda titik koma (`;`).
 
### B. Tipe Data, Variabel, dan Konstanta<br/>
 
Sub-bagian ini membahas cara data direpresentasikan dan disimpan dalam program.
 
#### 1. Tipe Data Dasar
 
Tipe data dasar meliputi `int` (bilangan bulat), `float`/`double` (bilangan pecahan), dan `char` (karakter), masing-masing memiliki ukuran dan jangkauan nilai berbeda.
 
#### 2. Variabel

Variabel adalah tempat menyimpan nilai yang dapat berubah, dideklarasikan dengan format `tipe nama;`.
 
#### 3. Konstanta
 
Konstanta (`const`) adalah nilai yang bersifat tetap dan tidak dapat diubah selama program berjalan.
 
### C. Input dan Output<br/>
 
Sub-bagian ini membahas cara program berinteraksi dengan pengguna.
 
#### 1. Fungsi `cin`
 
`cin` digunakan untuk membaca input dari *keyboard* menggunakan operator ekstraksi `>>`.
 
#### 2. Fungsi `cout`
 
`cout` digunakan untuk menampilkan output ke layar menggunakan operator penyisipan `<<`.
 
#### 3. Escape Sequence
 
Escape sequence (mis. `\n`, `\t`) digunakan untuk menyisipkan karakter kontrol seperti baris baru atau tab pada teks keluaran.
 
### D. Operator<br/>
 
Sub-bagian ini membahas simbol-simbol yang digunakan untuk melakukan operasi atau manipulasi data.
 
#### 1. Operator Aritmatika dan Assignment
 
Operator aritmatika (`+ - * / %`) digunakan untuk operasi hitung, sedangkan operator assignment (`= += -=`) digunakan untuk memberikan atau mengubah nilai variabel.
 
#### 2. Operator Relasi dan Logika
 
Operator relasi (`== != < >`) membandingkan dua nilai, sedangkan operator logika (`&& || !`) menggabungkan atau membalik hasil dari beberapa kondisi.
 
#### 3. Operator Increment dan Decrement
 
Operator `++` dan `--` digunakan untuk menambah atau mengurangi nilai variabel sebesar 1, dengan bentuk *prefix* (`++i`) dan *postfix* (`i++`) yang berbeda urutan eksekusinya.
 
### E. Struktur Kontrol Program<br/>
 
Sub-bagian ini membahas cara mengatur alur eksekusi program.
 
#### 1. Kondisional
 
Struktur kondisional (`if`, `if-else`, `switch`) digunakan untuk pengambilan keputusan berdasarkan suatu kondisi.
 
#### 2. Perulangan
 
Struktur perulangan (`for`, `while`, `do-while`) digunakan untuk mengeksekusi blok kode berulang kali secara efisien.
 
#### 3. Struktur (Struct)
 
`struct` adalah tipe data bentukan yang mengelompokkan beberapa variabel dengan tipe berbeda ke dalam satu nama, umumnya digunakan bersama *array* untuk menyimpan data majemuk.
 
---

## Guided

### 1. ...

```C++
#include <iostream>
using namespace std;
int main(){
int W, X, Y; float Z;
X = 7; Y = 3; W = 1;
Z = (X + Y)/(Y + W);
cout<< "Nilai z = " << Z << endl;
return 0;
}
```

## Penjelasan Kode

Program ini mendeklarasikan tiga variabel bertipe `int`, yaitu `X`, `Y`, dan `W`, serta satu variabel bertipe `float` bernama `Z`. Variabel `X` diberi nilai 7, `Y` diberi nilai 3, dan `W` diberi nilai 1. Selanjutnya, nilai `Z` dihitung dari ekspresi `(X + Y)/(Y + W)`, yaitu `(7 + 3)/(3 + 1)` atau `10/4`. Karena `X`, `Y`, dan `W` semuanya bertipe `int`, maka pembagian `10/4` dianggap sebagai pembagian bilangan bulat (*integer division*), sehingga hasilnya dibulatkan ke bawah menjadi `2`, bukan `2.5`. Nilai `2` inilah yang kemudian disimpan ke dalam `Z`, meskipun `Z` bertipe `float`, sehingga saat dicetak dengan `cout`, hasil yang muncul adalah "Nilai z = 2.000000".

Kasus ini menunjukkan konsep penting dalam C++, yaitu pembagian antar bilangan bertipe `int` akan menghasilkan bilangan bulat meskipun variabel penampungnya bertipe `float`. Untuk mendapatkan hasil desimal yang sesuai (`2.5`), salah satu operand pada pembagian perlu diubah tipenya menjadi `float` terlebih dahulu menggunakan *type casting*, misalnya `Z = (float)(X + Y)/(Y + W);`.

### 2. ...

```C++
#include <iostream>
using namespace std;
int main(){
int r = 10;
int s;
s=10 + ++r;
cout<< "Nilai r= "<<r<<endl;
cout<< "Nilai s= "<<s<<endl;
return 0;
}
```

## Penjelasan Kode

Program ini mendeklarasikan variabel `r` bertipe `int` dengan nilai awal 10, serta variabel `s` bertipe `int` yang belum diberi nilai. Pada baris `s = 10 + ++r;`, digunakan operator **pre-increment** (`++r`), yang artinya nilai `r` dinaikkan terlebih dahulu sebesar 1 sebelum digunakan dalam perhitungan. Sehingga `r` yang awalnya 10 berubah menjadi 11 terlebih dahulu, baru kemudian dijumlahkan dengan 10, menghasilkan `s = 10 + 11 = 21`.

Karena itu, saat program dijalankan, hasil yang dicetak adalah "Nilai r= 11" dan "Nilai s= 21". Perilaku ini berbeda jika menggunakan **post-increment** (`r++`), di mana nilai lama `r` akan dipakai dulu dalam perhitungan, baru setelah itu `r` dinaikkan — sehingga hasil `s` akan berbeda meskipun nilai akhir `r` tetap sama.

### 3. ...

```C++
#include <iostream>
#include <stdlib.h>
using namespace std;
int main(){
int r = 10;
int s;
s=10 + r++;
cout<< "Nilai r= "<<r<<endl;
cout<< "Nilai s= "<<s<<endl;
return 0;
}
```

## Penjelasan Kode

Program ini mendeklarasikan variabel `r` bertipe `int` dengan nilai awal 10, serta variabel `s` bertipe `int` yang belum diberi nilai. Pada baris `s = 10 + r++;`, digunakan operator **post-increment** (`r++`), yang artinya nilai `r` yang lama (yaitu 10) dipakai terlebih dahulu dalam perhitungan, baru setelah itu `r` dinaikkan sebesar 1. Sehingga perhitungan yang terjadi adalah `s = 10 + 10 = 20`, kemudian barulah `r` bertambah menjadi 11.

Karena itu, saat program dijalankan, hasil yang dicetak adalah "Nilai r= 11" dan "Nilai s= 20". Perilaku ini berbeda dengan **pre-increment** (`++r`), di mana `r` dinaikkan dulu sebelum dipakai dalam perhitungan, sehingga hasil `s` akan lebih besar dibanding menggunakan post-increment, meskipun nilai akhir `r` tetap sama.

### 4. ...

```C++
#include <iostream>
using namespace std;
int main(){
double tot_pembelian, diskon;
cout<<"total pembelian: Rp";
cin>>tot_pembelian;
diskon = 0;
if(tot_pembelian >= 100000)
diskon = 0.05*tot_pembelian;
cout<<"besar diskon = Rp" <<diskon;
}
```

## Penjelasan Kode

Program ini mendeklarasikan dua variabel bertipe `double`, yaitu `tot_pembelian` dan `diskon`. User diminta memasukkan nilai total pembelian melalui `cin`, kemudian variabel `diskon` diberi nilai awal 0. Selanjutnya, program memeriksa dengan pernyataan `if`: jika `tot_pembelian` bernilai lebih besar atau sama dengan 100.000, maka `diskon` dihitung sebesar 5% dari total pembelian (`0.05 * tot_pembelian`). Jika kondisi tersebut tidak terpenuhi, nilai `diskon` tetap 0 karena tidak ada pernyataan `else` yang mengubahnya.

Terakhir, program mencetak besar diskon yang didapat menggunakan `cout`. Contohnya, jika user memasukkan total pembelian 200.000, maka diskon yang dihitung adalah `0.05 * 200000 = 10000`, sehingga tercetak "besar diskon = Rp10000". Namun jika total pembelian kurang dari 100.000, misalnya 50.000, maka diskon tetap 0 karena syarat pada `if` tidak terpenuhi.

### 5. ...

```C++
#include <iostream>
using namespace std;
int main(){
double tot_pembelian, diskon;
cout<<"total pembelian: Rp";
cin>>tot_pembelian;
diskon = 0;
if(tot_pembelian >= 100000)
diskon = 0.05*tot_pembelian;
else
diskon = 0;
cout<<"besar diskon = Rp" <<diskon;
}
```

## Penjelasan Kode

Program ini mendeklarasikan dua variabel bertipe `double`, yaitu `tot_pembelian` dan `diskon`. User diminta memasukkan nilai total pembelian melalui `cin`, kemudian variabel `diskon` diberi nilai awal 0. Selanjutnya, program menggunakan pernyataan `if-else` untuk menentukan besar diskon: jika `tot_pembelian` bernilai lebih besar atau sama dengan 100.000, maka `diskon` dihitung sebesar 5% dari total pembelian (`0.05 * tot_pembelian`), namun jika kondisi tersebut tidak terpenuhi (kurang dari 100.000), maka `diskon` secara eksplisit diberi nilai 0 melalui blok `else`.

Terakhir, program mencetak besar diskon yang didapat menggunakan `cout`. Contohnya, jika user memasukkan total pembelian 200.000, maka diskon yang dihitung adalah `0.05 * 200000 = 10000`, sehingga tercetak "besar diskon = Rp10000". Sedangkan jika total pembelian 50.000, maka `diskon` langsung diset 0 melalui bagian `else`, sehingga tercetak "besar diskon = Rp0". Program ini pada dasarnya menghasilkan output yang sama seperti versi sebelumnya (yang hanya menggunakan `if` tanpa `else`), hanya saja di sini nilai 0 pada kondisi salah dituliskan secara eksplisit agar logikanya lebih jelas terlihat.

### 6. ...

```C++
#include <iostream>
using namespace std;
int main(){
int kode_hari;
puts("Menentukan hari kerja/libur\n");
puts("1=Senin 3=Rabu 5=Jumat 7=Minggu ");
puts("2=Selasa 4=Kamis 6=Sabtu ");
cin>>kode_hari;
switch(kode_hari){
case 1:
case 2:
case 3:
case 4:
case 5:
cout<<"Hari Kerja"<<endl;
break;
case 6:
case 7:
cout<<"Hari Libur"<<endl;
break;
default:
cout<<"Kode masukan salah!!!"<<endl;
}
return 0;
}
```

## Penjelasan Kode

Program ini mendeklarasikan variabel `kode_hari` bertipe `int`, kemudian menampilkan beberapa baris teks petunjuk menggunakan `puts()` yang menjelaskan kode angka untuk masing-masing hari (1 = Senin, 2 = Selasa, dan seterusnya). Setelah itu, user diminta memasukkan sebuah angka melalui `cin` yang akan disimpan ke dalam `kode_hari`.

Nilai `kode_hari` kemudian diperiksa menggunakan struktur `switch-case`. Pada kode ini, `case 1` sampai `case 5` sengaja tidak diberi `break` di antaranya (disebut *fall-through*), sehingga jika `kode_hari` bernilai 1, 2, 3, 4, atau 5, program akan langsung menjalankan pernyataan pada `case 5`, yaitu mencetak "Hari Kerja", lalu berhenti karena ada `break`. Dengan cara yang sama, jika `kode_hari` bernilai 6 atau 7, program akan mencetak "Hari Libur". Jika angka yang dimasukkan tidak sesuai dengan 1–7, maka blok `default` akan dijalankan dan program mencetak "Kode masukan salah!!!".

Teknik menumpuk beberapa `case` tanpa `break` seperti ini berguna ketika beberapa kondisi berbeda perlu menghasilkan aksi yang sama, sehingga kode menjadi lebih ringkas dibandingkan menuliskan pernyataan yang sama berulang-ulang di setiap `case`.

### 7. ...

```C++
#include <iostream>
using namespace std;
int main(){
int jum;
cout<<"jumlah perulangan: ";
cin>>jum;
for(int i=0; i<jum; i++){
cout<<"saya pintar\n";
}
return 0;
}
```

## Penjelasan Kode

Program ini mendeklarasikan variabel `jum` bertipe `int`, kemudian meminta user memasukkan jumlah perulangan yang diinginkan melalui `cin`. Nilai ini akan menentukan berapa kali kalimat akan dicetak.

Selanjutnya digunakan perulangan `for` dengan variabel kontrol `i` yang dimulai dari 0 (`i=0`), akan terus berjalan selama `i` masih lebih kecil dari `jum` (`i<jum`), dan setiap selesai satu putaran nilai `i` bertambah 1 (`i++`). Selama kondisi tersebut terpenuhi, program akan mencetak kalimat "saya pintar" diikuti baris baru (`\n`).

Sebagai contoh, jika user memasukkan angka 3, maka perulangan akan berjalan sebanyak 3 kali (untuk `i = 0, 1, 2`), sehingga kalimat "saya pintar" akan tercetak sebanyak 3 baris berturut-turut.

### 8. ...

```C++
#include <iostream>
using namespace std;
int main(){
int i=1;
int jum;
cout<<"masukan banyak baris: ";
cin>>jum;
while(i<=jum){
cout<<"baris ke-"<<i<<endl;
i++; 
}
return 0;
}
```

## Penjelasan Kode

Program ini mendeklarasikan variabel `i` dengan nilai awal 1 dan variabel `jum` bertipe `int` yang nilainya akan diisi oleh user melalui `cin` sebagai banyaknya baris yang ingin dicetak.

Selanjutnya digunakan perulangan `while` dengan kondisi `i<=jum`, artinya selama nilai `i` masih lebih kecil atau sama dengan `jum`, blok kode di dalamnya akan terus dijalankan. Setiap kali perulangan berjalan, program mencetak teks "baris ke-" diikuti nilai `i` saat itu, kemudian nilai `i` ditambah 1 (`i++`) agar perulangan pada akhirnya berhenti dan tidak menjadi *infinite loop*.

Sebagai contoh, jika user memasukkan angka 3, maka program akan mencetak "baris ke-1", "baris ke-2", dan "baris ke-3" secara berurutan, sebelum akhirnya kondisi `i<=jum` bernilai salah (karena `i` menjadi 4) dan perulangan berhenti.

### 9. ...

```C++
#include <iostream>
using namespace std;
int main(){
int i = 1;
int jum;
cin >> jum;
do{
cout << "baris ke-" <<(i+1)<<endl;
i++;
} while(i<jum);
return 0;
}
```

## Penjelasan Kode

Program ini mendeklarasikan variabel `i` dengan nilai awal 1 dan variabel `jum` yang nilainya diminta dari user melalui `cin`. Selanjutnya digunakan perulangan `do-while`, yang berbeda dari `while` biasa karena pengecekan kondisinya dilakukan di **akhir** blok, sehingga isi perulangan pasti dijalankan minimal satu kali sebelum kondisi diperiksa.

Di dalam blok `do`, program mencetak teks "baris ke-" diikuti nilai `i+1` (bukan `i` langsung), kemudian nilai `i` ditambah 1 (`i++`). Setelah itu, kondisi `i<jum` diperiksa; jika masih benar, perulangan diulang lagi, jika salah maka perulangan berhenti.

Sebagai contoh, jika user memasukkan `jum = 3`, maka jalannya program adalah: pertama `i=1` sehingga tercetak "baris ke-2", lalu `i` menjadi 2 dan diperiksa `2<3` (benar) sehingga diulang; tercetak "baris ke-3", lalu `i` menjadi 3 dan diperiksa `3<3` (salah) sehingga perulangan berhenti. Hasil akhirnya hanya tercetak dua baris ("baris ke-2" dan "baris ke-3"), bukan tiga baris seperti yang mungkin diharapkan — ini terjadi karena penomoran memakai `i+1` sementara kondisi berhenti memakai `i<jum` (bukan `i<=jum`), sehingga baris pertama ("baris ke-1") terlewat dan total baris yang tercetak menjadi satu lebih sedikit dari nilai `jum`.

### 10. ...

```C++
#include <iostream>
#define MAX 5
using namespace std;
int main(){
int i;
struct data{
char nama[40];
int nilai;
};
data siswa[MAX];
for(i=0; i<MAX; i++){
cout<<"masukkan data ke-"<<i+1<<endl;
cout<<"nama = ";
cin>>siswa[i].nama;
cout<<"nilai = ";
cin>>siswa[i].nilai;
}
cout<<"\ndata siswa\n";
cout<<"=======";
for(i=0; i<MAX; i++){
cout<<"\n\ndata ke-"<<i+1;
cout<<"\n\nnama="<<siswa[i].nama;
cout<<"\n\nnilai="<<siswa[i].nilai;
}
return 0;
}
```

## Penjelasan Kode

Program ini menggunakan `#define MAX 5` untuk membuat konstanta bernama `MAX` bernilai 5, yang menentukan jumlah data siswa yang akan diinput. Kemudian dideklarasikan sebuah `struct` bernama `data` yang berisi dua anggota, yaitu `nama` (array karakter untuk menyimpan nama) dan `nilai` (bertipe `int`). Struktur ini digunakan untuk mengelompokkan data nama dan nilai seorang siswa menjadi satu kesatuan. Selanjutnya dibuat array bertipe `data` bernama `siswa` sebanyak `MAX` elemen, sehingga bisa menampung data untuk 5 siswa sekaligus.

Perulangan `for` pertama digunakan untuk menginput data setiap siswa satu per satu: program meminta `nama` dan `nilai`, lalu menyimpannya ke elemen `siswa[i]` menggunakan tanda titik (`.`) untuk mengakses anggota struktur, misalnya `siswa[i].nama` dan `siswa[i].nilai`. Proses ini berulang sebanyak `MAX` kali (5 kali), sehingga seluruh data 5 siswa terisi.

Setelah semua data diinput, perulangan `for` kedua digunakan untuk menampilkan kembali seluruh data yang telah dimasukkan, dengan mencetak nomor data, nama, dan nilai setiap siswa secara berurutan. Program ini menunjukkan bagaimana `struct` dan `array` dapat dikombinasikan untuk menyimpan dan mengelola sekumpulan data yang memiliki beberapa atribut sekaligus, seperti data siswa yang terdiri dari nama dan nilai.

### 11. ...

```C++
#include <iostream>
using namespace std;

float ctof(float celcius);
int main() {
float celcius, fahrenheit;
cout <<"nilai Celcius? ";
cin >> celcius;
fahrenheit = ctof(celcius);
cout<<celcius<<" Celcius adalah "<<fahrenheit<<" Fahrenheit"<<endl;
return 0;
}

float ctof(float celcius){
return (celcius * 1.8) + 32;
}
```

## Penjelasan Kode

Program ini diawali dengan deklarasi fungsi `float ctof(float celcius);` sebelum `main()`, yang disebut *function prototype*. Ini memberi tahu compiler bahwa nanti akan ada fungsi bernama `ctof` yang menerima satu parameter bertipe `float` dan mengembalikan nilai bertipe `float`, sehingga fungsi tersebut sudah bisa dipanggil di dalam `main()` meskipun definisi lengkapnya baru dituliskan di bawah.

Di dalam `main()`, dideklarasikan dua variabel bertipe `float`, yaitu `celcius` dan `fahrenheit`. User diminta memasukkan nilai suhu dalam Celcius melalui `cin`, lalu nilai tersebut dikirim ke fungsi `ctof(celcius)` untuk dikonversi. Hasil konversi ini disimpan ke variabel `fahrenheit`, kemudian dicetak bersama nilai Celcius aslinya menggunakan `cout`.

Fungsi `ctof` sendiri didefinisikan di bagian bawah program, isinya menghitung konversi suhu dengan rumus `(celcius * 1.8) + 32`, lalu hasilnya dikembalikan (`return`) ke bagian program yang memanggilnya. Sebagai contoh, jika user memasukkan 10 derajat Celcius, maka fungsi akan menghitung `(10 * 1.8) + 32 = 50`, sehingga tercetak "10 Celcius adalah 50 Fahrenheit". Program ini menunjukkan cara memisahkan logika perhitungan ke dalam fungsi tersendiri agar kode `main()` lebih ringkas dan mudah dibaca.

## Unguided

### 1. 

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama  : ";
    cin >> a;
    cout << "Masukkan bilangan kedua    : ";
    cin >> b;

    cout << "\nHasil operasi:" << endl;
    cout << a << " + " << b << " = " << (a + b) << endl;
    cout << a << " - " << b << " = " << (a - b) << endl;
    cout << a << " * " << b << " = " << (a * b) << endl;

    if (b != 0)
        cout << a << " / " << b << " = " << (a / b) << endl;
    else
        cout << a << " / " << b << " = tidak terdefinisi (pembagian dengan nol)" << endl;

    return 0;
}

```

### Output Unguided 1 :

![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

## Penjelasan Kode

Program ini mendeklarasikan dua variabel bertipe `float`, yaitu `a` dan `b`, yang nilainya akan diisi oleh user melalui `cin` sebagai dua bilangan yang akan dioperasikan. Setelah kedua nilai diinput, program mencetak hasil dari empat operasi aritmatika dasar, yaitu penjumlahan (`a + b`), pengurangan (`a - b`), dan perkalian (`a * b`), yang masing-masing langsung dihitung di dalam `cout` dan ditampilkan bersama nilai `a` dan `b` aslinya agar hasilnya mudah dibaca.

Untuk operasi pembagian, program menggunakan pernyataan `if-else` untuk memeriksa apakah `b` sama dengan 0 atau tidak. Jika `b` tidak sama dengan 0, maka pembagian `a / b` dihitung dan dicetak seperti biasa. Namun jika `b` bernilai 0, program tidak melakukan pembagian dan malah mencetak pesan "tidak terdefinisi (pembagian dengan nol)", karena secara matematis pembagian dengan nol tidak memiliki hasil yang valid dan jika tetap dipaksakan bisa menyebabkan program berjalan tidak semestinya.

Pengecekan ini penting sebagai bentuk penanganan kesalahan sederhana (*error handling*), sehingga program tetap aman dijalankan meskipun user memasukkan nilai `b` sama dengan 0.

### 2. (isi dengan soal unguided 2)

```C++
#include <iostream>
#include <string>
using namespace std;

string terbilang(int n) {
    string satuan[] = {
        "nol", "satu", "dua", "tiga", "empat", "lima",
        "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"
    };

    if (n <= 11) {
        return satuan[n];
    } else if (n < 20) {
        return satuan[n - 10] + " belas";
    } else if (n < 100) {
        int puluh = n / 10;
        int sisa  = n % 10;
        string hasil = satuan[puluh] + " puluh";
        if (sisa > 0)
            hasil += " " + satuan[sisa];
        return hasil;
    } else if (n == 100) {
        return "seratus";
    }
    return "diluar jangkauan";
}

int main() {
    int angka;
    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka harus antara 0 sampai 100!" << endl;
        return 0;
    }

    cout << angka << " : " << terbilang(angka) << endl;

    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

##### Output 2

![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

## Penjelasan Kode

Program ini memiliki sebuah fungsi bernama `terbilang(int n)` yang bertugas mengubah angka menjadi tulisan. Di dalamnya terdapat array `satuan` yang menyimpan nama-nama angka dasar dari "nol" sampai "sebelas", yang menjadi acuan dasar untuk membentuk kata-kata angka lainnya.

Fungsi ini memeriksa angka `n` secara bertahap menggunakan `if-else if`. Jika `n` bernilai 0 sampai 11, maka nama angkanya langsung diambil dari array `satuan`. Jika `n` berada di rentang 12–19, maka diambil nama satuannya lalu ditambahkan kata "belas" (misalnya 15 menjadi "lima belas"). Untuk angka 20–99, angka dipecah menjadi bagian puluhan (`n/10`) dan sisa satuan (`n%10`), lalu digabungkan menjadi kata seperti "tujuh puluh sembilan" untuk 79; jika sisanya 0 (misalnya untuk angka 30, 40, dst), kata satuannya tidak ditambahkan sehingga hanya tercetak "tiga puluh". Terakhir, ada kasus khusus untuk angka 100 yang langsung dikembalikan sebagai "seratus".

Pada fungsi `main()`, user diminta memasukkan angka melalui `cin`, kemudian program memeriksa apakah angka tersebut berada di luar rentang 0–100; jika ya, program menampilkan pesan kesalahan dan langsung berhenti (`return 0`). Jika angka valid, fungsi `terbilang()` dipanggil untuk mengubah angka tersebut menjadi tulisan, lalu hasilnya dicetak bersama angka aslinya, misalnya "79 : tujuh puluh sembilan".

### 3. (isi dengan soal unguided 3)

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;

    cout << "output:" << endl;
    for (int i = n; i >= 0; i--) {
        // spasi di depan agar membentuk kerucut (rata tengah)
        for (int k = 0; k < (n - i) * 2; k++) {
            cout << " ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "*";

        for (int j = 1; j <= i; j++) {
            cout << " " << j;
        }

        cout << endl;
    }

    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

##### Output 2

![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

## Penjelasan Kode

Program ini meminta user memasukkan angka `n` melalui `cin`, yang menentukan besar pola kerucut yang akan dibentuk. Digunakan perulangan `for` luar dengan variabel `i` yang dimulai dari `n` dan terus berkurang (`i--`) sampai 0, sehingga jumlah baris yang dicetak sebanyak `n+1` baris.

Sebelum mencetak angka, ada tambahan perulangan `for` yang mencetak sejumlah spasi kosong terlebih dahulu, dengan jumlah `(n - i) * 2`. Artinya, semakin ke bawah baris yang dicetak (nilai `i` semakin kecil), semakin banyak spasi yang ditambahkan di depan, sehingga posisi angka bergeser ke kanan dan membentuk pola kerucut yang rata tengah, bukan rata kiri.

Setelah spasi dicetak, barulah dijalankan perulangan yang sama seperti sebelumnya: angka menurun dari `i` sampai 1 di sisi kiri, tanda `*` di tengah, lalu angka menaik dari 1 sampai `i` di sisi kanan sebagai cerminannya. Karena `i` semakin mengecil di setiap baris, jumlah angka yang dicetak pun semakin sedikit, sampai akhirnya saat `i=0` hanya tersisa tanda `*` di posisi paling tengah. Contohnya untuk `n=3`, hasilnya membentuk kerucut yang mengecil dan bergeser ke kanan setiap baris: `3 2 1 * 1 2 3`, lalu `  2 1 * 1 2`, lalu `    1 * 1`, dan terakhir `      *`.

## Kesimpulan

...

## Referensi

[1] ...
<br>[2] ...
<br>...