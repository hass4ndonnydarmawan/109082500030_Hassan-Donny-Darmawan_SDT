# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian 2)</h1>

<p align="center">Hassan Donny Darmawan - 109082500030</p>

## Dasar Teori

Bagian ini membahas konsep dasar yang digunakan dalam praktikum, mulai dari operasi pencarian (*searching*) pada *singly linked list*, struktur ADT *singly linked list* dalam file `.h` dan `.cpp`, hingga operasi-operasi lanjutan seperti penambahan elemen, penghapusan elemen, serta pemrosesan seluruh elemen dan *list*.

---

### A. Searching<br/>

Sub-bagian ini membahas pengertian *searching* dan fungsi-fungsi pencarian pada *singly linked list*.

#### 1. Pengertian Searching

*Searching* adalah operasi dasar pada *list* yang dilakukan dengan mencari *node* tertentu. Prosesnya berjalan dengan mengunjungi setiap *node* dari awal *list* dan berhenti setelah *node* yang dicari ditemukan. Karena *singly linked list* hanya dapat ditelusuri ke arah depan, pencarian dilakukan secara sekuensial. Dengan adanya operasi *searching*, operasi-operasi lain seperti *insert after*, *delete after*, dan *update* menjadi lebih mudah karena alamat *node* acuan dapat diperoleh terlebih dahulu.

#### 2. Fungsi Pencarian pada ADT

Pada ADT *singly linked list* terdapat beberapa fungsi pencarian, yaitu:
- `findElm(L, X)`, yaitu fungsi yang mencari elemen *list* dengan `P->info = X`. Jika ada, fungsi mengembalikan alamat elemen tersebut, dan jika tidak ada, fungsi mengembalikan `Nil`.
- `fFindElm(L, P)`, yaitu fungsi yang mencari apakah ada elemen *list* dengan alamat `P`. Fungsi ini mengembalikan `true` jika ada dan `false` jika tidak ada.
- `findBefore(L, P)`, yaitu fungsi yang mengembalikan alamat elemen sebelum `P`. Jika `P` berada pada awal *list*, fungsi mengembalikan `Nil`.

### B. ADT Singly Linked List<br/>

Sub-bagian ini membahas cara semua fungsi dasar *singly linked list* disusun sebagai ADT dalam file `.h` dan `.cpp`.

#### 1. Pembagian File ADT

Semua fungsi dasar pada *singly linked list*, termasuk operasi *searching*, merupakan bagian dari ADT *singly linked list*. Pada bahasa pemrograman C++, ADT tersebut disimpan dalam dua jenis file, yaitu file `*.h` yang berisi deklarasi tipe data dan *prototype* fungsi, serta file `*.cpp` yang berisi realisasi dari fungsi-fungsi tersebut.

#### 2. Deklarasi Struktur Data

Struktur data *singly linked list* dideklarasikan dengan `typedef int infotype;` sebagai tipe data informasi dan `typedef struct elmlist *address;` agar `address` menjadi *pointer* ke `elmlist`. Kemudian dibuat `struct elmlist` yang berisi `info` bertipe `infotype` dan `next` bertipe `address`, serta `struct list` yang berisi `address first`. Konstanta `Nil` didefinisikan sebagai `NULL`, dan deklarasi dilengkapi dengan `#ifndef`, `#define`, dan `#endif` serta `#include "boolean.h"` untuk tipe `boolean`.

#### 3. Aturan Dasar List

Sebuah *list* dinyatakan kosong jika `L.first = Nil`. Setiap elemen dengan alamat `P` dapat diacu dengan `P->info` untuk mengakses data dan `P->next` untuk mengakses elemen berikutnya.

#### 4. Fungsi Dasar List

Fungsi dasar yang digunakan untuk mengelola *list* adalah:
- `ListEmpty(L)`, yaitu fungsi yang mengembalikan `true` jika *list* kosong.
- `CreateList(L)`, yaitu prosedur yang membentuk *list* kosong.
- `dealokasi(P)`, yaitu prosedur yang mengembalikan memori yang digunakan `P` ke sistem.

Setiap prosedur pada ADT dilengkapi spesifikasi I.S. (*initial state*) sebagai kondisi awal dan F.S. (*final state*) sebagai kondisi akhir.

### C. Penambahan Elemen (Insert)<br/>

Sub-bagian ini membahas prosedur untuk menyisipkan elemen baru ke dalam *list*. Pada semua prosedur *insert*, elemen `P` harus sudah dialokasikan sebelum disisipkan.

#### 1. Insert First

`insertFirst(L, P)` menempatkan elemen beralamat `P` pada awal *list*.

#### 2. Insert After

`insertAfter(L, P, Prec)` menempatkan elemen beralamat `P` sesudah elemen beralamat `Prec`, dengan syarat `P` dan `Prec` adalah alamat salah satu elemen *list*.

#### 3. Insert Last

`insertLast(L, P)` menempatkan elemen beralamat `P` pada akhir *list*.

### D. Penghapusan Elemen (Delete)<br/>

Sub-bagian ini membahas prosedur untuk menghapus elemen dari *list*.

#### 1. Delete First

`delFirst(L, P)` menghapus elemen pertama *list* dengan syarat *list* tidak kosong. Setelah prosedur dijalankan, `P` berisi alamat elemen pertama sebelum dihapus, elemen pertama hilang dari *list*, dan *first* yang baru adalah *successor* dari *first* yang lama. *List* mungkin menjadi kosong setelah penghapusan.

#### 2. Delete Last

`delLast(L, P)` menghapus elemen terakhir *list* dengan syarat *list* tidak kosong. Setelah prosedur dijalankan, `P` berisi alamat elemen terakhir sebelum dihapus, dan elemen terakhir hilang dari *list*. *List* mungkin menjadi kosong setelah penghapusan.

#### 3. Delete After

`delAfter(L, P, Prec)` menghapus elemen setelah `Prec` dengan syarat *list* tidak kosong dan `Prec` adalah alamat salah satu elemen *list*. Setelah prosedur dijalankan, `P` berisi alamat dari `Prec->next`, dan elemen tersebut dihapus dari *list*.

#### 4. Delete Berdasarkan Info

`delP(L, X)` menghapus elemen yang memiliki `P->info = X`. Jika elemen tersebut ada, `P` dihapus dan didealokasi, sedangkan jika tidak ada, *list* tetap seperti semula. *List* mungkin menjadi kosong karena penghapusan.

### E. Proses Semua Elemen List<br/>

Sub-bagian ini membahas fungsi yang bekerja dengan menelusuri seluruh elemen *list*.

#### 1. Menampilkan Isi List

`printInfo(L)` menampilkan semua `info` yang ada pada *list* jika *list* tidak kosong. Pada kondisi awal, *list* boleh kosong.

#### 2. Menghitung Jumlah Elemen

`nbList(L)` mengembalikan jumlah elemen pada *list*.

### F. Proses terhadap List<br/>

Sub-bagian ini membahas operasi yang memproses *list* secara utuh.

#### 1. Delete All

`delAll(L)` menghapus semua elemen *list* dan men-dealokasi semua elemen tersebut.

#### 2. Invert List

`invertList(L)` membalik urutan elemen-elemen *list*.

#### 3. Copy List

`copyList(L1, L2)` menyalin *list* `L1` ke `L2` sehingga keduanya menunjuk pada elemen yang sama. Sementara itu, `fCopyList(L)` adalah fungsi yang mengembalikan *list* yang merupakan salinan dari `L`.
---

## Guided

### 1. ...

## list.h
```C++
#ifndef List_h
#define List_h 
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama, nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node
{
    dataMahasiswa isidata;
    address next;
};

struct linkedList
{
    address first;
};

bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertLast(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address prev);
void delFirst(linkedList &List);
void delLast(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

address FindNodebyData(linkedList List, string data);
void FindNodebyAddress(linkedList List, address node);
void FindNodeByRange(linkedList List, int nilaiAwal, int nilaiAkhir);

void updateFirst(linkedList &list);
void updateLast(linkedList &list);
void updateAfter(linkedList &list, address &prev);
void updateByNim(linkedList &list, string nim);

#endif
```
## list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List)
{
    if (List.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// pembuatan linked list kosong
void createList(linkedList &List)
{
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur)
{
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node)
{
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru)
{
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev)
{
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil)
    {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    }
    else
    {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru)
{
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List))
    {
        List.first = nodeBaru;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List)
{
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List)
{
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil)
        {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            while (nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }
    else
    {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev)
{
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    { // jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// prosedur untuk menampilkan isi list
void printList(linkedList List)
{
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List))
    {
        cout << "List kosong." << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node didalam list
int nbList(linkedList List)
{
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &List)
{
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}

// prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedList &list)
{
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;
    list.first->isidata = newData;
}

void updateLast(linkedList &list)
{
    if (isEmpty(list))
    {
        cout << "List kosong!" << endl;
    }
    else
    {
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama ;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;

    address nodeBantu = list.first;
    while (nodeBantu->next != Nil)
    {
        nodeBantu = nodeBantu->next;
    }

    nodeBantu->isidata = newData;
    }
}

void updateAfter(linkedList &list, address &prev)
{
    if (isEmpty(list))
    {
        cout << "List kosong!" << endl;
    }
    else
    {
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama ;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;

    prev->next->isidata = newData;
    }
}

void updateByNim(linkedList &list, string nim)
{
    if (!isEmpty(list))
    {
        address nodeBantu = FindNodebyData(list, nim);

        if (nodeBantu != Nil)
        {
            dataMahasiswa newData;
            cout << "Masukan nama baru : ";
            cin >> newData.nama;
            cout << "Masukan nim baru : ";
            cin >> newData.nim;
            cout << "Masukan umur baru : ";
            cin >> newData.umur;

            nodeBantu->isidata = newData;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

// prosedur-prosedur untuk searching data didalam list
address FindNodebyData(linkedList List, string data)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan nama atau nim yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu->isidata.nama == data || nodeBantu->isidata.nim == data)
            {
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
    return Nil;
}

void FindNodebyAddress(linkedList List, address node)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan alamat yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu == node)
            {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat Node : " << nodeBantu << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedList List, int nilaiAwal, int nilaiAkhir)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan semua node yang memiliki umur di dalam rentang nilaiAwal sampai nilaiAkhir */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas usia " << nilaiAwal << " dan dibawah " << nilaiAkhir << " ---" << endl;
        while (nodeBantu != Nil)
        {
            posisi++;
            int umur = nodeBantu->isidata.umur;
            if (umur > nilaiAwal && umur < nilaiAkhir)
            {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Tidak ada data node dalam range tersebut!" << endl;
        }
    }
    cout << endl;
}
```
## main.cpp
```C++
#include <iostream>
#include "list.h"
using namespace std;

int main(){
		linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    // updateFirst(List);
    // cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE FIRST ---" << endl;
    // printList(List);

    // updateLast(List);
    // cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE LAST ---" << endl;
    // printList(List);

    updateAfter(List, nodeC);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE AFTER ---" << endl;
    printList(List);

    updateByNim(List, "2211110014");
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE BY NIM ---" << endl;
    printList(List);
    
    return 0;
}
```

## Penjelasan Kode
Program ini menunjukkan cara menyimpan data mahasiswa ke dalam *singly linked list* dengan penerapan konsep ADT yang dipisah menjadi tiga file, yaitu `list.h`, `list.cpp`, dan `main.cpp`. File `list.h` berisi `struct mahasiswa` dengan tiga *field*, yaitu `umur` bertipe `int` serta `nama` dan `nim` bertipe `string`. Baris `typedef mahasiswa dataMahasiswa;` membuat `dataMahasiswa` menjadi nama lain dari `mahasiswa`. Kemudian ada `struct node` yang menyimpan `isidata` bertipe `dataMahasiswa` dan *pointer* `next`, serta `struct linkedList` yang hanya berisi *pointer* `first` sebagai penunjuk elemen pertama. Baris `typedef struct node *address;` membuat `address` menjadi nama lain dari *pointer* ke `node`, sedangkan `#define Nil NULL` membuat `Nil` dapat dipakai sebagai penanda *list* kosong atau akhir *list*. Baris `#ifndef List_h`, `#define List_h`, dan `#endif` mencegah file *header* ter-*include* berulang kali, `#include <iostream>` memuat pustaka `cin` dan `cout`, dan `using namespace std;` membuat `cout`, `endl`, dan `string` dapat ditulis tanpa awalan `std::`. Sisa isi *header* adalah deklarasi dua puluh fungsi dan prosedur, yaitu tiga belas untuk operasi dasar *list* (`isEmpty`, `createList`, `alokasi`, `dealokasi`, `printList`, tiga prosedur *insert*, tiga prosedur *delete*, `nbList`, dan `deleteList`), tiga untuk pencarian, dan empat untuk *update* data.

File `list.cpp` berisi isi dari fungsi-fungsi tersebut, dan setiap prosedur diberi komentar I.S. (*initial state*) serta F.S. (*final state*). Fungsi `isEmpty()` mengembalikan `true` jika `List.first` bernilai `Nil`, dan prosedur `createList()` mengisi `List.first` dengan `Nil` agar *list* kosong. Fungsi `alokasi()` membuat `node` baru dengan `new`, mengisi `nama`, `nim`, dan `umur` dari parameternya, lalu mengatur `next` menjadi `Nil` dan mengembalikan alamat `node` tersebut. Prosedur `dealokasi()` memutus `next` lalu membebaskan memori dengan `delete`. Prosedur `printList()` menelusuri *list* dari `first` sampai `Nil` dan mencetak `nama`, `nim`, dan `umur` setiap *node*, atau mencetak pesan "List kosong." jika *list* kosong. Untuk penyisipan, `insertFirst()` mengarahkan `next` elemen baru ke elemen pertama lalu memindahkan `first` ke elemen baru, `insertAfter()` menyisipkan elemen baru setelah `Prev` (dan mencetak pesan jika `Prev` bernilai `Nil`), dan `insertLast()` menjadikan elemen baru sebagai `first` jika *list* kosong atau menelusuri *list* sampai elemen terakhir lalu menyambungkan elemen baru di sana. Untuk penghapusan, `delFirst()` memindahkan `first` ke elemen berikutnya lalu mendealokasi elemen pertama, `delAfter()` menyambungkan `nodePrev` ke elemen setelah elemen yang dihapus lalu mendealokasinya, dan `delLast()` menelusuri *list* memakai dua *pointer* (`nodeHapus` dan `nodePrev`) agar elemen sebelum yang terakhir dapat diputus. Ketiga prosedur penghapusan akan mencetak pesan jika *list* kosong atau `nodePrev` tidak valid. Fungsi `nbList()` menghitung jumlah *node*, dan `deleteList()` menelusuri seluruh *node* untuk didealokasi, mengisi `first` dengan `Nil`, lalu mencetak "List sudah terhapus!". Prosedur `updateFirst()`, `updateLast()`, dan `updateAfter()` meminta pengguna memasukkan nama, NIM, dan umur baru lewat `cin`, lalu menimpa `isidata` pada *node* pertama, *node* terakhir, atau *node* setelah `prev`. Prosedur `updateByNim()` melakukan hal yang sama pada *node* yang dicari lewat `FindNodebyData()`. Untuk pencarian, `FindNodebyData()` mencocokkan parameter `data` dengan `nama` atau `nim` setiap *node* dan mencetak posisi serta isi *node* yang ditemukan, `FindNodebyAddress()` mencocokkan alamat *node*, dan `FindNodeByRange()` menampilkan *node* yang `umur`-nya lebih besar dari `nilaiAwal` dan lebih kecil dari `nilaiAkhir`. Parameter `linkedList &List` memakai tanda `&` (*call by reference*) pada prosedur yang mengubah *list* agar perubahannya tersimpan pada variabel aslinya di `main()`, sedangkan `printList()`, `nbList()`, dan fungsi-fungsi pencarian cukup dikirim dengan nilai karena isinya hanya dibaca.

Di dalam fungsi `main()`, dideklarasikan `List` bertipe `linkedList` serta lima *pointer* `nodeA` sampai `nodeE` bertipe `address` (hanya `nodeE` yang diberi nilai awal `Nil`). Setelah `createList(List)` dipanggil, setiap *node* dibuat dengan `alokasi()` dengan urutan argumen nama, NIM, lalu umur, yaitu Dhimas, Arvin, Rizal, Satrio, dan Joshua. Kelima *node* kemudian dimasukkan ke *list* secara bertahap: `nodeA` dengan `insertFirst()`, `nodeB` dengan `insertLast()`, `nodeC` dengan `insertAfter()` setelah `nodeA`, `nodeD` dengan `insertAfter()` setelah `nodeC`, dan `nodeE` dengan `insertLast()`, sehingga urutan akhirnya adalah A, C, D, B, E. Isi *list* dan jumlah *node* (5) lalu ditampilkan dengan `printList()` dan `nbList()`.

Setelah itu, `updateFirst()` dan `updateLast()` sengaja dijadikan komentar, sehingga yang dijalankan adalah `updateAfter(List, nodeC)`, yang meminta data baru lalu menimpa *node* setelah `nodeC`, yaitu `nodeD` (Satrio). Isi *list* ditampilkan kembali dengan `printList()`. Terakhir, `updateByNim(List, "2211110014")` mencari NIM milik Arvin (`nodeB`) dengan `FindNodebyData()`, yang mencetak bahwa data ditemukan pada posisi ke-4 beserta isinya. Namun, karena `FindNodebyData()` selalu mengembalikan `Nil` (baris terakhirnya `return Nil;`), kondisi `nodeBantu != Nil` pada `updateByNim()` tidak pernah terpenuhi, sehingga program tidak meminta input dan data Arvin tidak berubah. Akibatnya `printList()` yang terakhir menampilkan isi *list* yang sama seperti sebelumnya, lalu program berakhir dengan `return 0;`. Fungsi `FindNodebyAddress()`, `FindNodeByRange()`, `delFirst()`, `delLast()`, `delAfter()`, dan `deleteList()` sudah tersedia di `list.cpp` tetapi belum dipanggil di `main()`.


## Unguided

### Singlylist.h
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
#include <cstddef>

#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);
int totalInfo(List L);

#endif 
```
### Singlylist.cpp
```C++
#include "Singlylist.h"

void CreateList(List &L) {
    L.first = Nil;
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
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

int totalInfo(List L) {
    int total = 0;
    address P = L.first;
    while (P != Nil) {
        total += P->info;
        P = P->next;
    }
    return total;
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

    address hasil = findElm(L, 8);
    if (hasil != Nil) {
        cout << hasil->info << " ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    cout << "Total info dari kelima elemen adalah " << totalInfo(L) << endl;

    return 0;
}
```

##### Output 1

![Screenshot Output unguided 1_1](https://github.com/hass4ndonnydarmawan/109082500030_Hassan-Donny-Darmawan_SDT/blob/main/modul5/output/soal1.png)

## Penjelasan Kode
Program ini menunjukkan cara menyimpan data bilangan bulat ke dalam *singly linked list* dengan penerapan konsep ADT yang dipisah menjadi tiga file, yaitu `Singlylist.h`, `Singlylist.cpp`, dan `main.cpp`. File `Singlylist.h` berisi `typedef int infotype;` yang membuat `infotype` menjadi nama lain dari `int`, lalu `struct ElmList` yang menyimpan `info` bertipe `infotype` dan *pointer* `next`, serta `struct List` yang hanya berisi *pointer* `first` sebagai penunjuk elemen pertama. Baris `typedef struct ElmList *address;` membuat `address` menjadi nama lain dari *pointer* ke `ElmList`, sedangkan `#define Nil NULL` membuat `Nil` dapat dipakai sebagai penanda *list* kosong atau akhir *list*. Baris `#ifndef SINGLYLIST_H_INCLUDED`, `#define SINGLYLIST_H_INCLUDED`, dan `#endif` mencegah file *header* ter-*include* berulang kali, `#include <iostream>` memuat pustaka `cin` dan `cout`, `#include <cstddef>` memuat definisi `NULL`, dan `using namespace std;` membuat `cout` dan `endl` dapat ditulis tanpa awalan `std::`. Sisa isi *header* adalah deklarasi tujuh fungsi dan prosedur, yaitu lima operasi dasar untuk Latihan 2 (`CreateList`, `alokasi`, `dealokasi`, `printInfo`, dan `insertFirst`), satu fungsi pencarian `findElm` untuk Latihan 3, dan satu fungsi penjumlahan `totalInfo` untuk Latihan 4.

File `Singlylist.cpp` berisi isi dari fungsi-fungsi tersebut. Prosedur `CreateList()` mengisi `L.first` dengan `Nil` agar *list* kosong. Fungsi `alokasi()` membuat `ElmList` baru dengan `new`, mengisi `info` dengan parameter `x`, lalu mengatur `next` menjadi `Nil` dan mengembalikan alamat elemen tersebut. Prosedur `dealokasi()` membebaskan memori dengan `delete` lalu mengisi `P` dengan `Nil` agar tidak menjadi *dangling pointer*. Prosedur `printInfo()` menelusuri *list* dari `first` sampai `Nil` dan mencetak `info` setiap elemen dipisahkan spasi, lalu diakhiri dengan `endl`. Prosedur `insertFirst()` mengarahkan `next` elemen baru ke elemen pertama lalu memindahkan `first` ke elemen baru, sehingga elemen yang dimasukkan terakhir selalu berada di depan. Fungsi `findElm()` menelusuri *list* dan mengembalikan alamat elemen pertama yang `info`-nya sama dengan `x`, atau `Nil` jika sampai akhir *list* tidak ditemukan. Fungsi `totalInfo()` menelusuri seluruh elemen sambil menambahkan `info` ke variabel `total`, lalu mengembalikan hasilnya. Parameter `List &L` memakai tanda `&` (*call by reference*) pada prosedur yang mengubah *list*, yaitu `CreateList()` dan `insertFirst()`, agar perubahannya tersimpan pada variabel aslinya di `main()`, sedangkan `printInfo()`, `findElm()`, dan `totalInfo()` cukup dikirim dengan nilai karena isinya hanya dibaca.

Di dalam fungsi `main()`, dideklarasikan `L` bertipe `List` serta lima *pointer* `P1` sampai `P5` bertipe `address` (hanya `P5` yang diberi nilai awal `Nil`). Setelah `CreateList(L)` dipanggil, setiap elemen dibuat dengan `alokasi()` lalu langsung dimasukkan dengan `insertFirst()` dengan urutan nilai 2, 0, 8, 12, dan 9. Karena setiap elemen disisipkan di awal, *list* berkembang dari `2`, menjadi `0 2`, `8 0 2`, `12 8 0 2`, dan akhirnya `9 12 8 0 2`, sesuai dengan Gambar 5-1 pada modul. Isi *list* lalu ditampilkan dengan `printInfo()` sehingga keluarannya `9 12 8 0 2`.

Setelah itu, `findElm(L, 8)` dipanggil dan alamat hasilnya disimpan di *pointer* `hasil`. Jika `hasil` tidak sama dengan `Nil`, program mencetak `8 ditemukan dalam list` dengan mengambil nilai dari `hasil->info`, dan jika `Nil`, program mencetak pesan bahwa 8 tidak ditemukan. Karena nilai 8 ada di *list*, pesan pertama yang tampil. Terakhir, `totalInfo(L)` menjumlahkan 9 + 12 + 8 + 0 + 2 sehingga program mencetak `Total info dari kelima elemen adalah 31`, lalu berakhir dengan `return 0;`. Prosedur `dealokasi()` sudah tersedia di `Singlylist.cpp` tetapi belum dipanggil di `main()`, sehingga kelima elemen baru dibebaskan oleh sistem saat program selesai.

````

````
## Kesimpulan

Berdasarkan Modul 5 dan latihan soal yang dikerjakan, dapat disimpulkan bahwa operasi pencarian (*searching*) merupakan dasar dari banyak operasi lain pada *singly linked list*, dan penerapannya dengan *pointer* membuat data dapat ditelusuri, dihitung, dan diubah secara dinamis tanpa menentukan ukuran di awal.

*Searching* adalah operasi dasar *list* yang dilakukan dengan mengunjungi setiap *node* dari `first` dan berhenti setelah *node* yang dicari ditemukan. Hasil pencarian memudahkan operasi lain seperti *insert after*, *delete after*, dan *update*, karena operasi-operasi tersebut membutuhkan alamat *node* acuan. Pada modul, pencarian didefinisikan dalam beberapa bentuk, yaitu `findElm()` yang mencari elemen berdasarkan nilai `info` dan mengembalikan alamatnya atau `Nil` jika tidak ada, `fFindElm()` yang memeriksa apakah suatu alamat `P` ada di dalam *list* dan mengembalikan `true` atau `false`, serta `findBefore()` yang mengembalikan alamat elemen sebelum `P` atau `Nil` jika `P` berada di awal *list*. Seluruh operasi ini merupakan bagian dari ADT *singly linked list* yang pada bahasa C++ dipisah menjadi file `*.h` untuk deklarasi dan file `*.cpp` untuk implementasi. Pada latihan, ADT dibuat dalam tiga file, yaitu `Singlylist.h` yang berisi `infotype`, `address`, `ElmList`, `List`, dan deklarasi fungsi, `Singlylist.cpp` yang berisi isi fungsi, dan `main.cpp` sebagai *driver* yang menguji ADT.

Selain pencarian, modul ini memperkenalkan kumpulan operasi lain pada ADT *list*. Untuk penambahan elemen terdapat `insertFirst()`, `insertAfter()`, dan `insertLast()`, sedangkan untuk penghapusan terdapat `delFirst()`, `delLast()`, `delAfter()`, dan `delP()`. Untuk pemrosesan seluruh elemen terdapat `printInfo()` yang menampilkan semua `info` dan `nbList()` yang menghitung jumlah elemen, dan untuk pemrosesan terhadap *list* secara utuh terdapat `delAll()` yang menghapus dan mendealokasi semua elemen, `invertList()` yang membalik urutan elemen, serta `copyList()` dan `fCopyList()` yang menyalin *list*. Semua operasi ini pada dasarnya bekerja dengan menelusuri *list* dari `first` sampai `Nil` dan mengubah *pointer* `next`.

Pada latihan, `CreateList()` membentuk *list* kosong dengan mengisi `first` dengan `Nil`, `alokasi()` membuat elemen baru dengan `new`, dan `dealokasi()` membebaskan memorinya dengan `delete`. Prosedur `insertFirst()` menyisipkan elemen di awal *list* dengan dua langkah, yaitu `P->next = L.first;` lalu `L.first = P;`. Karena setiap elemen baru ditempatkan di depan, data yang dimasukkan berturut-turut 2, 0, 8, 12, dan 9 menghasilkan *list* dengan urutan 9, 12, 8, 0, 2, sesuai dengan keluaran pada modul. Fungsi `findElm()` pada Latihan 3 menelusuri *list* dan mengembalikan alamat elemen yang `info`-nya bernilai 8, sehingga program dapat mencetak bahwa 8 ditemukan dalam *list*. Fungsi `totalInfo()` pada Latihan 4 menelusuri seluruh elemen sambil menjumlahkan `info`-nya, sehingga diperoleh hasil 9 + 12 + 8 + 0 + 2 = 31. Kedua latihan ini menunjukkan bahwa pola penelusuran yang sama (mulai dari `first`, berhenti saat `Nil`) dapat dipakai untuk tujuan yang berbeda, yaitu mencari, menghitung, atau menampilkan data.

Parameter `List &L` pada `CreateList()` dan `insertFirst()` dikirim dengan *call by reference* agar perubahan pada *list* tersimpan pada variabel aslinya di `main()`, sedangkan `printInfo()`, `findElm()`, dan `totalInfo()` cukup dikirim dengan nilai karena isinya hanya dibaca. Karena *singly linked list* hanya dapat ditelusuri maju, pencarian dilakukan secara sekuensial, sehingga semakin panjang *list* semakin banyak elemen yang harus dikunjungi.

Dengan mengerjakan latihan ini, kita memahami bahwa penelusuran *list* adalah kunci dari hampir semua operasi pada *singly linked list*, dan ketelitian dalam menentukan kondisi berhenti (`Nil`) serta urutan perpindahan *pointer* menentukan benar tidaknya hasil operasi pada *list*.

## Referensi

[1] Modul Praktikum Struktur Data — Modul 5: Singly Linked List (Bagian Kedua), Fakultas Informatika, Telkom University.
<br>[2] Stroustrup, B. (2013). *The C++ Programming Language* (4th ed.). Addison-Wesley.
<br>[3] cplusplus.com. *Data Structures (struct)*. https://cplusplus.com/doc/tutorial/structures/
<br>[4] cplusplus.com. *Pointers*. https://cplusplus.com/doc/tutorial/pointers/
<br>[5] cplusplus.com. *Dynamic Memory*. https://cplusplus.com/doc/tutorial/dynamic/
<br>[6] cplusplus.com. *Functions*. https://cplusplus.com/doc/tutorial/functions/