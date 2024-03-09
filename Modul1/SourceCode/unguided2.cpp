#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;


// Contoh Struct
struct barang {
    string nama;
    int harga, jumlah;
};

// Contoh Class
class Jasa
{
private:
    string nama;
    int waktu;
    int harga;
public:
    // Konstruktor untuk inisialisasi objek Jasa
    Jasa(string namaJasa, int waktuJasa, int hargaJasa) {
        nama = namaJasa;
        waktu = waktuJasa;
        harga = hargaJasa;
    }

    // Method untuk menampilkan informasi jasa
    void tampilkanInfo() {
        cout << "Nama Jasa   : " << nama << endl;
        cout << "Durasi jasa : " << waktu << " menit" << endl;
        cout << "Harga       : Rp. " << harga << endl << endl;
    }
};
int main() {

    // Contoh Penggunaan Struct
    barang sabun, kecap;

    sabun.nama = "Sabun Wangi pake banget";
    sabun.harga = 5000;
    sabun.jumlah =  12;

    kecap.nama = "Kecap Manis cap Hitam";
    kecap.harga = 4000;
    kecap.jumlah = 13;

    cout << "Nama Barang : " << sabun.nama << endl
         << "Harga       : Rp." << sabun.harga << endl
         << "Jumlah      : " << sabun.jumlah << endl << endl;

    
    cout << "Nama Barang : " << kecap.nama << endl
         << "Harga       : Rp." << kecap.harga << endl
         << "Jumlah      : " << kecap.jumlah << endl << endl;

    // Contoh Penggunaan Class
    Jasa cuci("Cuci Mobil Kilat", 30, 40000);
    Jasa kebersihan("Jasa Pembersihan Rumah", 60, 75000);
    cuci.tampilkanInfo();
    kebersihan.tampilkanInfo();
}
