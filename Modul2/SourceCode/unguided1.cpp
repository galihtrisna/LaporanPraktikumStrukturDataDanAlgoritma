#include <iostream>
using namespace std;

int main()
{
    int maks = 10;
    int n[maks];
    cout << "Masukan Data Array" << endl;
    for (int i = 0; i < maks; i++)
    {
        cout << "angka ke-" << i + 1 << " : ";
        cin >> n[i];
    }
    cout << "\nData Array : ";
    for (int i = 0; i < maks; i++)
    {
        cout << n[i] << " ";
    }
    cout << "\nNomor Genap : ";
    for (int i = 0; i < maks; i++)
    {
        if (n[i] % 2 == 0)
        {
            cout << n[i] << ", ";
        }
    }
    cout << "\nNomor Genap : ";
    for (int i = 0; i < maks; i++)
    {
        if (n[i] % 2 == 1)
        {
            cout << n[i] << ", ";
        }
    }
}