# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahasa C++ (Bagian Pertama)</h1>

<p align="center">Hassan Donny Darmawan - 109082500030</p>

## Dasar Teori

Bagian ini membahas konsep dasar yang digunakan dalam praktikum, mulai dari *array*, *pointer* dan alamat memori, hingga fungsi, prosedur, dan cara melewatkan parameter dalam bahasa C++.

---

### A. Array<br/>

Sub-bagian ini membahas cara menyimpan kumpulan data bertipe sama dalam satu nama variabel.

#### 1. Array Satu Dimensi

*Array* satu dimensi adalah kumpulan data bertipe sama yang berada dalam satu larik dan diakses menggunakan indeks, dengan format deklarasi `tipe_data nama_var[ukuran];` (mis. `int nilai[10];`). Elemen pertama memiliki indeks 0, sehingga *array* dengan 5 elemen memiliki indeks terakhir 4.

#### 2. Array Dua Dimensi

*Array* dua dimensi berbentuk seperti tabel dan menggunakan dua indeks (baris dan kolom), dengan deklarasi `tipe_data nama_var[baris][kolom];` (mis. `int data_nilai[4][3];`). Cara akses, inisialisasi, dan penampilan datanya sama dengan *array* satu dimensi, hanya saja indeks yang digunakan ada dua.

#### 3. Array Berdimensi Banyak

*Array* berdimensi banyak adalah *array* dengan lebih dari dua indeks, dideklarasikan dengan `tipe_data nama_var[ukuran1][ukuran2]...[ukuranN];` (mis. `int data_rumit[4][6][6];`), di mana jumlah indeks menyatakan jumlah dimensinya.

### B. Pointer<br/>

Sub-bagian ini membahas cara program mengakses data melalui alamat memori.

#### 1. Data dan Memori

Semua data program disimpan di memori (RAM) yang dapat digambarkan sebagai *array* satu dimensi berukuran sangat besar, dengan setiap sel memiliki *address* unik. Alamat memori suatu variabel dapat diketahui dengan operator `&` di depan nama variabel (mis. `&a`).

#### 2. Pointer dan Alamat

*Pointer* adalah variabel yang menyimpan alamat memori variabel lain, dideklarasikan dengan `tipe *nama_variabel;` dan diisi dengan alamat variabel tujuan (mis. `p_int = &j;`). Nilai variabel yang ditunjuk diakses dengan operator `*` (*dereference*), dan karena *pointer* juga sebuah variabel, ia menempati memori dan memiliki alamatnya sendiri.

#### 3. Pointer dan Array

*Array* dan *pointer* saling berhubungan erat, sebab nama *array* merujuk ke alamat elemen pertamanya. Jika `pa = &a[0];`, maka `pa + i` adalah alamat `a[i]` dan `*(pa + i)` adalah isi elemen `a[i]`.

#### 4. Pointer dan String

*String* pada C++ adalah *array* karakter yang diakhiri karakter *null* (`'\0'`), sehingga panjang penyimpanannya adalah jumlah karakter ditambah satu. `char amessage[] = "now is the time";` membentuk *array* yang isinya dapat diubah, sedangkan `char *pmessage = "now is the time";` membentuk *pointer* ke konstanta *string* yang hasilnya tidak terdefinisi jika isinya diubah.

### C. Fungsi dan Prosedur<br/>

Sub-bagian ini membahas cara membagi program menjadi blok-blok kode yang melakukan tugas tertentu.

#### 1. Fungsi

Fungsi adalah blok kode yang menerima masukan berupa parameter, mengolahnya, dan mengembalikan sebuah nilai balik, dengan bentuk umum `tipe_keluaran nama_fungsi(daftar_parameter) { ... }`. Penggunaan fungsi membuat program lebih terstruktur dan mengurangi duplikasi kode.

#### 2. Prosedur

Prosedur adalah fungsi yang tidak mengembalikan nilai, sehingga dalam C++ dideklarasikan sebagai fungsi `void` dengan bentuk `void nama_prosedur(daftar_parameter) { ... }`.

#### 3. Prototipe Fungsi

Prototipe fungsi adalah deklarasi fungsi (tipe keluaran, nama, dan parameter) yang ditulis sebelum `main()` agar fungsi dapat dipanggil sebelum badan fungsinya didefinisikan.

### D. Parameter Fungsi<br/>

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

```C++
#include <iostream>
#define MAX 5
using namespace std;

int main(){
    int i,j;
    float nilai_total, rata_rata;
    float nilai[MAX];
    static int nilai_tahun[MAX][MAX]=
        { {0,2,2,0,0},
        {0,1,1,1,0},
        {0,3,3,3,0},
        {4,4,0,0,4},
        {5,0,0,0,5}
    };

    /*inisialisasi array dua dimensi */
    for (i=0; i<MAX; i++){
        cout<<"masukkan nilai ke-"<<i+1<<endl;
        cin>>nilai[i];
    }
    cout<<"\ndata nilai siswa :\n";

    /*menampilkan array satu dimensi */
    for (i=0; i<MAX; i++)
        cout<<"nilai k-"<<i+1<<"=" <<nilai[i]<<endl;
        cout<<"\n nilai tahunan : \n";

    /* menampilkan array dua dimensi */
    for(i=0; i<MAX; i++){
        for(j=0; j<MAX; j++)
            cout<<nilai_tahun[i][j];
            cout<<"\n";
    }
    return 0;
}
```


````markdown
## Penjelasan Kode

Program ini menunjukkan cara mengisi dan menampilkan *array* satu dimensi bernama `nilai` serta *array* dua dimensi bernama `nilai_tahun`. Di awal program, `#include <iostream>` dipakai untuk memuat pustaka `cin` dan `cout`, sedangkan `#define MAX 5` mendefinisikan konstanta `MAX` bernilai 5 yang menjadi ukuran *array* sekaligus batas perulangan. Baris `using namespace std;` membuat `cout`, `cin`, dan `endl` dapat ditulis tanpa awalan `std::`.

Di dalam fungsi `main()`, dideklarasikan variabel `i` dan `j` sebagai penghitung perulangan, `nilai` sebagai *array* satu dimensi berisi 5 elemen bertipe `float`, dan `nilai_tahun` sebagai *array* dua dimensi berukuran 5×5 yang langsung diisi nilai awal saat dideklarasikan. Variabel `nilai_total` dan `rata_rata` juga dideklarasikan, tetapi tidak digunakan dalam program ini.

Perulangan `for` yang pertama berjalan dari indeks 0 sampai 4. Pada setiap putaran, program menampilkan teks "masukkan nilai ke-" diikuti `i+1` agar penomoran tampil mulai dari 1, lalu membaca input dari *keyboard* dan menyimpannya ke `nilai[i]`. Setelah kelima nilai terisi, program mencetak judul "data nilai siswa", kemudian perulangan kedua menampilkan setiap elemen `nilai[i]` beserta nomor urutnya. Perulangan ini tidak memakai kurung kurawal, sehingga hanya satu baris `cout` tepat di bawahnya yang ikut berulang, sedangkan baris berikutnya yang mencetak judul "nilai tahunan" hanya dijalankan satu kali setelah perulangan selesai.

Terakhir, *array* dua dimensi ditampilkan dengan dua perulangan bersarang. Perulangan luar dengan variabel `i` menentukan baris, dan perulangan dalam dengan variabel `j` mencetak setiap kolom pada baris tersebut secara berurutan. Perintah `cout<<"\n"` diletakkan di luar perulangan dalam, sehingga program berpindah baris setelah satu baris selesai dicetak. Hasilnya berupa tabel angka 5×5 seperti `02200`, `01110`, `03330`, `44004`, dan `50005`, lalu program berakhir dengan `return 0;`.
````

### 2. ...

```C++
#include <iostream>
using namespace std;

int main(){
    int x, y; // x dan y bertipe int
    int *px; // px merupakan variabel pointer menunjuk ke variabel int

    x = 87;
    px = &x;
    y = *px;

    cout << "Alamat x= " << &x << endl;
    cout << "Isi px= " << px << endl;
    cout << "Isi X= " << x << endl;
    cout << "Nilai yang ditunjuk px= " << *px << endl;
    cout << "Nilai y= " << y << endl;
return 0;
}
```

## Penjelasan Kode
Program ini menunjukkan cara kerja *pointer*, yaitu variabel yang menyimpan alamat memori variabel lain, serta cara mengakses nilai variabel melalui *pointer* tersebut. Di awal program, `#include <iostream>` memuat pustaka `cin` dan `cout`, sedangkan `using namespace std;` membuat keduanya dapat ditulis tanpa awalan `std::`.

Di dalam fungsi `main()`, dideklarasikan dua variabel bertipe `int`, yaitu `x` dan `y`, serta sebuah variabel *pointer* `px` yang dapat menunjuk ke variabel bertipe `int`. Tanda `*` pada deklarasi `int *px;` menandakan bahwa `px` adalah *pointer*, bukan variabel biasa.

Program kemudian mengisi `x` dengan nilai 87. Pernyataan `px = &x;` membuat `px` menyimpan alamat memori dari `x`, dengan `&` sebagai operator alamat, sehingga dapat dikatakan bahwa `px` menunjuk ke `x`. Setelah itu, `y = *px;` mengambil nilai dari variabel yang ditunjuk `px` (operator `*` di sini berfungsi sebagai *dereference*) lalu menyalinnya ke `y`, sehingga `y` juga bernilai 87.

Kelima perintah `cout` menampilkan hasilnya. `&x` mencetak alamat memori `x`, dan `px` mencetak isi *pointer* yang berupa alamat yang sama dengan `&x`, sehingga kedua baris pertama akan menampilkan nilai heksadesimal yang identik (pada modul contohnya `0022FF14`, meskipun alamat sebenarnya berbeda di setiap komputer). Selanjutnya `x` mencetak nilai 87, `*px` mencetak nilai yang ditunjuk `px` yaitu 87, dan `y` juga mencetak 87. Program diakhiri dengan `return 0;`.

### 3. ...

```C++
#include <iostream>
using namespace std;
int maks3(int a, int b, int c);
int main(){
    int x,y,z;
    cout<<"masukkan nilai bilangan ke-1 =";
    cin>>x;
    cout<<"masukkan nilai bilangan ke-2 =";
    cin>>y;
    cout<<"masukkan nilai bilangan ke-3 =";
    cin>>z;
    cout<<"nilai maksimumnya adalah =" <<maks3(x,y,z);
return 0;
}

int maks3(int a, int b, int c){
    /* deklarasi variabel lokal dalam fungsi */
    int temp_max =a;
    if(b>temp_max)
        temp_max=b;
    if(c>temp_max)
        temp_max=c;
    return (temp_max);
}
```

## Penjelasan Kode

Program ini menunjukkan penggunaan fungsi dalam C++, yaitu fungsi `maks3()` yang mencari nilai terbesar dari tiga bilangan yang dimasukkan pengguna. Di awal program, `#include <iostream>` memuat pustaka `cin` dan `cout`, sedangkan `using namespace std;` membuat keduanya dapat ditulis tanpa awalan `std::`. Baris `int maks3(int a, int b, int c);` merupakan prototipe fungsi, yaitu deklarasi yang ditulis sebelum `main()` agar fungsi dapat dipanggil sebelum badan fungsinya didefinisikan.

Di dalam fungsi `main()`, dideklarasikan tiga variabel bertipe `int`, yaitu `x`, `y`, dan `z`. Program menampilkan pesan permintaan input sebanyak tiga kali, dan setiap jawaban dibaca dengan `cin` lalu disimpan ke variabel yang sesuai. Setelah itu, `maks3(x,y,z)` dipanggil pada perintah `cout` terakhir, sehingga hasil yang dikembalikan fungsi langsung ditampilkan sebagai nilai maksimum. Dalam pemanggilan ini, `x`, `y`, dan `z` adalah parameter aktual.

Badan fungsi `maks3()` menerima tiga parameter formal, yaitu `a`, `b`, dan `c`, yang masing-masing berisi salinan nilai `x`, `y`, dan `z` (*call by value*). Di dalamnya, variabel lokal `temp_max` diisi terlebih dahulu dengan nilai `a` sebagai anggapan awal bahwa `a` adalah yang terbesar. Pernyataan `if(b>temp_max)` kemudian memeriksa apakah `b` lebih besar, dan jika ya maka `temp_max` diganti dengan `b`. Pemeriksaan yang sama dilakukan untuk `c`. Setelah kedua pemeriksaan selesai, `temp_max` berisi bilangan terbesar dan nilainya dikembalikan ke `main()` melalui `return (temp_max);`. Program diakhiri dengan `return 0;`.

### 4. ...

```C++
#include <iostream>
using namespace std;

    /*prototype fungsi */
void tulis(int x);
int main(){
    int jum;
    cout << "jumlah baris kata=";
    cin >> jum;
    tulis(jum);
    return 0;
}

    /*badan prosedur*/
void tulis(int x){
    for (int i=0;i<x;i++)
        cout<<"baris ke-"<<i+1<<endl;
}
```

## Penjelasan Kode

Program ini menunjukkan penggunaan prosedur dalam C++, yaitu prosedur `tulis()` yang mencetak tulisan "baris ke-" sebanyak jumlah yang dimasukkan pengguna. Di awal program, `#include <iostream>` memuat pustaka `cin` dan `cout`, sedangkan `using namespace std;` membuat keduanya dapat ditulis tanpa awalan `std::`. Baris `void tulis(int x);` merupakan prototipe prosedur yang ditulis sebelum `main()` agar prosedur dapat dipanggil sebelum badannya didefinisikan. Kata kunci `void` menandakan bahwa prosedur ini tidak mengembalikan nilai.

Di dalam fungsi `main()`, dideklarasikan variabel `jum` bertipe `int`. Program menampilkan pesan "jumlah baris kata=", lalu membaca input dari *keyboard* dengan `cin` dan menyimpannya ke `jum`. Setelah itu, `tulis(jum)` dipanggil dengan `jum` sebagai parameter aktual. Karena `tulis()` adalah prosedur, pemanggilannya ditulis sebagai pernyataan tersendiri dan tidak ada nilai balik yang ditampung atau ditampilkan.

Pada badan prosedur `tulis()`, parameter formal `x` menerima salinan nilai `jum` (*call by value*). Perulangan `for` dengan variabel lokal `i` berjalan dari 0 sampai `x-1`, sehingga jumlah putarannya sama dengan nilai `x`. Pada setiap putaran, program mencetak "baris ke-" diikuti `i+1` agar penomoran dimulai dari 1. Sebagai contoh, jika pengguna memasukkan 3, maka output yang tampil adalah `baris ke-1`, `baris ke-2`, dan `baris ke-3`. Setelah perulangan selesai, prosedur berakhir dan kendali kembali ke `main()`, yang kemudian ditutup dengan `return 0;`.


### 5. ...

```C++
#include <iostream>
using namespace std;

void tukarValue(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void tukarPointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void tukarReference(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}   

int main() {
    int a = 5, b = 10;

    cout << "Sebelum tukarValue: a = " << a << ", b = " << b << endl;
    tukarValue(a, b);
    cout << "Setelah tukarValue: a = " << a << ", b = " << b << endl;

    cout << "Sebelum tukarPointer: a = " << a << ", b = " << b << endl;
    tukarPointer(&a, &b);
    cout << "Setelah tukarPointer: a = " << a << ", b = " << b << endl;

    cout << "Sebelum tukarReference: a = " << a << ", b = " << b << endl;
    tukarReference(a, b);
    cout << "Setelah tukarReference: a = " << a << ", b = " << b << endl;

    return 0;
}
```

## Penjelasan Kode

Program ini memanggil tiga fungsi penukar nilai, yaitu `tukarValue`, `tukarPointer`, dan `tukarReference`, lalu menampilkan nilai `a` dan `b` sebelum dan sesudah setiap pemanggilan untuk melihat pengaruhnya. Di awal program, `#include <iostream>` memuat pustaka `cout`, sedangkan `using namespace std;` membuat `cout` dan `endl` dapat ditulis tanpa awalan `std::`. Ketiga fungsi didefinisikan sebelum `main()`, sehingga prototipe fungsi tidak diperlukan.

Fungsi `tukarValue(int &x, int &y)` dan `tukarReference(int &x, int &y)` memiliki isi yang identik. Keduanya memakai tanda `&` pada parameter, sehingga `x` dan `y` menjadi nama lain dari variabel yang dikirim (*call by reference*). Pertukaran lewat variabel `temp` langsung mengubah variabel aslinya. Fungsi `tukarPointer(int *x, int *y)` menerima alamat variabel, lalu operator `*` dipakai untuk membaca dan mengubah nilai yang berada di alamat tersebut (*call by pointer*), sehingga variabel asli juga ikut berubah.

Di dalam `main()`, variabel `a` diisi 5 dan `b` diisi 10. Pemanggilan `tukarValue(a, b)` menukar nilainya menjadi `a = 10, b = 5`. Pemanggilan `tukarPointer(&a, &b)` dilakukan dengan mengirim alamat variabel memakai operator `&`, sehingga nilainya tertukar kembali menjadi `a = 5, b = 10`. Terakhir, `tukarReference(a, b)` cukup dipanggil dengan menulis variabelnya langsung, dan nilainya tertukar lagi menjadi `a = 10, b = 5`. Program diakhiri dengan `return 0;`.

Output program:

```
Sebelum tukarValue: a = 5, b = 10
Setelah tukarValue: a = 10, b = 5
Sebelum tukarPointer: a = 10, b = 5
Setelah tukarPointer: a = 5, b = 10
Sebelum tukarReference: a = 5, b = 10
Setelah tukarReference: a = 10, b = 5
```

## Unguided

### 1. 

```C++
source

```

### Output Unguided 1 :

![Screenshot Output Unguided 1_1](https://github.com/hass4ndonnydarmawan/109082500030_Hassan-Donny-Darmawan_SDT/blob/main/modul_1/output/unguided1.png)

## Penjelasan Kode


### 2. (isi dengan soal unguided 2)

```C++
source
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/hass4ndonnydarmawan/109082500030_Hassan-Donny-Darmawan_SDT/blob/main/modul_1/output/unguided2.png)

##### Output 2

![Screenshot Output Unguided 2_2](https://github.com/hass4ndonnydarmawan/109082500030_Hassan-Donny-Darmawan_SDT/blob/main/modul_1/output/unguided2_2.png)

## Penjelasan Kode


### 3. (isi dengan soal unguided 3)

```C++
source
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/hass4ndonnydarmawan/109082500030_Hassan-Donny-Darmawan_SDT/blob/main/modul_1/output/unguided3.png)

##### Output 2

![Screenshot Output Unguided 3_2](https://github.com/hass4ndonnydarmawan/109082500030_Hassan-Donny-Darmawan_SDT/blob/main/modul_1/output/unguided3_2.png)

## Penjelasan Kode


## Kesimpulan

Berdasarkan dasar teori dan seluruh contoh program yang telah dibahas, dapat disimpulkan bahwa C++ adalah bahasa pemrograman yang dibangun di atas struktur dasar berupa header, fungsi `main()`, serta pernyataan yang diakhiri titik koma. Program dalam C++ bekerja dengan memanfaatkan variabel dan tipe data (seperti `int`, `float`, `double`, dan `char`) untuk menyimpan nilai, serta fungsi `cin` dan `cout` sebagai sarana interaksi antara program dan pengguna.

Dari contoh-contoh program yang diberikan, terlihat bagaimana operator aritmatika, assignment, serta increment/decrement (`++`, `--`) memengaruhi hasil perhitungan, termasuk pentingnya memperhatikan tipe data saat melakukan pembagian agar tidak terjadi pemotongan nilai desimal (*integer division*). Struktur kondisional (`if`, `if-else`, `switch`) terbukti berguna untuk mengambil keputusan berdasarkan suatu syarat, seperti pada program perhitungan diskon dan penentuan hari kerja/libur, sedangkan struktur perulangan (`for`, `while`, `do-while`) memungkinkan suatu blok kode dieksekusi berulang kali secara efisien, seperti pada pembuatan pola *mirror* berbentuk kerucut.

Selain itu, penggunaan `struct` menunjukkan bagaimana beberapa data dengan tipe berbeda dapat dikelompokkan menjadi satu kesatuan, dan ketika dikombinasikan dengan *array*, sangat berguna untuk mengelola banyak data sekaligus, seperti data siswa. Latihan-latihan yang diberikan — mulai dari operasi aritmatika dua bilangan, konversi angka menjadi tulisan, hingga pembuatan pola *mirror* — pada dasarnya merupakan penerapan langsung dari seluruh konsep dasar tersebut, sehingga membuktikan bahwa penguasaan tipe data, operator, struktur kontrol, dan fungsi merupakan fondasi penting sebelum mempelajari struktur data yang lebih kompleks.

## Referensi

[1] Modul Praktikum Struktur Data — Modul 2: Pengenalan Bahasa C++ (Bagian Kedua), Fakultas Informatika, Telkom University.
<br>[2] Stroustrup, B. (2013). *The C++ Programming Language* (4th ed.). Addison-Wesley.
<br>[3] cplusplus.com. *C++ Language Tutorial*. https://www.cplusplus.com/doc/tutorial/
<br>[4] cppreference.com. *Pointer declaration*. https://en.cppreference.com/w/cpp/language/pointer