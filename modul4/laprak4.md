# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List</h1>

<p align="center">Hassan Donny Darmawan - 109082500030</p>

## Dasar Teori
 
Bagian ini membahas konsep dasar yang digunakan dalam praktikum, mulai dari pengertian *linked list*, struktur *singly linked list*, hingga operasi-operasi dasarnya seperti *insert*, *view*, *delete*, dan *update*.
 
---
 
### A. Linked List<br/>
 
Sub-bagian ini membahas pengertian *linked list* dan alasan penggunaan *pointer* dalam implementasinya.
 
#### 1. Pengertian Linked List
 
*Linked list* (biasa disebut *list* saja) adalah salah satu bentuk struktur data berupa serangkaian elemen data yang saling berkaitan dan bersifat fleksibel karena dapat tumbuh dan mengerut sesuai kebutuhan. Data yang disimpan dapat berupa data tunggal, yaitu data yang hanya terdiri dari satu variabel (mis. nama bertipe `string`), atau data majemuk berupa *record* yang terdiri dari beberapa tipe data (mis. data mahasiswa yang terdiri dari nama, NIM, dan alamat).
 
#### 2. Linked List dengan Pointer
 
*Linked list* dapat diimplementasikan menggunakan *array* maupun *pointer*, dan yang digunakan dalam praktikum ini adalah *pointer*. Alasannya, *array* bersifat statis sedangkan *pointer* dinamis, bentuk data pada *linked list* yang saling bergandengan lebih mudah ditangani dengan *pointer*, dan sifat *linked list* yang fleksibel cocok dengan *pointer* yang dapat diatur sesuai kebutuhan. *Array* lebih cocok digunakan pada kumpulan data yang jumlah elemen maksimumnya sudah diketahui sejak awal. Pada implementasinya, elemen diakses dengan operator panah (`->`) atau tanda titik (`.`).
 
#### 3. Model-Model ADT Linked List
 
Model ADT *linked list* yang dipelajari meliputi *singly linked list*, *doubly linked list*, *circular linked list*, *multi linked list*, *stack*, *queue*, *tree*, dan *graph*. Setiap model memiliki karakteristik tertentu dan penggunaannya disesuaikan dengan kebutuhan.
 
#### 4. Operasi Umum pada Linked List
 
Secara umum, operasi ADT pada *linked list* terdiri dari:
- Penciptaan dan inisialisasi *list* (*Create List*).
- Penyisipan elemen *list* (*Insert*).
- Penghapusan elemen *list* (*Delete*).
- Penelusuran elemen *list* dan menampilkannya (*View*).
- Pencarian elemen *list* (*Searching*).
- Pengubahan isi elemen *list* (*Update*).
 
### B. Singly Linked List<br/>
 
Sub-bagian ini membahas model *linked list* yang hanya memiliki satu arah *pointer*.
 
#### 1. Pengertian dan Komponen Elemen
 
*Singly linked list* adalah model ADT *linked list* yang hanya memiliki satu arah *pointer*. Setiap elemen terdiri dari dua bagian, yaitu *data* sebagai informasi utama yang tersimpan dalam elemen, dan *successor* sebagai bagian yang menghubungkan elemen tersebut dengan elemen berikutnya.
 
#### 2. Sifat Singly Linked List
 
*Singly linked list* memiliki sifat sebagai berikut:
- Hanya memerlukan satu buah *pointer*.
- *Node* akhir menunjuk ke `Nil`, kecuali untuk *list circular*.
- Hanya dapat melakukan pembacaan maju.
- Pencarian sekuensial dilakukan jika data tidak terurut.
- Lebih mudah ketika melakukan penyisipan atau penghapusan di tengah *list*.
 
#### 3. Istilah dalam Singly Linked List
 
Istilah yang digunakan dalam *singly linked list* adalah:
- `first`/`head`, yaitu *pointer* pada *list* yang menunjuk alamat elemen pertama.
- `next`, yaitu *pointer* pada elemen yang berfungsi sebagai *successor* (penunjuk) alamat elemen di depannya.
- `NULL`/`Nil`, yang berarti tidak memiliki nilai, tidak mengacu ke mana pun, atau kosong.
- *Node*/simpul/elemen, yaitu tempat penyimpanan data pada suatu memori tertentu.
 
### C. Pembentukan Komponen List<br/>
 
Sub-bagian ini membahas deklarasi struktur data dan operasi dasar untuk membentuk serta mengelola komponen *list*.
 
#### 1. Deklarasi Struktur Data
 
Struktur data *singly linked list* dideklarasikan dengan `typedef struct elmlist *address;`, sebuah `struct elmlist` yang berisi `info` bertipe `infotype` dan `next` bertipe `address`, serta sebuah `struct list` yang berisi `address first`. Untuk data majemuk seperti data mahasiswa, `infotype` didefinisikan sebagai `struct` tersebut melalui `typedef`. Konstanta `Nil` didefinisikan sebagai `NULL` dan deklarasi dilengkapi `#ifndef`, `#define`, `#endif`.
 
#### 2. Pembentukan List
 
Pembentukan *list* adalah proses membentuk sebuah *list* baru, biasanya dengan fungsi `createList()`. Fungsi ini mengatur nilai awal `first` pada *list* dengan `Nil`.
 
#### 3. Pengalokasian Memori
 
Pengalokasian memori adalah proses menyediakan memori untuk setiap elemen data pada *list*, biasanya dengan fungsi `alokasi()`. Pada bahasa C digunakan `P = (address) malloc(sizeof(elmlist));`, sedangkan pada C++ cukup `P = new elmlist;`.
 
#### 4. Dealokasi
 
Dealokasi digunakan untuk menghapus *memory address* yang telah dialokasikan. Pada bahasa C digunakan `free(p);`, sedangkan pada C++ digunakan `delete p;`.
 
#### 5. Pengecekan List
 
Fungsi `isEmpty()` digunakan untuk mengecek apakah *list* kosong atau tidak. Fungsi ini mengembalikan nilai `true` jika *list* kosong dan `false` jika *list* tidak kosong.
 
### D. Insert<br/>
 
Sub-bagian ini membahas cara menyisipkan elemen baru ke dalam *list*. Pada setiap jenis *insert*, elemen baru dibuat terlebih dahulu dengan `P = alokasi(X);` dan `P->next = Nil;`.
 
#### 1. Insert First
 
*Insert first* adalah metode memasukkan elemen data pada awal *list*. Setelah elemen dialokasikan, `next` dari elemen baru diarahkan ke elemen pertama dengan `P->next = L.first;`, lalu `first` diarahkan ke elemen baru dengan `L.first = P;`.
 
#### 2. Insert Last
 
*Insert last* adalah metode memasukkan elemen data pada akhir *list*. *Pointer* bantu `Q` digunakan untuk menunjuk elemen terakhir, kemudian elemen baru dihubungkan dengan `Q->next = P;`.
 
#### 3. Insert After
 
*Insert after* adalah metode memasukkan elemen data setelah *node* tertentu yang ditunjuk oleh *user*. Jika `Q` menunjuk *node* acuan, maka `next` elemen baru diarahkan ke *node* setelah `Q` dengan `P->next = Q->next;`, lalu `Q->next = P;`.
 
### E. View<br/>
 
Sub-bagian ini membahas operasi untuk menampilkan isi *list*.
 
*View* adalah operasi dasar pada *list* yang menampilkan isi *node* dengan penelusuran *list*, yaitu mengunjungi setiap *node* kemudian menampilkan data yang tersimpan pada *node* tersebut. Semua fungsi dasar pada ADT *singly linked list* disimpan dalam *file* `.h` yang berisi prototipe fungsi dan tipe data, serta *file* `.cpp` yang berisi realisasinya.
 
### F. Delete<br/>
 
Sub-bagian ini membahas cara mengambil atau menghapus elemen dari *list*.
 
#### 1. Delete First
 
*Delete first* adalah penghapusan elemen pada awal *list*. Elemen pertama ditunjuk dengan `P = L.first;`, `first` dipindahkan ke elemen berikutnya dengan `L.first = (L.first)->next;`, kemudian `P->next = Nil;` dan elemen dikembalikan atau didealokasi.
 
#### 2. Delete Last
 
*Delete last* adalah penghapusan elemen dari akhir *list*. Elemen terakhir ditunjuk dengan `P = getLast(L);` dan elemen sebelumnya dengan `Q = findBefore(P);`, kemudian `Q->next = Nil;` dan elemen `P` dikembalikan atau didealokasi.
 
#### 3. Delete After
 
*Delete after* adalah penghapusan *node* setelah *node* tertentu. Jika `P` menunjuk *node* acuan dan `Q` menunjuk *node* sesudahnya, maka `P->next = Q->next;` melewati `Q`, kemudian `Q->next = Nil;` dan elemen `Q` didealokasi.
 
#### 4. Delete Elemen
 
*Delete* elemen adalah operasi untuk menghapus dan membebaskan memori yang dipakai oleh elemen. Fungsi yang biasa dipakai adalah `dealokasi(P)`, yang membebaskan memori elemen `P`, dan `delAll(L)`, yang membebaskan memori semua elemen pada *list* `L` sehingga hasil akhirnya *list* menjadi kosong.
 
### G. Update<br/>
 
Sub-bagian ini membahas operasi untuk mengubah data pada *list*.
 
*Update* adalah operasi dasar pada *list* yang digunakan untuk mengubah data yang ada di dalam *list*, yaitu data-data pada *node*. Proses *update* biasanya diawali dengan proses pencarian terhadap data yang akan diubah.
---

## Guided

### 1. ...

## List.h
```C++
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct Node *address;

struct student {
    int age;
    string name, id;
};

struct Node {
    student data;
    address next;
};

struct LinkedList {
    address first;
};

bool isEmpty(LinkedList L);
void createList(LinkedList &L);
address alokasi(int age, string name, string id);
void dealokasi(address &P);
void printList(LinkedList L);
void insertFirst(LinkedList &L, address P);
void insertAfter(LinkedList &L, address Prev, address P);
void insertLast(LinkedList &L, address P);

void delfirst(LinkedList &L);
void delAfter(LinkedList &L, address Prev, address P);
void delLast(LinkedList &L);
int nbList(LinkedList L);
void delList(LinkedList &L);
#endif
```
## List.cpp
```C++
#include "List.h"
#include <iostream>
using namespace std;

bool isEmpty(LinkedList L){
    if (L.first == Nil){
        return (L.first == Nil);
    } else {
        return (L.first == Nil);
    }
};

void createList(LinkedList &L){
    L.first = Nil;
};
// Function to allocate a new node with the given student data
address alokasi(int age, string name, string id){
    address P = new Node;
    if (P != Nil){
        P->data.age = age;
        P->data.name = name;
        P->data.id = id;
        P->next = Nil;
    }
    return P;
};

void dealokasi(address &P){
    P->next = Nil;
    delete P;
};

void printList(LinkedList L){
    address P = L.first;
    while (P != Nil){
        cout << "Name: \t" << P->data.name << ", ID: \t" << P->data.id << ", Age: " << P->data.age << endl;
        P = P->next;
    }
};

void insertFirst(LinkedList &L, address P)
{
    if (isEmpty(L)){
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
};

void insertAfter(LinkedList &L, address Prev, address P)
{
    if (Prev != Nil){
        P->next = Prev->next;
        Prev->next = P;
    }
};

void insertLast(LinkedList &L, address P)
{
    if (isEmpty(L)){
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != Nil){
            Q = Q->next;
        }
        Q->next = P;
    }
};


void delfirst(LinkedList &L){
    if (isEmpty(L)){
        cout << "List is empty, cannot delete." << endl;
    } else {
        address P = L.first;
        L.first = P->next;
        dealokasi(P);
    }
};

void delAfter(LinkedList &L, address Prev, address P){
    if (isEmpty(L)){
        cout << "List is empty, cannot delete." << endl;
    } else {
        if(Prev != Nil && Prev->next != Nil){
            P = Prev->next;
            Prev->next = P->next;
            P->next = Nil;
            dealokasi(P);
        }else{
            cout << "Previous node is not valid, cannot delete." << endl;
        }
    }
};

void delLast(LinkedList &L){
    if (isEmpty(L)){
        cout << "List is empty, cannot delete." << endl;
    } else {
        address P = L.first;
        address Q = Nil;
        while (P->next != Nil){
            Q = P;
            P = P->next;
        }
        if (Q != Nil){
            Q->next = Nil;
        } else {
            L.first = Nil;
        }
        dealokasi(P);
    }
};

int nbList(LinkedList L){
    int count = 0;
    address P = L.first;
    while (P != Nil){
        count++;
        P = P->next;
    }
    return count;
};

void delList(LinkedList &L){
    while (!isEmpty(L)){
        delfirst(L);
    }
};
```
## main.cpp
```C++
#include <iostream>
#include "List.h"

using namespace std;

int main(){

    LinkedList L;
    address nodeA = Nil, nodeB = Nil, nodeC = Nil, nodeD = Nil, nodeE = Nil;
    createList(L);

    \
    nodeA = alokasi(20, "Dhimas", "2311102151");
    nodeB = alokasi(21, "Arvin",  "2311102152");
    nodeC = alokasi(20, "Budi",   "2311102153");
    nodeD = alokasi(22, "Citra",  "2311102154");
    nodeE = alokasi(19, "Dina",   "2311102155");

    
    insertFirst(L, nodeA);          
    insertLast(L, nodeB);           
    insertAfter(L, nodeA, nodeC);   
    insertFirst(L, nodeD);          
    insertLast(L, nodeE);           

    cout << "Isi list:" << endl;
    printList(L);
    cout << "Jumlah node: " << nbList(L) << endl;

    delfirst(L);                    
    delLast(L);                     
    delAfter(L, L.first, Nil);      

    cout << "\nSetelah penghapusan:" << endl;
    printList(L);
    cout << "Jumlah node: " << nbList(L) << endl;

    delList(L);                     // bebaskan semua memori
    cout << "\nSetelah delList, jumlah node: " << nbList(L) << endl;

    return 0;
}
```
##### Output 1

![Screenshot Output guided 1](https://github.com/hass4ndonnydarmawan/109082500030_Hassan-Donny-Darmawan_SDT/blob/main/modul4/output/guided.png)

## Penjelasan Kode
Program ini menunjukkan cara menyimpan data mahasiswa ke dalam *singly linked list* dengan penerapan konsep ADT yang dipisah menjadi tiga file. File `List.h` berisi `struct student` dengan tiga *field*, yaitu `age` bertipe `int` serta `name` dan `id` bertipe `string`. Kemudian ada `struct Node` yang menyimpan `data` bertipe `student` dan *pointer* `next`, serta `struct LinkedList` yang hanya berisi *pointer* `first` sebagai penunjuk elemen pertama. Baris `typedef struct Node *address;` membuat `address` menjadi nama lain dari *pointer* ke `Node`, sedangkan `#define Nil NULL` membuat `Nil` dapat dipakai sebagai penanda *list* kosong atau akhir *list*. Baris `#ifndef LINKEDLIST_H`, `#define LINKEDLIST_H`, dan `#endif` mencegah file *header* ter-*include* berulang kali, `#include <iostream>` memuat pustaka `cin` dan `cout`, dan `using namespace std;` membuat `cout`, `endl`, dan `string` dapat ditulis tanpa awalan `std::`. Sisa isi *header* adalah deklarasi tiga belas fungsi dan prosedur untuk mengelola *list*.

File `List.cpp` berisi isi dari fungsi-fungsi tersebut. Fungsi `isEmpty()` mengembalikan `true` jika `L.first` bernilai `Nil`, dan prosedur `createList()` mengisi `L.first` dengan `Nil` agar *list* kosong. Fungsi `alokasi()` membuat `Node` baru dengan `new`, mengisi `age`, `name`, dan `id` dari parameternya, lalu mengatur `next` menjadi `Nil` dan mengembalikan alamat `Node` tersebut. Prosedur `dealokasi()` memutus `next` lalu membebaskan memori dengan `delete`. Prosedur `printList()` menelusuri *list* dari `first` sampai `Nil` dan mencetak `name`, `id`, dan `age` setiap *node*. Untuk penyisipan, `insertFirst()` mengarahkan `next` elemen baru ke elemen pertama lalu memindahkan `first` ke elemen baru, `insertAfter()` menyisipkan elemen baru setelah `Prev`, dan `insertLast()` menelusuri *list* sampai elemen terakhir lalu menyambungkan elemen baru di sana. Untuk penghapusan, `delfirst()` memindahkan `first` ke elemen berikutnya lalu mendealokasi elemen pertama, `delAfter()` melewati elemen setelah `Prev` lalu mendealokasinya, dan `delLast()` menelusuri *list* memakai dua *pointer* (`P` dan `Q`) agar elemen sebelum yang terakhir dapat diputus. Ketiga prosedur penghapusan akan mencetak pesan jika *list* kosong atau `Prev` tidak valid. Fungsi `nbList()` menghitung jumlah *node*, dan `delList()` memanggil `delfirst()` berulang kali sampai *list* kosong. Parameter `LinkedList &L` memakai tanda `&` (*call by reference*) pada prosedur yang mengubah *list* agar perubahannya tersimpan pada variabel aslinya di `main()`, sedangkan `printList()` dan `nbList()` cukup dikirim dengan nilai karena isinya hanya dibaca.

Di dalam fungsi `main()`, dideklarasikan `L` bertipe `LinkedList` serta lima *pointer* `nodeA` sampai `nodeE` bertipe `address` yang diinisialisasi dengan `Nil`. Setelah `createList(L)` dipanggil, setiap *node* dibuat dengan `alokasi()` dengan urutan argumen umur, nama, lalu NIM. Kelima *node* kemudian dimasukkan ke *list* secara bertahap: `nodeA` dengan `insertFirst()`, `nodeB` dengan `insertLast()`, `nodeC` dengan `insertAfter()` setelah `nodeA`, `nodeD` dengan `insertFirst()`, dan `nodeE` dengan `insertLast()`, sehingga urutan akhirnya adalah D, A, C, B, E. Isi *list* dan jumlah *node* lalu ditampilkan dengan `printList()` dan `nbList()`.

Setelah itu, `delfirst()` menghapus `nodeD`, `delLast()` menghapus `nodeE`, dan `delAfter(L, L.first, Nil)` menghapus node setelah `nodeA`, yaitu `nodeC`, sehingga *list* tersisa A dan B. Parameter ketiga `delAfter()` diisi `Nil` karena nilainya langsung ditimpa di dalam fungsi. Program menampilkan kembali isi *list* yang kini berisi Dhimas dan Arvin dengan jumlah *node* 2. Terakhir, `delList(L)` membebaskan semua *node* yang tersisa sehingga `nbList(L)` bernilai 0, dan program berakhir dengan `return 0;`.


## Unguided

### 1. Program Data Mahasiswa Menggunakan Konsep ADT Sederhana

### Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```
### Singlylist.cpp
```C++
#include "Singlylist.h"

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}
```
### main.cpp
```C++
#include <iostream>
#include "Singlylist.h"

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```
##### Output 1

![Screenshot Output unguided 1_1](https://github.com/hass4ndonnydarmawan/109082500030_Hassan-Donny-Darmawan_SDT/blob/main/modul4/output/soal1.png)

## Penjelasan Kode

Program ini menunjukkan cara menyimpan kumpulan angka ke dalam *singly linked list* dengan penerapan konsep ADT yang dipisah menjadi tiga file. File `Singlylist.h` berisi `typedef int infotype;` sebagai tipe data yang disimpan, dan `typedef struct ElmList *address;` yang membuat `address` menjadi nama lain dari *pointer* ke `ElmList`. Kemudian ada `struct ElmList` yang menyimpan `info` bertipe `infotype` dan *pointer* `next`, serta `struct List` yang hanya berisi *pointer* `First` sebagai penunjuk elemen pertama. Baris `#define Nil NULL` membuat `Nil` dapat dipakai sebagai penanda *list* kosong atau akhir *list*. Baris `#ifndef SINGLYLIST_H`, `#define SINGLYLIST_H`, dan `#endif` mencegah file *header* ter-*include* berulang kali, `#include <iostream>` memuat pustaka `cin` dan `cout`, dan `using namespace std;` membuat `cout` dan `endl` dapat ditulis tanpa awalan `std::`. Sisa isi *header* adalah deklarasi lima fungsi dan prosedur untuk mengelola *list*.

File `Singlylist.cpp` berisi isi dari kelima fungsi tersebut. Prosedur `CreateList()` mengisi `L.First` dengan `Nil` agar *list* kosong. Fungsi `alokasi()` membuat elemen baru dengan `new`, mengisi `info` dari parameter `x`, mengatur `next` menjadi `Nil`, lalu mengembalikan alamat elemen tersebut. Prosedur `dealokasi()` membebaskan memori elemen dengan `delete` lalu mengisi `P` dengan `Nil` agar tidak menjadi *pointer* yang menggantung. Prosedur `printInfo()` menelusuri *list* dari `First` sampai `Nil`, mencetak `info` setiap elemen diikuti spasi, lalu berpindah baris. Prosedur `insertFirst()` mengarahkan `next` elemen baru ke elemen pertama dengan `P->next = L.First;`, kemudian memindahkan `First` ke elemen baru dengan `L.First = P;`. Parameter `List &L` pada `CreateList()` dan `insertFirst()` memakai tanda `&` (*call by reference*) agar perubahan pada *list* tersimpan pada variabel aslinya di `main()`, sedangkan `printInfo()` cukup dikirim dengan nilai karena isinya hanya dibaca.

Di dalam fungsi `main()`, dideklarasikan `L` bertipe `List` serta lima *pointer* `P1` sampai `P5` bertipe `address`, dengan `P5` diinisialisasi `Nil`. Setelah `CreateList(L)` dipanggil, setiap elemen dibuat dengan `alokasi()` lalu langsung dimasukkan ke awal *list* dengan `insertFirst()`, berturut-turut dengan nilai 2, 0, 8, 12, dan 9. Karena setiap elemen baru selalu ditempatkan di depan, elemen yang dimasukkan terakhir berada paling awal, sehingga urutan *list* menjadi 9, 12, 8, 0, 2.

Pemanggilan `printInfo(L)` kemudian mencetak isi *list* dari elemen pertama sampai terakhir, yaitu `9 12 8 0 2`. Prosedur `dealokasi()` tidak dipanggil di `main()`, sehingga memori elemen dibebaskan oleh sistem saat program berakhir dengan `return 0;`.

````

````
## Kesimpulan

Berdasarkan Modul 4 dan latihan soal yang dikerjakan, dapat disimpulkan bahwa *singly linked list* adalah struktur data yang fleksibel karena dapat tumbuh dan mengerut sesuai kebutuhan, dan penerapannya dengan *pointer* membuat penyimpanan data menjadi dinamis serta mudah diatur.

*Linked list* adalah serangkaian elemen data yang saling berkaitan, dan pada *singly linked list* setiap elemen hanya memiliki satu arah *pointer*. Setiap elemen (*node*) terdiri dari `info` sebagai data dan `next` sebagai *successor* yang menunjuk ke elemen berikutnya, sedangkan `First` menunjuk elemen pertama dan `Nil` menandai akhir *list* atau *list* yang kosong. *Pointer* dipilih dibandingkan *array* karena *array* bersifat statis dan cocok untuk data yang jumlah maksimumnya sudah diketahui, sedangkan *pointer* dapat diatur sesuai kebutuhan. Pada latihan, struktur ini dibuat sebagai ADT yang dipisah menjadi tiga file, yaitu `Singlylist.h` yang berisi `infotype`, `address`, `ElmList`, `List`, dan deklarasi fungsi, `Singlylist.cpp` yang berisi isi fungsi, dan `main.cpp` sebagai *driver* yang menguji ADT.

Operasi dasar pada *linked list* meliputi pembentukan, penyisipan, penghapusan, penelusuran, pencarian, dan pengubahan data. Pada latihan, `CreateList()` membentuk *list* kosong dengan mengisi `First` dengan `Nil`, `alokasi()` membuat elemen baru dengan `new`, dan `dealokasi()` membebaskan memorinya dengan `delete`. Prosedur `printInfo()` menelusuri *list* dari `First` sampai `Nil` untuk menampilkan setiap `info`. Prosedur `insertFirst()` menyisipkan elemen di awal *list* dengan dua langkah, yaitu `P->next = L.First;` lalu `L.First = P;`. Urutan kedua langkah ini penting karena jika `First` dipindahkan lebih dulu, alamat elemen lama akan hilang. Karena setiap elemen baru ditempatkan di depan, data yang dimasukkan berturut-turut 2, 0, 8, 12, dan 9 menghasilkan *list* dengan urutan 9, 12, 8, 0, 2, sesuai dengan keluaran pada modul.

Operasi penyisipan dan penghapusan lainnya pada dasarnya hanya mengubah *pointer* `next`. *Insert last* menyambungkan elemen baru ke elemen terakhir, *insert after* mengarahkan `next` elemen baru ke elemen setelah elemen acuan lalu menyambungkan elemen acuan ke elemen baru, dan *delete* memutus elemen dari *list* sebelum memorinya dibebaskan dengan `dealokasi()`. Karena itu, penyisipan dan penghapusan di tengah *list* lebih mudah dibandingkan pada *array*, tetapi *singly linked list* hanya dapat ditelusuri maju sehingga pencarian dilakukan secara sekuensial.

Parameter `List &L` pada `CreateList()` dan `insertFirst()` dikirim dengan *call by reference* agar perubahan pada *list* tersimpan pada variabel aslinya di `main()`, sedangkan `printInfo()` cukup dikirim dengan nilai karena isinya hanya dibaca.

Dengan mengerjakan latihan ini, kita memahami bahwa *singly linked list* membantu menyimpan data yang jumlahnya berubah-ubah tanpa menentukan ukuran di awal, dan ketelitian dalam mengatur urutan perpindahan *pointer* menentukan benar tidaknya hasil operasi pada *list*.

## Referensi

[1] Modul Praktikum Struktur Data — Modul 4: Singly Linked List (Bagian Pertama), Fakultas Informatika, Telkom University.
<br>[2] Stroustrup, B. (2013). *The C++ Programming Language* (4th ed.). Addison-Wesley.
<br>[3] cplusplus.com. *Data Structures (struct)*. https://cplusplus.com/doc/tutorial/structures/
<br>[4] cplusplus.com. *Pointers*. https://cplusplus.com/doc/tutorial/pointers/
<br>[5] cplusplus.com. *Dynamic Memory*. https://cplusplus.com/doc/tutorial/dynamic/
<br>[6] cplusplus.com. *Functions*. https://cplusplus.com/doc/tutorial/functions/