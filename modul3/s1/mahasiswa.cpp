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
