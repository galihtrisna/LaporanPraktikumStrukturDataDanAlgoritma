#include <iostream>
using namespace std;
int main()
{
    string kalimat;
    int jumlah = 0;
    
    cout << "\t # PROGRAM PENGHITUNG HURUF VOKAL PADA KALIMAT #" << endl;
    cout << "\nMasukkan kalimat : ";
    getline(cin, kalimat);
    
    for (int i = 0; i < kalimat.length(); i++) {
        char huruf = tolower(kalimat[i]);
        if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o') jumlah++;
    }

    cout << "\nJumlah Huruf vokal pada kalimat adalah " << jumlah << " huruf.";
    return 0;
}