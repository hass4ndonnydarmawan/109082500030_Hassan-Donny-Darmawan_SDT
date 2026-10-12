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