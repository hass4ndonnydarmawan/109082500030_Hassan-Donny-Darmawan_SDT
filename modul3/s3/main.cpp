#include <iostream>
#include "tukar.h"

using namespace std;

int main (){

    int arrayA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arrayB[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int a = 10, b = 20;
    int *ptr1 = &a;
    int *ptr2 = &b;
    int baris, kolom;

    cout << "Array A : " << endl;
    tampilArray(arrayA);
    cout << "Array B : " << endl;
    tampilArray(arrayB);

    cout << "masukan baris (0-2) : ";
    cin >> baris;
    cout << "masukan kolom (0-2) : ";
    cin >> kolom;

    tukarArray(arrayA, arrayB, baris, kolom);

    cout << "Array A setelah ditukar : " << endl;
    tampilArray(arrayA);
    cout << "Array B setelah ditukar : " << endl;
    tampilArray(arrayB);

    cout << "isi variabel sebelum ditukar : " << *ptr1 << " dan " << *ptr2 << endl;
    tukarPointer(ptr1, ptr2);
    cout << "isi variabel setelah ditukar : " << *ptr1 << " dan " << *ptr2 << endl;

    return 0;
}
