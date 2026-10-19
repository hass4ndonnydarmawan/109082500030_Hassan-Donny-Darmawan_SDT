#include <iostream>
#include "List.h"

using namespace std;

int main(){

    LinkedList L;
    address nodeA = Nil, nodeB = Nil, nodeC = Nil, nodeD = Nil, nodeE = Nil;
    createList(L);

    // urutan parameter alokasi: (age, name, id)
    nodeA = alokasi(20, "Dhimas", "2311102151");
    nodeB = alokasi(21, "Arvin",  "2311102152");
    nodeC = alokasi(20, "Budi",   "2311102153");
    nodeD = alokasi(22, "Citra",  "2311102154");
    nodeE = alokasi(19, "Dina",   "2311102155");

    // node yang sudah dialokasi harus dimasukkan ke list
    insertFirst(L, nodeA);          // A
    insertLast(L, nodeB);           // A B
    insertAfter(L, nodeA, nodeC);   // A C B
    insertFirst(L, nodeD);          // D A C B
    insertLast(L, nodeE);           // D A C B E

    cout << "Isi list:" << endl;
    printList(L);
    cout << "Jumlah node: " << nbList(L) << endl;

    delfirst(L);                    // hapus D
    delLast(L);                     // hapus E
    delAfter(L, L.first, Nil);      // hapus node setelah A (yaitu C)

    cout << "\nSetelah penghapusan:" << endl;
    printList(L);
    cout << "Jumlah node: " << nbList(L) << endl;

    delList(L);                     // bebaskan semua memori
    cout << "\nSetelah delList, jumlah node: " << nbList(L) << endl;

    return 0;
}