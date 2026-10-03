#include <iostream>
using namespace std;

void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void tukarReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int x, y, z;

    cout << "Masukkan x: ";
    cin >> x;
    cout << "Masukkan y: ";
    cin >> y;
    cout << "Masukkan z: ";
    cin >> z;

    cout << "\nSebelum: x = " << x << ", y = " << y << ", z = " << z << endl;

    tukarPointer(&x, &y, &z);
    cout << "Pointer: x = " << x << ", y = " << y << ", z = " << z << endl;

    tukarReference(x, y, z);
    cout << "Reference: x = " << x << ", y = " << y << ", z = " << z << endl;

    return 0;
}