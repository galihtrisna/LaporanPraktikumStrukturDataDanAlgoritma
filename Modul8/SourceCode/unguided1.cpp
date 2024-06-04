#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

string kalimat;
char c;

void toLower() {
    string tmp;
    for (int i = 0; i < kalimat.length(); i++) {
        tmp += tolower(kalimat[i]);
    }
    kalimat = tmp;
}

void selection_sort()
{
    int min, i, j;
    char tmp;
    toLower();
    for (i = 0; i < kalimat.length(); i++)
    {
        min = i;
        for (j = i + 1; j < kalimat.length(); j++)
        {
            if (kalimat[j] < kalimat[min])
            {
                min = j;
            }
        }
        tmp = kalimat[i];
        kalimat[i] = kalimat[min];
        kalimat[min] = tmp;
    }
}
void binarysearch()
{
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = kalimat.length();
    while (b_flag == 0 && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (kalimat[tengah] == c)
        {
            b_flag = 1;
            break;
        }
        else if (kalimat[tengah] < c)
            awal = tengah + 1;
        else
            akhir = tengah - 1;
    }
    if (b_flag == 1)
        cout << "\n Karakter '" << c << "' ditemukan pada index ke - " << tengah << endl;
    else
        cout << "\nData tidak ditemukan\n";
}
int main()
{
    cout << "\t BINARY SEARCH " << endl;
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat);
    cout << "\nMasukkan karakter yang ingin Anda cari : ";
    cin >> c;
    c = tolower(c);
    cout << "\nKalimat yang diurutkan berdasarkan karakter : ";
    selection_sort();
    for (int x = 0; x < kalimat.length(); x++)
        cout << kalimat[x];
    cout << endl;
    binarysearch();
    return EXIT_SUCCESS;
}