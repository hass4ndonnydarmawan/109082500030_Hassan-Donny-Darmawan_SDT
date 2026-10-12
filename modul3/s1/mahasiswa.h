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
