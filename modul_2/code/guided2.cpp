#include <iostream>
using namespace std;

int main(){
    int x, y; // x dan y bertipe int
    int *px; // px merupakan variabel pointer menunjuk ke variabel int

    x = 87;
    px = &x;
    y = *px;

    cout << "Alamat x= " << &x << endl;
    cout << "Isi px= " << px << endl;
    cout << "Isi X= " << x << endl;
    cout << "Nilai yang ditunjuk px= " << *px << endl;
    cout << "Nilai y= " << y << endl;
return 0;
}