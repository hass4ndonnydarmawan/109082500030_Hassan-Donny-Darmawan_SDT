#include <iostream>
#include <string>
using namespace std;

string terbilang(int n) {
    string satuan[] = {
        "nol", "satu", "dua", "tiga", "empat", "lima",
        "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"
    };

    if (n <= 11) {
        return satuan[n];
    } else if (n < 20) {
        return satuan[n - 10] + " belas";
    } else if (n < 100) {
        int puluh = n / 10;
        int sisa  = n % 10;
        string hasil = satuan[puluh] + " puluh";
        if (sisa > 0)
            hasil += " " + satuan[sisa];
        return hasil;
    } else if (n == 100) {
        return "seratus";
    }
    return "diluar jangkauan";
}

int main() {
    int angka;
    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka harus antara 0 sampai 100!" << endl;
        return 0;
    }

    cout << angka << " : " << terbilang(angka) << endl;

    return 0;
}
