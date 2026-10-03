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

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3.

```C++
#include <iostream>
using namespace std;

void inputMatriks(int m[3][3], char nama) {
    cout << "Masukkan matriks " << nama << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nama << "[" << i << "][" << j << "] = ";
            cin >> m[i][j];
        }
    }
}

void tampilMatriks(int m[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

void tambah(int a[3][3], int b[3][3], int c[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            c[i][j] = a[i][j] + b[i][j];
}

void kurang(int a[3][3], int b[3][3], int c[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            c[i][j] = a[i][j] - b[i][j];
}

void kali(int a[3][3], int b[3][3], int c[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 3; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
}

int main() {
    int A[3][3], B[3][3], C[3][3];
    int pilih;

    inputMatriks(A, 'A');
    inputMatriks(B, 'B');

    do {
        cout << "\n--- Menu Matriks ---" << endl;
        cout << "1. Penjumlahan" << endl;
        cout << "2. Pengurangan" << endl;
        cout << "3. Perkalian" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            tambah(A, B, C);
            cout << "Hasil A + B:" << endl;
            tampilMatriks(C);
        } else if (pilih == 2) {
            kurang(A, B, C);
            cout << "Hasil A - B:" << endl;
            tampilMatriks(C);
        } else if (pilih == 3) {
            kali(A, B, C);
            cout << "Hasil A x B:" << endl;
            tampilMatriks(C);
        }
    } while (pilih != 0);

    return 0;
}

```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/hass4ndonnydarmawan/109082500030_Hassan-Donny-Darmawan_SDT/blob/main/modul_2/output/1.1.png)

##### Output 2

![Screenshot Output Unguided 1_1](https://github.com/hass4ndonnydarmawan/109082500030_Hassan-Donny-Darmawan_SDT/blob/main/modul_2/output/1.2.png)

## Penjelasan Kode

Program ini menunjukkan penggunaan prosedur dan array dua dimensi dalam C++, yaitu operasi penjumlahan, pengurangan, dan perkalian pada dua matriks berukuran 3x3. Di awal program, `#include <iostream>` memuat pustaka `cin` dan `cout`, sedangkan `using namespace std;` membuat keduanya dapat ditulis tanpa awalan `std::`. Semua prosedur ditulis sebelum `main()` sehingga tidak diperlukan prototipe. Kata kunci `void` menandakan bahwa prosedur tidak mengembalikan nilai, sehingga hasil perhitungan disimpan langsung ke dalam matriks yang dikirim sebagai parameter.

Prosedur `inputMatriks()` menerima matriks `m` dan sebuah karakter `nama` yang dipakai sebagai label saat meminta input. Dua perulangan `for` bersarang dengan variabel `i` sebagai indeks baris dan `j` sebagai indeks kolom berjalan dari 0 sampai 2, sehingga seluruh sembilan elemen terisi lewat `cin >> m[i][j]`. Prosedur `tampilMatriks()` bekerja dengan pola perulangan yang sama, tetapi mencetak setiap elemen diikuti `\t` agar tersusun rapi per kolom, dan `endl` setiap satu baris selesai dicetak. Karena parameter berupa array, yang dikirim ke prosedur adalah alamat array aslinya, bukan salinan. Akibatnya, isi matriks yang diubah di dalam `inputMatriks()` ikut berubah di `main()`.

Prosedur `tambah()` dan `kurang()` menerima tiga matriks, yaitu `a`, `b`, dan `c`. Pada setiap pasangan indeks `[i][j]`, elemen `a` dan `b` dijumlahkan (atau dikurangkan), lalu hasilnya disimpan ke `c[i][j]`. Prosedur `kali()` sedikit berbeda karena memakai tiga perulangan bersarang. Untuk setiap elemen hasil `c[i][j]`, nilainya dikosongkan dulu dengan `c[i][j] = 0`. Perulangan `k` kemudian menjumlahkan hasil kali `a[i][k] * b[k][j]`, yaitu baris ke-`i` dari matriks `a` dikalikan dengan kolom ke-`j` dari matriks `b`. Inisialisasi dengan 0 penting agar hasil perkalian sebelumnya yang masih tersimpan di `c` tidak ikut terjumlah.

Di dalam fungsi `main()`, dideklarasikan tiga matriks `A`, `B`, dan `C` bertipe `int`, serta variabel `pilih` untuk menyimpan pilihan menu. Program memanggil `inputMatriks(A, 'A')` dan `inputMatriks(B, 'B')` agar pengguna mengisi kedua matriks. Setelah itu, perulangan `do-while` menampilkan menu dan membaca pilihan dengan `cin`. Jika `pilih` bernilai 1, 2, atau 3, program memanggil `tambah()`, `kurang()`, atau `kali()` dengan `C` sebagai penampung hasil, lalu mencetaknya dengan `tampilMatriks(C)`. Perulangan terus berjalan selama `pilih` tidak sama dengan 0, sehingga pengguna bisa mencoba semua operasi tanpa mengisi ulang matriks. Sebagai contoh, jika A berisi 1 sampai 9 secara berurutan dan B berisi 9 sampai 1, maka memilih menu 1 menghasilkan matriks yang seluruh elemennya bernilai 10. Program berakhir saat pengguna memasukkan 0, dan ditutup dengan `return 0;`.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel.

```C++
#include <iostream>
using namespace std;

void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void tukarReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int x, y, z;

    cout << "Masukkan x: ";
    cin >> x;
    cout << "Masukkan y: ";
    cin >> y;
    cout << "Masukkan z: ";
    cin >> z;

    cout << "\nSebelum: x = " << x << ", y = " << y << ", z = " << z << endl;

    tukarPointer(&x, &y, &z);
    cout << "Pointer: x = " << x << ", y = " << y << ", z = " << z << endl;

    tukarReference(x, y, z);
    cout << "Reference: x = " << x << ", y = " << y << ", z = " << z << endl;

    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/hass4ndonnydarmawan/109082500030_Hassan-Donny-Darmawan_SDT/blob/main/modul_2/output/2.1.png)

##### Output 2

![Screenshot Output Unguided 2_2](https://github.com/hass4ndonnydarmawan/109082500030_Hassan-Donny-Darmawan_SDT/blob/main/modul_2/output/2.2.png)

## Penjelasan Kode
Program ini menunjukkan penggunaan prosedur dengan parameter pointer dan reference dalam C++, yaitu prosedur `tukarPointer()` dan `tukarReference()` yang menukar nilai dari tiga variabel secara berputar. Di awal program, `#include <iostream>` memuat pustaka `cin` dan `cout`, sedangkan `using namespace std;` membuat keduanya dapat ditulis tanpa awalan `std::`. Kedua prosedur ditulis sebelum `main()` sehingga tidak diperlukan prototipe. Kata kunci `void` menandakan bahwa prosedur tidak mengembalikan nilai, karena hasil penukaran langsung mengubah variabel asli yang dikirim dari `main()`.

Prosedur `tukarPointer()` menerima tiga parameter bertipe pointer, yaitu `int *a`, `int *b`, dan `int *c`, yang masing-masing menyimpan alamat sebuah variabel (*call by pointer*). Nilai yang ditunjuk alamat tersebut diakses dengan operator `*`, sehingga `*a` berarti isi variabel yang alamatnya disimpan di `a`. Pertama, `*a` disimpan ke variabel sementara `temp` agar tidak hilang. Lalu `*a` diisi dengan `*b`, `*b` diisi dengan `*c`, dan `*c` diisi dengan `temp`. Hasilnya, nilai bergeser satu posisi ke kiri: isi pertama menjadi isi kedua, isi kedua menjadi isi ketiga, dan isi ketiga menjadi isi pertama.

Prosedur `tukarReference()` memiliki logika yang sama, tetapi parameternya bertipe reference, yaitu `int &a`, `int &b`, dan `int &c` (*call by reference*). Reference adalah nama lain dari variabel asli, sehingga `a`, `b`, dan `c` dapat dipakai langsung tanpa operator `*`. Variabel `temp` menyimpan nilai `a`, lalu `a = b`, `b = c`, dan `c = temp`. Perbedaan utamanya ada pada penulisan: pointer memerlukan operator `*` saat mengakses nilai dan operator `&` saat memanggil prosedur, sedangkan reference ditulis seperti variabel biasa.

Di dalam fungsi `main()`, dideklarasikan tiga variabel `x`, `y`, dan `z` bertipe `int`. Program meminta pengguna memasukkan ketiga nilai dengan `cin`, lalu menampilkan nilai sebelum ditukar. Pemanggilan `tukarPointer(&x, &y, &z)` mengirim alamat setiap variabel menggunakan operator `&`, sedangkan `tukarReference(x, y, z)` cukup mengirim variabelnya langsung. Penukaran dilakukan dua kali berturut-turut pada variabel yang sama, sehingga hasil reference adalah hasil pointer yang diputar sekali lagi. Sebagai contoh, jika pengguna memasukkan 1, 2, dan 3, maka setelah `tukarPointer()` nilainya menjadi 2, 3, 1, dan setelah `tukarReference()` nilainya menjadi 3, 1, 2. Program berakhir dengan `return 0;`.

**3.** Diketahui sebuah array 1 dimensi sebagai berikut:
 
```
arrA = {48, 2, 7, 21, 5, 20, 77, 9, 10, 1}
```
 
Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata-rata dari array tersebut! Kerjakan soal dengan ketentuan:
 
- Untuk mencari nilai minimum dan maksimum, harus dibuat menjadi sebuah function.
- Untuk mencari rata-rata harus dibuat menjadi sebuah procedure.
- Buat output di fungsi utama (main) untuk menampilkan nilai rata-rata yang sudah didapatkan melalui procedure sebelumnya. (Gunakan metode pass by reference atau pass by pointer)
- Buat menu sederhana untuk menjalankan setiap procedure.
Tampilan menu:
 
```
--- Menu Program Array ---
1. Tampilkan isi array
2. Cari nilai maksimum
3. Cari nilai minimum
4. Hitung nilai rata - rata
```

```C++
#include <iostream>
using namespace std;

int cariMaks(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks) {
            maks = arr[i];
        }
    }
    return maks;
}

int cariMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void hitungRata(int arr[], int n, double &rata) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    rata = (double)total / n;
}

int main() {
    int arrA[10] = {48, 2, 7, 21, 5, 20, 77, 9, 10, 1};
    int n = 10;
    double rata;
    int pilih;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata - rata" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            for (int i = 0; i < n; i++) {
                cout << arrA[i] << " ";
            }
            cout << endl;
        } else if (pilih == 2) {
            cout << "Nilai maksimum: " << cariMaks(arrA, n) << endl;
        } else if (pilih == 3) {
            cout << "Nilai minimum: " << cariMin(arrA, n) << endl;
        } else if (pilih == 4) {
            hitungRata(arrA, n, rata);
            cout << "Nilai rata-rata: " << rata << endl;
        }
    } while (pilih != 0);

    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/hass4ndonnydarmawan/109082500030_Hassan-Donny-Darmawan_SDT/blob/main/modul_2/output/3.png)

## Penjelasan Kode
Program ini menunjukkan penggunaan fungsi, prosedur, dan array satu dimensi dalam C++, yaitu fungsi `cariMaks()` dan `cariMin()` yang mengembalikan nilai, serta prosedur `hitungRata()` yang menghitung rata-rata dari sebuah array. Di awal program, `#include <iostream>` memuat pustaka `cin` dan `cout`, sedangkan `using namespace std;` membuat keduanya dapat ditulis tanpa awalan `std::`. Semua fungsi dan prosedur ditulis sebelum `main()` sehingga tidak diperlukan prototipe. Fungsi memiliki tipe keluaran `int` sehingga harus mengembalikan nilai dengan `return`, sedangkan kata kunci `void` pada prosedur menandakan bahwa prosedur tidak mengembalikan nilai.

Fungsi `cariMaks()` menerima array `arr` dan jumlah elemennya `n`. Variabel `maks` diisi terlebih dahulu dengan elemen pertama, yaitu `arr[0]`, sebagai nilai pembanding awal. Perulangan `for` dengan variabel lokal `i` berjalan dari indeks 1 sampai `n-1`. Pada setiap putaran, jika `arr[i]` lebih besar dari `maks`, maka `maks` diperbarui dengan nilai tersebut. Setelah perulangan selesai, `maks` berisi nilai terbesar dan dikembalikan ke pemanggil dengan `return maks;`. Fungsi `cariMin()` memiliki alur yang sama, tetapi kondisinya dibalik menjadi `arr[i] < min` sehingga yang disimpan adalah nilai terkecil.

Prosedur `hitungRata()` menerima tiga parameter, yaitu array `arr`, jumlah elemen `n`, dan parameter `double &rata` yang bertipe reference (*call by reference*). Variabel lokal `total` diawali dengan 0, lalu perulangan `for` dari indeks 0 sampai `n-1` menjumlahkan seluruh elemen ke dalam `total`. Rata-rata dihitung dengan `(double)total / n`. Konversi `(double)` diperlukan agar pembagian dua bilangan bulat tidak dibulatkan ke bawah, sehingga hasil desimal tetap terjaga. Karena `rata` adalah reference, hasil perhitungan langsung tersimpan di variabel `rata` milik `main()`, tanpa perlu `return`. Parameter `arr` yang berupa array juga tidak disalin, melainkan yang dikirim adalah alamat awalnya.

Di dalam fungsi `main()`, array `arrA` dideklarasikan berukuran 10 dan langsung diisi dengan nilai 48, 2, 7, 21, 5, 20, 77, 9, 10, dan 1. Variabel `n` menyimpan jumlah elemen, `rata` menampung hasil rata-rata, dan `pilih` menyimpan pilihan menu. Perulangan `do-while` menampilkan menu, lalu membaca pilihan dengan `cin`. Jika `pilih` bernilai 1, seluruh isi array dicetak lewat perulangan `for`. Jika bernilai 2 atau 3, program memanggil `cariMaks()` atau `cariMin()` dan langsung menampilkan nilai baliknya dengan `cout`. Jika bernilai 4, program memanggil `hitungRata(arrA, n, rata)` terlebih dahulu, lalu menampilkan isi `rata` di `main()`. Perulangan terus berjalan selama `pilih` tidak sama dengan 0, sehingga pengguna dapat memilih menu berkali-kali. Sebagai contoh, hasil untuk `arrA` adalah nilai maksimum 77, nilai minimum 1, dan rata-rata 20 karena total seluruh elemen adalah 200 dibagi 10 elemen. Program berakhir saat pengguna memasukkan 0, dan ditutup dengan `return 0;`.

## Kesimpulan

Berdasarkan Modul 2 dan latihan soal yang dikerjakan, dapat disimpulkan bahwa array, pointer, fungsi, dan prosedur adalah dasar penting dalam pemrograman C++ karena membantu program menjadi lebih terstruktur, efisien, dan mudah dikembangkan.

Array adalah kumpulan data bertipe sama yang disimpan berurutan di memori dan diakses lewat indeks yang dimulai dari 0. Array satu dimensi dipakai pada soal 3 untuk menyimpan `arrA` dan mencari nilai minimum, maksimum, serta rata-ratanya. Array dua dimensi menyerupai tabel dengan indeks baris dan kolom. Pada soal 1, array dua dimensi dipakai untuk menyimpan matriks 3x3 dan memprosesnya dengan perulangan `for` bersarang. Penjumlahan dan pengurangan cukup dengan dua perulangan, sedangkan perkalian membutuhkan tiga perulangan karena setiap elemen hasil diperoleh dari baris matriks pertama dikalikan dengan kolom matriks kedua.

Pointer adalah variabel yang menyimpan alamat memori variabel lain. Operator `&` dipakai untuk mengambil alamat suatu variabel, sedangkan operator `*` dipakai untuk mengakses nilai pada alamat yang ditunjuk. Pointer juga berhubungan erat dengan array, karena nama array pada dasarnya menunjuk ke alamat elemen pertamanya. Karena itu, array yang dikirim ke fungsi atau prosedur tidak disalin, sehingga perubahan di dalam prosedur ikut mengubah array aslinya.

Fungsi adalah blok kode yang mengembalikan nilai, sedangkan prosedur (`void`) adalah blok kode yang tidak mengembalikan nilai. Keduanya membuat program terbagi menjadi modul-modul kecil dan mengurangi pengulangan kode. Pada soal 3, pencarian nilai maksimum dan minimum dibuat sebagai fungsi karena menghasilkan satu nilai, sedangkan perhitungan rata-rata dibuat sebagai prosedur yang hasilnya dikirim kembali lewat parameter.

Ada tiga cara melewatkan parameter. Pada *call by value*, nilai parameter aktual disalin ke parameter formal sehingga variabel asli tidak berubah. Pada *call by pointer*, yang dikirim adalah alamat variabel (`&a`) dan diterima oleh parameter pointer (`int *x`), sehingga nilai variabel asli dapat diubah lewat operator `*`. Pada *call by reference*, parameter formal dideklarasikan dengan `&` (`int &x`) dan menjadi nama lain dari variabel asli, sehingga perubahannya langsung berlaku tanpa operator tambahan saat pemanggilan. Soal 2 menunjukkan perbedaan kedua cara ini lewat `tukarPointer()` dan `tukarReference()`, yang sama-sama menukar nilai tiga variabel di luar fungsi. Perbedaannya hanya pada penulisan: pointer memakai `*` dan `&`, sedangkan reference ditulis seperti variabel biasa.

Dengan mengerjakan ketiga soal ini, kita memahami bahwa pemilihan antara fungsi dan prosedur serta cara melewatkan parameter harus disesuaikan dengan kebutuhan program. Fungsi dipakai jika hanya perlu satu nilai balik. Pointer atau reference dipakai jika nilai variabel asli perlu diubah atau ada lebih dari satu hasil yang harus dikembalikan.

## Referensi

[1] Modul Praktikum Struktur Data — Modul 2: Pengenalan Bahasa C++ (Bagian Kedua), Fakultas Informatika, Telkom University.
<br>[2] Stroustrup, B. (2013). *The C++ Programming Language* (4th ed.). Addison-Wesley.
<br>[3] cplusplus.com. *C++ Language Tutorial*. https://www.cplusplus.com/doc/tutorial/
<br>[4] cppreference.com. *Pointer declaration*. https://en.cppreference.com/w/cpp/language/pointer