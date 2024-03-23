#include <iostream>
using namespace std;

int main()
{
    int menu, maks;
    float minimum, maksimum, total = 0, rata = 0;
    cout << "Masukkan jumlah data yang ingin diinput : ";
    cin >> maks;
    float arr[maks];
    for (int i = 0; i < maks; i++)
    {
        cout << "Data ke-" << i + 1 << " : ";
        cin >> arr[i];
    }
    do
    {
        cout << "\nPilih Menu (1-3)\n1. Nilai Maksimum\n2. Nilai Minimum\n3. Nilai Rata rata\n4. Close\nPilih > ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            maksimum = arr[0];
            for (int i = 0; i < maks; i++)
            {
                if (arr[i] > maksimum)
                {
                    maksimum = arr[i];
                }
            }
            cout << "Nilai maksimum adalah " << maksimum << endl;

            break;
        case 2:
            minimum = arr[0];
            for (int i = 0; i < maks; i++)
            {
                if (arr[i] < minimum)
                {
                    minimum = arr[i];
                }
            }
            cout << "Nilai minimum adalah " << minimum << endl;
            break;

        case 3:
            for (int i = 0; i < maks; i++)
            {
                total += arr[i];
            }
            rata = total / maks;
            cout << "Nilai rata rata adalah " << rata << endl;
            break;

        case 4:
            cout << "Program telah berakhir." << endl;
            break;
        default:
            cout << "inputan salah" << endl;
        }
    } while (menu != 4);
}
