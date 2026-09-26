#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;

    cout << "output:" << endl;
    for (int i = n; i >= 0; i--) {
        // spasi di depan agar membentuk kerucut (rata tengah)
        for (int k = 0; k < (n - i) * 2; k++) {
            cout << " ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "*";

        for (int j = 1; j <= i; j++) {
            cout << " " << j;
        }

        cout << endl;
    }

    return 0;
}