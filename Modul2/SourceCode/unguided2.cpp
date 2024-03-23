#include <iostream>
using namespace std;
int main()
{
    int rows, cols, depths;
    cout << "Masukkan ukuran dari array 3 dimensi" << endl;
    cout << "jumlah baris = ";
    cin >> rows;
    cout << "jumlah kolom = ";
    cin >> cols;
    cout << "jumlah layer = ";
    cin >> depths;
    int arr[depths][rows][cols];
    for (int x = 0; x < depths; x++)
    {
        for (int y = 0; y < rows; y++)
        {
            for (int z = 0; z < cols; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    for (int x = 0; x < depths; x++)
    {
        for (int y = 0; y < rows; y++)
        {
            for (int z = 0; z < cols; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
        cout << endl;
    }
    cout << endl;
    for (int x = 0; x < depths; x++)
    {
        for (int y = 0; y < rows; y++)
        {
            for (int z = 0; z < cols; z++)
            {
                cout << arr[x][y][z] << " " << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}