#include <iostream>
using namespace std;

struct node {
    int noMhs;
    string name;
    node* next;
};

node* START = NULL; //pointer start (menunjuk node pertama) yang bernilai null (Kosong)

void addnode() { // simpan node baru ke linked list
    int nim;
    string nama;
    node* NodeBaru = new node();
    cout << "Masukan NIM: ";
    cin >> nim;
    cout << "Masukan Nama: ";
    cin >> nama;
    NodeBaru->noMhs = nim;
    NodeBaru->name = nama;
}
int main()
{
    std::cout << "Hello World!\n";
}
