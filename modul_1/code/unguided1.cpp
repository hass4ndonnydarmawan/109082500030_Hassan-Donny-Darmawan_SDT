#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama  : ";
    cin >> a;
    cout << "Masukkan bilangan kedua    : ";
    cin >> b;

    cout << "\nHasil operasi:" << endl;
    cout << a << " + " << b << " = " << (a + b) << endl;
    cout << a << " - " << b << " = " << (a - b) << endl;
    cout << a << " * " << b << " = " << (a * b) << endl;

    if (b != 0)
        cout << a << " / " << b << " = " << (a / b) << endl;
    else
        cout << a << " / " << b << " = tidak terdefinisi (pembagian dengan nol)" << endl;

    return 0;
}
