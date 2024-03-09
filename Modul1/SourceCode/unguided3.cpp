#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> mahasiswa;

    mahasiswa[2311102050] = "Galih Trisna";
    mahasiswa[2200000000] = "Bambang Cahyono";
    mahasiswa[2100000000] = "Suherman Tejo";

    cout  << "Data Mahasiswa : " << endl;
    cout << mahasiswa[2311102050] << endl
         << mahasiswa[2200000000] << endl
         << mahasiswa[2100000000] << endl;
}
