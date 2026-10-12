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
