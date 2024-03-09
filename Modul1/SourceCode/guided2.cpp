#include <stdio.h>

struct Mahasiswa
{
    const char *name;
    const char *adresss;
    int age;
};

int main()
{
    struct Mahasiswa msh1, msh2;

    msh1.name = "Dian";
    msh1.adresss = "Mataram";
    msh1.age = 22;
    msh2.name = "Bambang";
    msh2.adresss = "Surabaya";
    msh2.age = 23;

    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", msh1.name);
    printf("Alamat: %s\n", msh1.adresss);
    printf("Umur: %d\n" , msh1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", msh2.name);
    printf("Alamat: %s\n", msh2.adresss);
    printf("Umur: %d\n" , msh2.age);
    return 0;
};