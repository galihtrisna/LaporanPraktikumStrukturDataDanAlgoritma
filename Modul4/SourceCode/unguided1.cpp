#include <iostream>
#include <iomanip>
using namespace std;

struct Node
{
    string nama;
    string nim;
    Node *next;
};

string tmp_nama;
Node *head;
Node *tail;

void init()
{
    head = NULL;
    tail = NULL;
}

bool isEmpty()
{
    return head == NULL;
}

void insertDepan(string nama, string nim)
{
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    if (isEmpty())
    {
        head = tail = baru;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}

void insertBelakang(string nama, string nim)
{
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    if (isEmpty())
    {
        head = tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

int hitungList()
{
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

void insertTengah(string nama, string nim, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru = new Node();
        baru->nama = nama;
        baru->nim = nim;
        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

void hapusDepan()
{
    if (!isEmpty())
    {
        Node *hapus = head;
        tmp_nama = head->nama;
        if (head->next != NULL)
        {
            head = head->next;
        }
        else
        {
            head = tail = NULL;
        }
        delete hapus;
        cout << "Data " << tmp_nama << " telah dihapus." << endl;
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void hapusBelakang()
{
    if (!isEmpty())
    {
        Node *hapus = tail;
        if (head != tail)
        {
            Node *bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tmp_nama = tail->nama;
            tail = bantu;
            tail->next = NULL;
            cout << "Data " << tmp_nama << " telah dihapus." << endl;
        }
        else
        {
            tmp_nama = tail->nama;
            cout << "Data " << tmp_nama << " telah dihapus." << endl;
            head = tail = NULL;
        }
        delete hapus;
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void hapusTengah(int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *bantu = head;
        Node *hapus;
        Node *sebelum = NULL;
        int nomor = 1;

        while (nomor < posisi)
        {
            sebelum = bantu;
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu;
        string tmp_nama = bantu->nama;
        if (sebelum != NULL)
        {
            sebelum->next = bantu->next;
        }
        else
        {
            head = bantu->next;
        }
        delete hapus;
        cout << "Data " << tmp_nama << " telah dihapus." << endl;
    }
}

void ubahDepan(string nama, string nim)
{
    if (!isEmpty())
    {
        tmp_nama = head->nama;
        head->nama = nama;
        head->nim = nim;
        cout << "Data " << tmp_nama << " telah diganti dengan data " << nama << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

void ubahTengah(string nama, string nim, int posisi)
{
    if (!isEmpty())
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            Node *bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            tmp_nama = bantu->nama;
            bantu->nama = nama;
            bantu->nim = nim;
            cout << "Data " << tmp_nama << " telah diganti dengan data " << nama << endl;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

void ubahBelakang(string nama, string nim)
{
    if (!isEmpty())
    {
        tmp_nama = tail->nama;
        tail->nama = nama;
        tail->nim = nim;
        cout << "Data " << tmp_nama << " telah diganti dengan data " << nama << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

void clearList()
{
    Node *bantu = head;
    Node *hapus;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

void tampil()
{
    Node *bantu = head;
    if (!isEmpty())
    {
        cout << "\nDATA MAHASISWA\n\n";
        cout << setw(37) << setfill('-') << "-" << setfill(' ') << endl;
        cout << "| " << setw(20) << left << "Nama"
             << " | " << setw(10) << "NIM"
             << " |" << endl;
        cout << setw(37) << setfill('-') << "-" << setfill(' ') << endl;
        while (bantu != NULL)
        {
            cout << "| " << setw(20) << left << bantu->nama << " | " << setw(10) << bantu->nim << " |" << endl;
            bantu = bantu->next;
        }
        cout << setw(37) << setfill('-') << "-" << setfill(' ') << endl;
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    int operasi, posisi;
    string nama;
    string nim;

    cout << endl
         << "============================================" << endl;
    cout << "  PROGRAM SINGLE LINKED LIST NON-CIRCULAR   " << endl;
    cout << "============================================" << endl;
    cout << "1. Tambah Data di Depan" << endl;
    cout << "2. Tambah Data di Belakang" << endl;
    cout << "3. Tambah Data di Tengah" << endl;
    cout << "4. Ubah Data di Depan" << endl;
    cout << "5. Ubah Data di Belakang" << endl;
    cout << "6. Ubah Data di Tengah" << endl;
    cout << "7. Hapus Data di Depan" << endl;
    cout << "8. Hapus Data di Belakang" << endl;
    cout << "9. Hapus Data di Tengah" << endl;
    cout << "10. Hapus Seluruh Data" << endl;
    cout << "11. Tampilkan Data" << endl;
    cout << "0. Keluar" << endl;
    cout << "============================================" << endl;
    do
    {
        cout << "Pilih Operasi: ";
        cin >> operasi;
        switch (operasi)
        {
        case 1:
            cout << endl
                 << "=== Tambah Depan ===" << endl
                 << endl;
            cout << "Masukkan Nama : ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM : ";
            cin >> nim;
            insertDepan(nama, nim);
            cout << endl
                 << endl
                 << "Data telah ditambahkan." << endl
                 << endl;
            break;
        case 2:
            cout << endl
                 << "=== Tambah Belakang ===" << endl
                 << endl;
            cout << "Masukkan Nama : ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM : ";
            cin >> nim;
            insertBelakang(nama, nim);
            cout << endl
                 << endl
                 << "Data telah ditambahkan." << endl
                 << endl;
            break;
        case 3:
            cout << endl
                 << "=== Tambah Tengah ===" << endl
                 << endl;
            cout << "Masukkan Nama : ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM : ";
            cin >> nim;
            cout << "Masukkan Posisi : ";
            cin >> posisi;
            insertTengah(nama, nim, posisi);
            cout << endl
                 << endl
                 << "Data telah ditambahkan." << endl
                 << endl;
            break;
        case 4:
            cout << endl
                 << "=== Ubah Depan ===" << endl
                 << endl;
            cout << "Masukkan Nama : ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM : ";
            cin >> nim;
            ubahDepan(nama, nim);
            break;
        case 5:
            cout << endl
                 << "=== Ubah Belakang ===" << endl
                 << endl;
            cout << "Masukkan Nama : ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM : ";
            cin >> nim;
            ubahBelakang(nama, nim);
            break;
        case 6:
            cout << endl
                 << "=== Ubah Tengah ===" << endl
                 << endl;
            cout << "Masukkan Nama : ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM : ";
            cin >> nim;
            cout << "Masukkan Posisi : ";
            cin >> posisi;
            ubahTengah(nama, nim, posisi);
            break;
        case 7:
            cout << endl
                 << "=== Hapus Depan ===" << endl
                 << endl;
            hapusDepan();
            break;
        case 8:
            cout << endl
                 << "=== Hapus Belakang ===" << endl
                 << endl;
            hapusBelakang();
            break;
        case 9:
            cout << endl
                 << "=== Hapus Tengah ===" << endl
                 << endl;
            cout << "Masukkan Posisi : ";
            cin >> posisi;
            hapusTengah(posisi);
            break;
        case 10:
            cout << endl
                 << "=== Hapus List ===" << endl
                 << endl;
            clearList();
            break;
        case 11:
            tampil();
            break;

        default:
            break;
        }
    } while (operasi != 0);
}