#include <iostream>
using namespace std;

int umur(int tahun) {
    return 2024-tahun;
}

bool kabisat(int tahun) {
    if (tahun % 4 == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int tahun;
    cout << "# CEK UMUR DAN KABISAT #" << endl;
    cout << "Masukan tahun lahir kamu > "; cin >> tahun;
    cout << "\nUmur Kamu = "<<umur(tahun)<<" Tahun" << endl;
    if (kabisat(tahun)) {
        cout << "Kamu lahir di tahun kabisat";
    } else {
        cout << "Kamu tidak lahir di tahun kabisat";
    }
    
}