#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int TABLE_SIZE = 11;
string nim;
int nilai;
class HashNode
{
public:
    string nim;
    int nilai;
    HashNode(string nim, int nilai)
    {
        this->nim = nim;
        this->nilai = nilai;
    }
};
class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }
    void insert(string nim, int nilai)
    {
        int hash_val = hashFunc(nim);
        for (auto node : table[hash_val])
        {
            if (node->nim == nim)
            {
                node->nilai = nilai;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(nim,
                                               nilai));
    }
    void remove(string nim)
    {
        int hash_val = hashFunc(nim);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
        {
            if ((*it)->nim == nim)
            {
                table[hash_val].erase(it);
                return;
            }
            else
            {
                cout << "Tidak Ditemukan" << endl;
            }
        }
    }

    int searchByNim(string nim)
    {
        int hash_val = hashFunc(nim);
        for (auto node : table[hash_val])
        {
            if (node->nim == nim)
            {
                // return node->nilai;
                cout << "\nMahasiswa dengan NIM " << node->nim << " memiliki nilai " << node->nilai << endl;
            }
        }
        return 0;
    }
    int searchByNilai(int minNilai, int maxNilai)
    {
        for (const auto &bucket : table)
        {
            for (auto node : bucket)
            {
                if (node->nilai >= minNilai && node->nilai <= maxNilai)
                {
                    cout << "[ NIM : " << node->nim << ", NILAI : " << node->nilai << " ]" << endl;
                }
            }
        }
        return 0;
    }

    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[ NIM : " << pair->nim << ", NILAI : " << pair->nilai << " ]";
                }
            }
            cout << endl;
        }
    }
};
int main()
{
    HashMap mahasiswa_map;
    bool menu = true;
    int choice;
    do
    {

        cout << "======================= # Data Mahasiswa # =======================" << endl;
        mahasiswa_map.print();
        cout << "======================= # ============== # =======================" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Cari berdasarkan NIM" << endl;
        cout << "4. Cari berdasarkan Nilai" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan Nilai: ";
            cin >> nilai;

            mahasiswa_map.insert(nim, nilai);
            break;
        case 2:
            cout << "Masukkan NIM: ";
            cin >> nim;
            mahasiswa_map.remove(nim);
            break;
        case 3:
            cout << "Masukkan NIM: ";
            cin >> nim;
            mahasiswa_map.searchByNim(nim);

            break;
        case 4:
            int maxNilai, minNilai;
            cout << "Masukkan Nilai Tertinggi: ";
            cin >> maxNilai;
            cout << "Masukkan Nilai Terendah: ";
            cin >> minNilai;
            mahasiswa_map.searchByNilai(minNilai, maxNilai);
            break;
        case 0:
            menu = false;
            break;

        default:
            break;
        }

    } while (menu == true);
    return 0;
}