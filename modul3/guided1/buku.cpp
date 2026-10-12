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
