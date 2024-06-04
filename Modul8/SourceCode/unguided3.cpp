#include <iostream>

using namespace std;
int main()
{
    int n = 10;
    int data[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari = 4;
    int counter = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (data[i] == cari)
        {
            counter++;
        }
    }

    cout << "Program Sequential mencari angka 4" << endl
         << endl;
    cout << " data: 9, 4, 1, 4, 7, 10, 5, 4, 12, 4" << endl;
    cout << "banyak angka 4 pada array adalah : " << counter << endl;
    return 0;
}