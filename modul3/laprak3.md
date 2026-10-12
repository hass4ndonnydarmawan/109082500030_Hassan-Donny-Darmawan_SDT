# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>

<p align="center">Hassan Donny Darmawan - 109082500030</p>

## Dasar Teori
 
Bagian ini membahas konsep dasar yang digunakan dalam praktikum, mulai dari *Abstract Data Type* (ADT), *array*, dan *pointer* hingga fungsi, prosedur, dan cara melewatkan parameter dalam bahasa C++.
 
---
 
### A. Abstract Data Type (ADT)<br/>
 
Sub-bagian ini membahas cara mendefinisikan sebuah tipe data beserta operasi-operasi dasarnya.
 
#### 1. Pengertian ADT
 
ADT adalah sebuah TYPE beserta sekumpulan PRIMITIF (operasi dasar) terhadap TYPE tersebut. ADT yang lengkap juga menyertakan definisi invarian dari TYPE dan aksioma yang berlaku. ADT bersifat statik, dan definisi type-nya dapat mengandung ADT lain (mis. ADT waktu yang terdiri dari ADT JAM dan ADT DATE). Dalam C++, TYPE diterjemahkan menjadi `struct`, sedangkan PRIMITIF diterjemahkan menjadi fungsi atau prosedur.
 
#### 2. Struct
 
*Struct* adalah tipe bentukan yang mengelompokkan beberapa data (*field*) dengan tipe yang bisa berbeda ke dalam satu nama, dengan format `struct nama { tipe field; ... };` (mis. `struct mahasiswa { char nim[10]; int nilai1, nilai2; };`). Setiap *field* diakses dengan operator titik (mis. `mhs.nilai1`).
 
#### 3. Primitif ADT
 
Primitif dikelompokkan menjadi beberapa jenis:
- Konstruktor/kreator, yang membentuk nilai *type* dan biasanya diawali `Make` atau `create`.
- *Selector*, yang mengakses komponen dan biasanya diawali `Get`.
- Prosedur pengubah nilai komponen, yang biasanya diawali `Set`.
- Validator komponen, yang menguji apakah nilai dapat membentuk tipe sesuai batasan.
- Destruktor/dealokator, yang "menghancurkan" nilai objek beserta memorinya.
- Baca/tulis untuk interaksi dengan perangkat *input/output*.
- Operator relasional dan aritmatika terhadap tipe tersebut.
- Konversi dari tipe tersebut ke tipe dasar dan sebaliknya.
#### 4. Struktur File ADT
 
ADT diimplementasikan menjadi dua modul utama dan satu modul *driver*. File *header* (`.h`) berisi spesifikasi *type* dan *header* fungsi/prosedur, dan dilengkapi `#ifndef`, `#define`, `#endif` agar tidak ter-*include* berulang. File *body* (`.cpp`) berisi realisasi dari primitif, yang sebaiknya memanfaatkan *selector* dan konstruktor. File `main.cpp` berperan sebagai *driver* yang menguji ADT dengan memanggil primitif-primitifnya.
 
### B. Array<br/>
 
Sub-bagian ini membahas cara menyimpan kumpulan data bertipe sama dalam satu nama variabel.
 
#### 1. Array Satu Dimensi
 
*Array* satu dimensi adalah kumpulan data bertipe sama yang berada dalam satu larik dan diakses menggunakan indeks, dengan format deklarasi `tipe_data nama_var[ukuran];` (mis. `int nilai[10];`). Elemen pertama memiliki indeks 0, sehingga *array* dengan 5 elemen memiliki indeks terakhir 4.
 
#### 2. Array Dua Dimensi
 
*Array* dua dimensi berbentuk seperti tabel dan menggunakan dua indeks (baris dan kolom), dengan deklarasi `tipe_data nama_var[baris][kolom];` (mis. `int data[3][3];`). Cara akses, inisialisasi, dan penampilan datanya sama dengan *array* satu dimensi, hanya saja indeks yang digunakan ada dua.
 
#### 3. Array dari Struct
 
*Array* juga dapat berisi elemen bertipe `struct`, sehingga satu elemen menyimpan satu kumpulan data lengkap (mis. `mahasiswa dataMhs[10];`). Satu *field* pada elemen ke-i diakses dengan `dataMhs[i].nama`.
 
### C. Pointer<br/>
 
Sub-bagian ini membahas cara program mengakses data melalui alamat memori.
 
#### 1. Data dan Memori
 
Semua data program disimpan di memori (RAM) yang dapat digambarkan sebagai *array* satu dimensi berukuran sangat besar, dengan setiap sel memiliki *address* unik. Alamat memori suatu variabel dapat diketahui dengan operator `&` di depan nama variabel (mis. `&a`).
 
#### 2. Pointer dan Alamat
 
*Pointer* adalah variabel yang menyimpan alamat memori variabel lain, dideklarasikan dengan `tipe *nama_variabel;` dan diisi dengan alamat variabel tujuan (mis. `p_int = &j;`). Nilai variabel yang ditunjuk diakses dengan operator `*` (*dereference*), dan karena *pointer* juga sebuah variabel, ia menempati memori dan memiliki alamatnya sendiri.
 
#### 3. Pointer dan Array
 
*Array* dan *pointer* saling berhubungan erat, sebab nama *array* merujuk ke alamat elemen pertamanya. Jika `pa = &a[0];`, maka `pa + i` adalah alamat `a[i]` dan `*(pa + i)` adalah isi elemen `a[i]`.
 
### D. Fungsi dan Prosedur<br/>
 
Sub-bagian ini membahas cara membagi program menjadi blok-blok kode yang melakukan tugas tertentu.
 
#### 1. Fungsi
 
Fungsi adalah blok kode yang menerima masukan berupa parameter, mengolahnya, dan mengembalikan sebuah nilai balik, dengan bentuk umum `tipe_keluaran nama_fungsi(daftar_parameter) { ... }`. Penggunaan fungsi membuat program lebih terstruktur dan mengurangi duplikasi kode.
 
#### 2. Prosedur
 
Prosedur adalah fungsi yang tidak mengembalikan nilai, sehingga dalam C++ dideklarasikan sebagai fungsi `void` dengan bentuk `void nama_prosedur(daftar_parameter) { ... }`.
 
#### 3. Prototipe Fungsi
 
Prototipe fungsi adalah deklarasi fungsi (tipe keluaran, nama, dan parameter) yang ditulis sebelum `main()` agar fungsi dapat dipanggil sebelum badan fungsinya didefinisikan. Pada ADT, prototipe ini ditempatkan di file *header* (`.h`), sedangkan badan fungsinya ada di file `.cpp`.
 
### E. Parameter Fungsi<br/>
 
Sub-bagian ini membahas jenis parameter dan cara data dilewatkan ke dalam fungsi.
 
#### 1. Parameter Formal dan Parameter Aktual
 
Parameter formal adalah variabel pada daftar parameter saat fungsi didefinisikan, sedangkan parameter aktual adalah nilai atau ekspresi yang dipakai saat fungsi dipanggil, dan dapat berupa variabel, konstanta, maupun ungkapan.
 
#### 2. Pemanggilan dengan Nilai (*Call by Value*)
 
Pada *call by value*, nilai parameter aktual disalin ke parameter formal sehingga perubahan di dalam fungsi tidak memengaruhi variabel aslinya (mis. `void tukar(int x, int y)`).
 
#### 3. Pemanggilan dengan Pointer (*Call by Pointer*)
 
Pada *call by pointer*, yang dilewatkan adalah alamat variabel menggunakan operator `&` saat pemanggilan (mis. `tukar(&a, &b)`) dan diterima oleh parameter *pointer* (mis. `void tukar(int *x, int *y)`), sehingga nilai variabel di luar fungsi dapat berubah.
 
#### 4. Pemanggilan dengan Referensi (*Call by Reference*)
 
Pada *call by reference*, parameter formal dideklarasikan dengan operator `&` (mis. `void tukar(int &x, int &y)`) sehingga menjadi nama lain dari variabel aktual. Variabel di luar fungsi ikut berubah, dan pemanggilannya cukup `tukar(a, b)` tanpa operator tambahan.
---

## Guided

### 1. ...

## buku.h
```C++
# ifndef BUKU_H
#define BUKU_H
#include <iostream>

using namespace std;
struct buku {
    string judul;
    int halaman;
    string penulis;
};

void editIsi (string judul, int halaman, string penulis, buku &buku);
void tampilanIsiBuku (buku buku);
bool checkPenulis(buku buku);

#endif
```
## buku.cpp
```C++
#include "buku.h"

void editIsi (string judul, int halaman, string penulis, buku &buku){
    buku.judul = judul;
    buku.halaman = halaman;
    buku.penulis = penulis;
}

void tampilanIsiBuku(buku buku){
    cout << "Judul Buku : " << buku.judul << endl;
    cout << "Halaman Buku : " << buku.halaman << endl;
    cout << "penulis buku : " << buku.penulis << endl;
}

bool checkPenulis(buku buku)
{
    return buku.penulis == "";
}
```
## main.cpp
```C++
#include <iostream>
#include "buku.h"

using namespace std;

int main (){

    buku novel;
    string judul, penulis;
    int halaman;

    cout << "masukan judul buku : ";
    cin >> judul;
    cout << "masukan halaman buku : ";
    cin >> halaman;
    cout << "masukan penulis buku : ";
    cin >> penulis;

    editIsi(judul, halaman, penulis, novel);
    tampilanIsiBuku(novel);
    
    cout << checkPenulis(novel);

    return 0;
}
```
##### Output 1

![Screenshot Output guided 1](https://github.com/hass4ndonnydarmawan/109082500030_Hassan-Donny-Darmawan_SDT/blob/main/modul3/output/g1.png)

## Penjelasan Kode
Program ini menunjukkan cara menyimpan data sebuah buku ke dalam `struct` dan mengelolanya dengan fungsi, dengan penerapan konsep ADT yang dipisah menjadi tiga file. File `buku.h` berisi `struct buku` dengan tiga *field*, yaitu `judul` dan `penulis` bertipe `string` serta `halaman` bertipe `int`, ditambah deklarasi tiga fungsi. Baris `#ifndef BUKU_H`, `#define BUKU_H`, dan `#endif` mencegah file *header* ter-*include* berulang kali, sedangkan `#include <iostream>` memuat pustaka `cin` dan `cout`. Baris `using namespace std;` membuat `cout`, `cin`, `endl`, dan `string` dapat ditulis tanpa awalan `std::`.

File `buku.cpp` berisi isi dari ketiga fungsi tersebut. Prosedur `editIsi()` menerima `judul`, `halaman`, dan `penulis`, lalu memasukkannya ke *field* yang sesuai pada variabel `buku`. Parameter `buku` pada `editIsi()` memakai tanda `&` (*call by reference*) agar perubahan isinya tersimpan pada variabel aslinya di `main()`. Prosedur `tampilanIsiBuku()` mencetak judul, jumlah halaman, dan penulis buku, dan parameternya cukup dikirim dengan nilai karena isinya hanya dibaca. Fungsi `checkPenulis()` mengembalikan nilai `bool` hasil perbandingan `buku.penulis == ""`, sehingga hasilnya `true` (1) jika nama penulis kosong dan `false` (0) jika sudah terisi.

Di dalam fungsi `main()`, dideklarasikan `novel` bertipe `buku`, variabel `judul` dan `penulis` bertipe `string`, serta `halaman` bertipe `int` untuk menampung data dari *keyboard*. Program meminta pengguna memasukkan judul, jumlah halaman, dan penulis, lalu membacanya dengan `cin >>`. Data tersebut dikirim ke `editIsi()` untuk disimpan ke `novel`, kemudian `tampilanIsiBuku()` dipanggil untuk menampilkannya.

Baris terakhir, `cout << checkPenulis(novel);`, mencetak hasil pengecekan penulis berupa angka 0 atau 1. Sebagai contoh, jika penulis diisi "tereliye", hasilnya 0 karena penulis tidak kosong. Karena input dibaca dengan `cin >>` yang tidak menerima string kosong, hasil pengecekan di program ini selalu 0, dan judul maupun penulis hanya bisa berupa satu kata. Program berakhir dengan `return 0;`.


## Unguided

### 1. Program Data Mahasiswa Menggunakan Konsep ADT Sederhana

### mahasiswa.h
```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H
#include <iostream>
#include <string>

using namespace std;

const int MAX_MHS = 10;

struct mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas);
void editIsi(string nama, string nim, float uts, float uas, float tugas, mahasiswa &mhs);
void tampilanIsiMahasiswa(mahasiswa mhs);

#endif
```
### mahasiswa.cpp
```C++
#include "mahasiswa.h"

float hitungNilaiAkhir(float uts, float uas, float tugas){
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

void editIsi(string nama, string nim, float uts, float uas, float tugas, mahasiswa &mhs){
    mhs.nama = nama;
    mhs.nim = nim;
    mhs.uts = uts;
    mhs.uas = uas;
    mhs.tugas = tugas;
    mhs.nilaiAkhir = hitungNilaiAkhir(uts, uas, tugas);
}

void tampilanIsiMahasiswa(mahasiswa mhs){
    cout << "Nama Mahasiswa : " << mhs.nama << endl;
    cout << "NIM : " << mhs.nim << endl;
    cout << "UTS : " << mhs.uts << endl;
    cout << "UAS : " << mhs.uas << endl;
    cout << "Tugas : " << mhs.tugas << endl;
    cout << "Nilai Akhir : " << mhs.nilaiAkhir << endl;
}
```
### main.cpp
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main (){

    mahasiswa dataMhs[MAX_MHS];
    string nama, nim;
    float uts, uas, tugas;
    int jumlah;

    cout << "masukan jumlah mahasiswa : ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++){
        cout << "data mahasiswa ke-" << i + 1 << endl;
        cout << "masukan nama : ";
        cin >> nama;
        cout << "masukan nim : ";
        cin >> nim;
        cout << "masukan uts : ";
        cin >> uts;
        cout << "masukan uas : ";
        cin >> uas;
        cout << "masukan tugas : ";
        cin >> tugas;

        editIsi(nama, nim, uts, uas, tugas, dataMhs[i]);
    }

    for (int i = 0; i < jumlah; i++){
        tampilanIsiMahasiswa(dataMhs[i]);
    }

    return 0;
}
```
##### Output 1

![Screenshot Output unguided 1_1](https://github.com/hass4ndonnydarmawan/109082500030_Hassan-Donny-Darmawan_SDT/blob/main/modul3/output/s1_1.png)

##### Output 2

![Screenshot Output unguided 1_2](https://github.com/hass4ndonnydarmawan/109082500030_Hassan-Donny-Darmawan_SDT/blob/main/modul3/output/s1_2.png)

## Penjelasan Kode

Program ini menunjukkan cara menyimpan data beberapa mahasiswa ke dalam sebuah *array* bertipe `struct` bernama `dataMhs`, dengan nilai akhir dihitung oleh sebuah fungsi. Program dibagi menjadi tiga file sesuai konsep ADT. File `mahasiswa.h` berisi `struct mahasiswa` dengan *field* `nama`, `nim`, `uts`, `uas`, `tugas`, dan `nilaiAkhir`, konstanta `MAX_MHS` bernilai 10 sebagai batas jumlah data, serta deklarasi fungsi. Baris `#ifndef`, `#define`, dan `#endif` mencegah file *header* ter-*include* berulang kali, sedangkan `#include <iostream>` dan `#include <string>` memuat pustaka untuk `cin`, `cout`, dan tipe `string`. Baris `using namespace std;` membuat pustaka tersebut dapat dipakai tanpa awalan `std::`.

File `mahasiswa.cpp` berisi isi dari tiga fungsi. Fungsi `hitungNilaiAkhir()` menerima nilai `uts`, `uas`, dan `tugas`, lalu mengembalikan hasil rumus `0.3 * uts + 0.4 * uas + 0.3 * tugas`. Prosedur `editIsi()` mengisi semua *field* pada sebuah data mahasiswa dari parameter yang diterima, dan memanggil `hitungNilaiAkhir()` untuk mengisi `nilaiAkhir` secara otomatis. Parameter `mhs` pada `editIsi()` memakai tanda `&` (*call by reference*) agar perubahan isinya tersimpan pada variabel aslinya. Prosedur `tampilanIsiMahasiswa()` hanya mencetak isi satu data mahasiswa, sehingga parameternya cukup dikirim dengan nilai.

Di dalam fungsi `main()`, dideklarasikan `dataMhs` sebagai *array* berukuran `MAX_MHS`, variabel `nama` dan `nim` bertipe `string`, variabel `uts`, `uas`, dan `tugas` bertipe `float`, serta `jumlah` untuk menyimpan banyaknya mahasiswa yang akan diinput. Program meminta nilai `jumlah` terlebih dahulu, kemudian perulangan `for` yang pertama berjalan dari indeks 0 sampai `jumlah - 1`. Pada setiap putaran, program menampilkan teks "data mahasiswa ke-" diikuti `i + 1` agar penomoran dimulai dari 1, membaca `nama`, `nim`, `uts`, `uas`, dan `tugas` dari *keyboard*, lalu memanggil `editIsi()` untuk menyimpannya ke `dataMhs[i]`.

````

````
### 2. Program Adt pelajaran

### pelajaran.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <iostream>
#include <string>

using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```
### pelajaran.cpp
```C++
#include "pelajaran.h"

pelajaran create_pelajaran(string namapel, string kodepel){
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel){
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```
### main.cpp
```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main(){
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
##### Output 1

![Screenshot Output unguided 1_1](https://github.com/hass4ndonnydarmawan/109082500030_Hassan-Donny-Darmawan_SDT/blob/main/modul3/output/s2.png)

## Penjelasan Kode

Program ini menunjukkan penerapan konsep ADT untuk menyimpan data sebuah mata pelajaran, dengan kode yang dipisah menjadi tiga file. File `pelajaran.h` berisi `struct pelajaran` dengan dua *field* bertipe `string`, yaitu `namaMapel` dan `kodeMapel`, serta deklarasi fungsi `create_pelajaran()` dan `tampil_pelajaran()`. Baris `#ifndef PELAJARAN_H`, `#define PELAJARAN_H`, dan `#endif` mencegah file *header* ter-*include* berulang kali, sedangkan `#include <iostream>` dan `#include <string>` memuat pustaka untuk `cout` dan tipe `string`. Baris `using namespace std;` membuat pustaka tersebut dapat dipakai tanpa awalan `std::`.

File `pelajaran.cpp` berisi isi dari kedua fungsi. Fungsi `create_pelajaran()` berperan sebagai konstruktor, yaitu menerima `namapel` dan `kodepel`, membuat variabel `pel` bertipe `pelajaran`, mengisi kedua *field*-nya dari parameter, lalu mengembalikan `pel` sebagai hasil. Dengan cara ini, setiap variabel bertipe `pelajaran` dibentuk melalui satu fungsi yang sama. Prosedur `tampil_pelajaran()` menerima sebuah `pelajaran` dan mencetak "nama pelajaran : " diikuti nama mapel, lalu "nilai : " diikuti kode mapel. Parameternya cukup dikirim dengan nilai karena isinya hanya dibaca dan tidak diubah.

Di dalam fungsi `main()`, dideklarasikan variabel `namapel` yang langsung diisi "Struktur Data" dan `kodepel` yang diisi "STD". Kedua variabel itu dikirim ke `create_pelajaran()`, dan hasilnya disimpan ke variabel `pel` bertipe `pelajaran`. Kemudian `tampil_pelajaran(pel)` dipanggil untuk menampilkan isinya, sehingga program mencetak "nama pelajaran : Struktur Data" dan "nilai : STD". Label "nilai" dipakai untuk menampilkan kode mapel karena mengikuti contoh *output* pada soal. Berbeda dengan program lain, program ini tidak meminta *input* dari *keyboard* karena datanya sudah ditentukan di dalam `main()`. Program berakhir dengan `return 0;`.

### 2. Program tukar isi array 2 dimensi

### tukar.h
```C++
#ifndef TUKAR_H
#define TUKAR_H
#include <iostream>

using namespace std;

void tampilArray(int arr[3][3]);
void tukarArray(int arr1[3][3], int arr2[3][3], int baris, int kolom);
void tukarPointer(int *p1, int *p2);

#endif
```
### tukar.cpp
```C++
#include "tukar.h"

void tampilArray(int arr[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(int arr1[3][3], int arr2[3][3], int baris, int kolom){
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
```
### main.cpp
```C++
#include <iostream>
#include "tukar.h"

using namespace std;

int main (){

    int arrayA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arrayB[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int a = 10, b = 20;
    int *ptr1 = &a;
    int *ptr2 = &b;
    int baris, kolom;

    cout << "Array A : " << endl;
    tampilArray(arrayA);
    cout << "Array B : " << endl;
    tampilArray(arrayB);

    cout << "masukan baris (0-2) : ";
    cin >> baris;
    cout << "masukan kolom (0-2) : ";
    cin >> kolom;

    tukarArray(arrayA, arrayB, baris, kolom);

    cout << "Array A setelah ditukar : " << endl;
    tampilArray(arrayA);
    cout << "Array B setelah ditukar : " << endl;
    tampilArray(arrayB);

    cout << "isi variabel sebelum ditukar : " << *ptr1 << " dan " << *ptr2 << endl;
    tukarPointer(ptr1, ptr2);
    cout << "isi variabel setelah ditukar : " << *ptr1 << " dan " << *ptr2 << endl;

    return 0;
}
```
##### Output 1

![Screenshot Output unguided 1_1](https://github.com/hass4ndonnydarmawan/109082500030_Hassan-Donny-Darmawan_SDT/blob/main/modul3/output/s3_1.png)

##### Output 2

![Screenshot Output unguided 1_2](https://github.com/hass4ndonnydarmawan/109082500030_Hassan-Donny-Darmawan_SDT/blob/main/modul3/output/s3_2.png)

## Penjelasan Kode

Program ini menunjukkan cara menampilkan *array* dua dimensi, menukar isi dua *array* pada posisi tertentu, dan menukar isi variabel melalui *pointer*. Kode dipisah menjadi tiga file. File `tukar.h` berisi deklarasi tiga fungsi, yaitu `tampilArray()`, `tukarArray()`, dan `tukarPointer()`. Baris `#ifndef TUKAR_H`, `#define TUKAR_H`, dan `#endif` mencegah file *header* ter-*include* berulang kali, sedangkan `#include <iostream>` memuat pustaka `cin` dan `cout`. Baris `using namespace std;` membuat `cout`, `cin`, dan `endl` dapat ditulis tanpa awalan `std::`.

File `tukar.cpp` berisi isi dari ketiga fungsi tersebut. Prosedur `tampilArray()` menerima *array* berukuran 3×3 lalu menampilkannya dengan dua perulangan `for` bersarang. Perulangan luar dengan variabel `i` menentukan baris, dan perulangan dalam dengan variabel `j` mencetak setiap kolom pada baris tersebut, sedangkan `cout << endl` di luar perulangan dalam membuat program berpindah baris setelah satu baris selesai dicetak. Prosedur `tukarArray()` menerima dua *array* beserta `baris` dan `kolom`, lalu menukar `arr1[baris][kolom]` dengan `arr2[baris][kolom]` memakai variabel sementara `temp`. Variabel `temp` diperlukan agar nilai pertama tidak hilang saat ditimpa nilai kedua. Perubahan pada *array* tersimpan di `main()` karena *array* yang dikirim ke fungsi selalu diteruskan sebagai alamat, bukan salinan.

Prosedur `tukarPointer()` menerima dua *pointer* integer, `p1` dan `p2`. Nilai yang ditunjuk `p1` disimpan ke `temp` dengan `*p1`, lalu isi `*p1` diganti dengan `*p2`, dan `*p2` diisi dengan nilai `temp`. Tanda `*` (*dereference*) dipakai agar yang berubah adalah isi variabel yang ditunjuk, bukan alamat yang disimpan *pointer*. Cara ini disebut *call by pointer*, sehingga nilai variabel di luar fungsi ikut berubah.

Di dalam fungsi `main()`, dideklarasikan dua *array* 3×3 yang langsung diisi nilai awal, yaitu `arrayA` berisi angka 1 sampai 9 dan `arrayB` berisi angka 9 sampai 1. Dideklarasikan juga variabel `a` bernilai 10 dan `b` bernilai 20, serta dua *pointer* `ptr1` dan `ptr2` yang diisi alamat `a` dan `b` dengan operator `&`. Variabel `baris` dan `kolom` dipakai untuk menampung posisi yang diinput pengguna. Program menampilkan kedua *array* terlebih dahulu, lalu meminta `baris` dan `kolom`, kemudian memanggil `tukarArray()` dan menampilkan kedua *array* kembali. Sebagai contoh, jika diinput baris 1 dan kolom 2, elemen `arrayA[1][2]` yang bernilai 6 bertukar dengan `arrayB[1][2]` yang bernilai 4.

Pada bagian terakhir, program mencetak `*ptr1` dan `*ptr2` untuk menampilkan isi variabel yang ditunjuk, yaitu 10 dan 20. Setelah `tukarPointer(ptr1, ptr2)` dipanggil, isinya bertukar sehingga yang tercetak menjadi 20 dan 10. Program tidak memeriksa apakah `baris` dan `kolom` berada pada rentang 0 sampai 2, sehingga input di luar rentang tersebut dapat menyebabkan error. Program berakhir dengan `return 0;`.

## Kesimpulan

Berdasarkan Modul 3 dan latihan soal yang dikerjakan, dapat disimpulkan bahwa *Abstract Data Type* (ADT), *array*, *pointer*, serta fungsi dan prosedur adalah dasar penting dalam pemrograman C++ karena membantu program menjadi lebih terstruktur, rapi, dan mudah dikembangkan.

ADT adalah sebuah *type* beserta sekumpulan primitif (operasi dasar) terhadap *type* tersebut. Dalam C++, *type* diterjemahkan menjadi `struct`, sedangkan primitif diterjemahkan menjadi fungsi atau prosedur. Penerapannya memisahkan kode menjadi tiga file, yaitu file *header* (`.h`) yang berisi `struct` dan deklarasi fungsi, file `.cpp` yang berisi isi fungsi, dan `main.cpp` sebagai *driver* yang menguji ADT. Pada soal 2, ADT `pelajaran` dibuat dengan fungsi `create_pelajaran()` sebagai konstruktor yang membentuk nilai bertipe `pelajaran` dan prosedur `tampil_pelajaran()` untuk menampilkannya. Pada soal 1, ADT `mahasiswa` dibuat dengan cara yang sama, dengan fungsi `hitungNilaiAkhir()` yang menghitung nilai akhir dari rumus `0.3*uts + 0.4*uas + 0.3*tugas`. Dengan pemisahan ini, program menjadi lebih terstruktur dan bagian yang sama dapat dipakai ulang tanpa menulis ulang kode.

*Array* adalah kumpulan data bertipe sama yang disimpan berurutan di memori dan diakses lewat indeks yang dimulai dari 0. Pada soal 1, *array* dipakai untuk menyimpan hingga 10 data mahasiswa, di mana setiap elemennya bertipe `struct` sehingga satu elemen menyimpan satu data lengkap. Pada soal 3, *array* dua dimensi berukuran 3x3 menyerupai tabel dengan indeks baris dan kolom, dan ditampilkan dengan perulangan `for` bersarang. Perulangan luar menentukan baris, sedangkan perulangan dalam mencetak setiap kolom pada baris tersebut.

*Pointer* adalah variabel yang menyimpan alamat memori variabel lain. Operator `&` dipakai untuk mengambil alamat suatu variabel, sedangkan operator `*` dipakai untuk mengakses nilai pada alamat yang ditunjuk. Pada soal 3, dua *pointer* integer digunakan untuk menunjuk dua variabel, lalu isi kedua variabel tersebut ditukar lewat `*p1` dan `*p2` menggunakan variabel sementara agar salah satu nilai tidak hilang. *Pointer* juga berhubungan erat dengan *array*, karena nama *array* pada dasarnya menunjuk ke alamat elemen pertamanya. Karena itu, *array* yang dikirim ke fungsi tidak disalin, sehingga perubahan di dalam fungsi, seperti pada `tukarArray()`, ikut mengubah *array* aslinya.

Fungsi adalah blok kode yang mengembalikan nilai, sedangkan prosedur (`void`) adalah blok kode yang tidak mengembalikan nilai. Pada soal 1 dan 2, `hitungNilaiAkhir()` dan `create_pelajaran()` dibuat sebagai fungsi karena menghasilkan satu nilai, sedangkan `tampilanIsiMahasiswa()` dan `tampil_pelajaran()` dibuat sebagai prosedur karena hanya menampilkan data.

Ada tiga cara melewatkan parameter. Pada *call by value*, nilai parameter aktual disalin ke parameter formal sehingga variabel asli tidak berubah, seperti pada `tampil_pelajaran()` yang hanya membaca data. Pada *call by pointer*, yang dikirim adalah alamat variabel dan diterima oleh parameter *pointer* (`int *x`), sehingga nilai variabel asli dapat diubah lewat operator `*`, seperti pada `tukarPointer()`. Pada *call by reference*, parameter formal dideklarasikan dengan `&` dan menjadi nama lain dari variabel asli, sehingga perubahannya langsung berlaku tanpa operator tambahan saat pemanggilan, seperti pada `editIsi()` yang mengisi data mahasiswa.

Dengan mengerjakan ketiga soal ini, kita memahami bahwa ADT membantu mengelompokkan data beserta operasinya dalam satu kesatuan yang rapi, dan pemilihan antara fungsi dan prosedur serta cara melewatkan parameter harus disesuaikan dengan kebutuhan program. Fungsi dipakai jika hanya perlu satu nilai balik, sedangkan *pointer* atau *reference* dipakai jika nilai variabel asli perlu diubah.

## Referensi

[1] Modul Praktikum Struktur Data — Modul 3: Abstract Data Type (ADT), Fakultas Informatika, Telkom University.
<br>[2] Stroustrup, B. (2013). *The C++ Programming Language* (4th ed.). Addison-Wesley.
<br>[3] cplusplus.com. *Data Structures (struct)*. https://cplusplus.com/doc/tutorial/structures/
<br>[4] cplusplus.com. *Arrays*. https://cplusplus.com/doc/tutorial/arrays/
<br>[5] cplusplus.com. *Pointers*. https://cplusplus.com/doc/tutorial/pointers/
<br>[6] cplusplus.com. *Functions*. https://cplusplus.com/doc/tutorial/functions/