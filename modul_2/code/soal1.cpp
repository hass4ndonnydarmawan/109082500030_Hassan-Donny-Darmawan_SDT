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