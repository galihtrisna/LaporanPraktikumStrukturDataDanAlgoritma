#include <iostream>
using namespace std;
/// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};
Pohon *root, *baru, *current;
// Inisialisasi
void init()
{
    root = NULL;
}
// Cek Node
int isEmpty()
{
    if (root == NULL)
        return 1; // true
    else
        return 0; // false
}
// Buat Node Baru
void buatNode(char data)
{
    if (isEmpty() == 1)
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat menjadi root." << endl;
        current = root;
    }
    else
    {
        cout << "\n Pohon sudah dibuat" << endl;
    }
}
// Tambah Kiri
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Tidak ada tree, buat terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah child kiri ada atau tidak
        if (node->left != NULL)
        {
            // kalau ada
            cout << "\n Node " << node->data << " sudah ada child kiri!"
                 << endl;
            return NULL;
        }
        else
        {
            // kalau tidak ada
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}
// Tambah Kanan
Pohon *insertRight(char data, Pohon *node)
{
    if (root == NULL)
    {
        cout << "\n Tidak ada tree, buat terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah child kanan ada atau tidak
        if (node->right != NULL)
        {
            // kalau ada
            cout << "\n Node " << node->data << " sudah ada child kanan!"
                 << endl;
            return NULL;
        }
        else
        {
            // kalau tidak ada
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan" << baru->parent->data << endl;
            return baru;
        }
    }
}
// Ubah Data Tree
void update(char data, Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Tidak ada tree, buat terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}
// Lihat Isi Data Tree
void retrieve(Pohon *node)
{
    if (!root)
    {
        cout << "\n Tidak ada tree, buat terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\n Data node : " << node->data << endl;
        }
    }
}
// Cari Data Tree
void find(Pohon *node)
{
    if (!root)
    {
        cout << "\n Tidak ada tree, buat terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;
            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->data << endl;

            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;

            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data << endl;
        }
    }
}
// Penelurusan (Traversal)
// preOrder
void preOrder(Pohon *node = root)
{
    if (!root)
        cout << "\n Tidak ada tree, buat terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}
// inOrder
void inOrder(Pohon *node = root)
{
    if (!root)
        cout << "\n Tidak ada tree, buat terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}
// postOrder
void postOrder(Pohon *node = root)
{
    if (!root)
        cout << "\n Tidak ada tree, buat terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}
// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (!root)
        cout << "\n Tidak ada tree, buat terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}
// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (!root)
        cout << "\n Tidak ada tree, buat terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}
// Hapus Tree
void clear()
{
    if (!root)
        cout << "\n Tidak ada tree, buat terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}
// Cek Size Tree
int size(Pohon *node = root)
{
    if (!root)
    {
        cout << "\n Tidak ada tree, buat terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}
// Cek Height Level Tree
int height(Pohon *node = root)
{
    if (!root)
    {
        cout << "\n Tidak ada tree, buat terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}
// Karakteristik Tree
void charateristic()
{
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}
void showChild(Pohon *node)
{
    if (!root)
    {
        cout << "\n Tidak ada tree, buat terlebih dahulu!" << endl;
    }
    else
    {
        if (!node->left)
            cout << " Child kiri : (tidak ada child kiri)" << endl;
        else
            cout << " Child kiri : " << node->left->data << endl;
        if (!node->right)
            cout << " Child kanan : (tidak ada child kanan)" << endl;
        else
            cout << " Child lanan : " << node->right->data << endl;
    }
}
void showDescendant(Pohon *node = current)
{
    if (!root)
    {
        cout << "\n Tidak ada tree, buat terlebih dahulu!" << endl;
        return;
    }
    if (node != NULL)
    {
        if (node != current)
            cout << node->data << ", ";
        showDescendant(node->left);
        showDescendant(node->right);
    }
}
char inputData()
{
    char n;
    cout << "Masukkan data : ";
    cin >> n;
    return n;
}
void changeCurrent(char dest, Pohon *node = root)
{
    if (!root)
    {
        cout << "\n Tidak ada tree, buat terlebih dahulu!" << endl;
    }
    else if (current->data == dest)
        return;
    else
    {
        if (node->data == dest)
        {
            Pohon *temp = current;
            current = node;
            cout << "\n Current node : " << temp->data << " -> " << current->data << endl;
        }
        else
        {
            if (node->left != nullptr)
                changeCurrent(dest, node->left);
            if (node->right != nullptr)
                changeCurrent(dest, node->right);
        }
    }
}
int main()
{
    string line(12, '=');
    int choice;

    while (true)
    {
        string options[] = {
            "Tampilkan node",
            "Tampilkan node (detail)",
            "Tampilkan child",
            "Tampilkan descendant",
            "Ukuran tree",
            "Tinggi tree",
            "characteristic tree",
            "Buat root",
            "Tambah child kiri",
            "Tambah child kanan",
            "Ganti current node",
            "Update data node",
            "Traversal Pre-Order",
            "Traversal Post-Order",
            "Traversal In-Order",
            "Hapus tree",
            "Hapus subtree",
            "Hapus node",
        };
        int optSize = sizeof(options) / sizeof(options[0]);
        cout << endl;
        cout << "#" << line << " PROGRAM TREE " << line << "#" << endl;
        for (int i = 0; i < optSize; i++)
        {
            cout << i + 1 << ". " << options[i] << endl;
        }
        cout << "0. Keluar\n";
        cout << "\nNode saat ini : ";
        if (isEmpty())
        {
            cout << "-\n";
        }
        else
        {
            cout << current->data << endl;
        }
        cout << "Pilih menu [0 - " << optSize << "] : ";
        cin >> choice;

        switch (choice)
        {
        case 0:
        {
            cout << "\n\nKeluar dari aplikasi.\n";
            return 0;
            break;
        }
        case 1:
            retrieve(current);
            break;
        case 2:
            find(current);
            break;
        case 3:
            showChild(current);
            break;
        case 4:
            showDescendant();
            cout << endl;
            break;
        case 5:
            cout << "Ukuran tree : " << size() << endl;
            break;
        case 6:
            cout << "Tinggi tree : " << height() << endl;
            break;
        case 7:
            charateristic();
            break;
        case 8:
            buatNode(inputData());
            break;
        case 9:
            insertLeft(inputData(), current);
            break;
        case 10:
            insertRight(inputData(), current);
            break;
        case 11:
            changeCurrent(inputData());
            break;
        case 12:
            update(inputData(), current);
            break;
        case 13:
            preOrder();
            break;
        case 14:
            postOrder();
            break;
        case 15:
            inOrder();
            break;
        case 16:
            clear();
            break;
        case 17:
            deleteSub(current);
            break;
        case 18:
            deleteTree(current);
            break;
        default:
            cout << "Input Tidak Benar !\n";
        }
    }
}