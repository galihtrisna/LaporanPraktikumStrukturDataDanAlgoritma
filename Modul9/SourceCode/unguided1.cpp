#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{
    int verCount;

    cout << "Masukkan jumlah simpul : ";
    cin >> verCount;

    string vertecies[verCount];
    int edgeValues[verCount][verCount];
    cout << "Masukkan nama simpul,\n";
    for (int i = 0; i < verCount; i++) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> vertecies[i];
    }

    cout << "Masukkan bobot antar simpul,\n";
    for (int i = 0; i < verCount; i++) {
        for (int j = 0; j < verCount; j++) {
            cout << vertecies[i] << "->" << vertecies[j] << " : ";
            cin >> edgeValues[i][j];
        }
    }

    cout << endl << setw(10) << " ";
    for (int i = 0; i < verCount; i++) {
        cout << setw(10) << vertecies[i];
    }
    cout << endl;

    for (int i = 0; i < verCount; i++) {
        cout << setw(10) << vertecies[i];
        for (int j = 0; j < verCount; j++) {
            cout << setw(10) << edgeValues[i][j];
        }
        cout << endl;
    }

    return 0;
}