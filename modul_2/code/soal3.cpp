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