#include <iostream>
#include <iomanip>
using namespace std;

class Node
{
public:
    string namaProduk;
    int harga;
    Node *prev;
    Node *next;
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push(string namaProduk, int harga)
    {
        Node *newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr)
        {
            head->prev = newNode;
        }
        else
        {
            tail = newNode;
        }

        head = newNode;
    }

    void pushCenter(string namaProduk, int harga, int posisi)
    {
        if (posisi < 0)
        {
            cout << "Posisi harus bernilai non-negatif." << endl;
            return;
        }

        Node *newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;

        if (posisi == 0 || head == nullptr)
        {
            newNode->prev = nullptr;
            newNode->next = head;

            if (head != nullptr)
            {
                head->prev = newNode;
            }
            else
            {
                tail = newNode;
            }
            head = newNode;
        }
        else
        {
            Node *temp = head;
            int count = 0;
            while (temp != nullptr && count < posisi)
            {
                temp = temp->next;
                count++;
            }

            if (temp == nullptr)
            {
                newNode->prev = tail;
                newNode->next = nullptr;
                tail->next = newNode;
                tail = newNode;
            }
            else
            {
                newNode->prev = temp->prev;
                newNode->next = temp;
                temp->prev->next = newNode;
                temp->prev = newNode;
            }
        }
    }

    void pop()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        head = head->next;

        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }

        delete temp;
    }

    void popCenter(int posisi)
    {
        if (head == nullptr)
        {
            cout << "List kosong. Tidak ada yang bisa dihapus." << endl;
            return;
        }

        if (posisi < 0)
        {
            cout << "Posisi harus bernilai non-negatif." << endl;
            return;
        }

        if (posisi == 0)
        {
            Node *temp = head;
            head = head->next;

            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }

            delete temp;
        }
        else
        {
            Node *temp = head;
            int count = 0;
            while (temp != nullptr && count < posisi)
            {
                temp = temp->next;
                count++;
            }

            if (temp == nullptr)
            {
                cout << "Posisi melebihi ukuran list. Tidak ada yang dihapus." << endl;
                return;
            }

            if (temp == tail)
            {
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
        }
    }

    bool update(string oldNamaProduk, string newNamaProduk, int newHarga)
    {
        Node *current = head;

        while (current != nullptr)
        {
            if (current->namaProduk == oldNamaProduk)
            {
                current->namaProduk = newNamaProduk;
                current->harga = newHarga;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool updateCenter(string newNamaProduk, int newHarga, int posisi)
    {
        if (head == nullptr)
        {
            cout << "List kosong. Tidak ada yang dapat diperbarui." << endl;
            return false;
        }

        if (posisi < 0)
        {
            cout << "Posisi harus bernilai non-negatif." << endl;
            return false;
        }

        Node *current = head;
        int count = 0;

        while (current != nullptr && count < posisi)
        {
            current = current->next;
            count++;
        }

        if (current == nullptr)
        {
            cout << "Posisi melebihi ukuran list. Tidak ada yang diperbarui." << endl;
            return false;
        }

        current->namaProduk = newNamaProduk;
        current->harga = newHarga;
        return true;
    }

    void deleteAll()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List kosong." << endl;
            return;
        }

        Node *current = head;

        cout << setw(37) << setfill('-') << "-" << setfill(' ') << endl;
        cout << "| " << setw(20) << left << "Nama Produk"
             << " | " << setw(10) << "Harga"
             << " |" << endl;
        cout << setw(37) << setfill('-') << "-" << setfill(' ') << endl;

        while (current != nullptr)
        {
            cout << "| " << setw(20) << left << current->namaProduk << " | " << setw(10) << current->harga << " |" << endl;
            current = current->next;
        }
        cout << setw(37) << setfill('-') << "-" << setfill(' ') << endl;
    }
};

int main()
{
    DoublyLinkedList list;
    int choice;
    cout << endl
         << "Toko Skincare Purwokerto" << endl;
    do
    {
        cout << "1. Tambah data" << endl;
        cout << "2. Hapus data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan data" << endl;
        cout << "8. Exit" << endl;

        cout << "Pilihan : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string namaProduk;
            int harga;
            cout << "Masukkan nama produk: ";
            cin.ignore();
            getline(cin, namaProduk);
            cout << "Masukkan harga produk: ";
            cin >> harga;
            list.push(namaProduk, harga);
            break;
        }
        case 2:
        {
            list.pop();
            break;
        }
        case 3:
        {
            string newNamaProduk;
            int newHarga, posisi;
            cout << "Masukkan posisi produk: ";
            cin >> posisi;
            cout << "Masukkan nama baru produk: ";
            cin >> newNamaProduk;
            cout << "Masukkan harga baru produk: ";
            cin >> newHarga;
            bool updatedCenter = list.updateCenter(newNamaProduk, newHarga, posisi);
            if (!updatedCenter)
            {
                cout << "Data not found" << endl;
            }
            break;
        }
        case 4:
        {
            string namaProduk;
            int harga, posisi;
            cout << "Masukkan posisi data produk: ";
            cin >> posisi;
            cout << "Masukkan nama produk: ";
            cin.ignore();
            getline(cin, namaProduk);
            cout << "Masukkan harga produk: ";
            cin >> harga;
            list.pushCenter(namaProduk, harga, posisi);
            break;
        }
        case 5:
        {
            int posisi;
            cout << "Masukkan posisi data produk: ";
            cin >> posisi;
            list.popCenter(posisi);
            break;
        }
        case 6:
        {
            list.deleteAll();
            break;
        }
        case 7:
        {
            list.display();
            break;
        }
        case 8:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    } while (choice != 8);

    return 0;
}