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
    if (START == NULL || nim <= START->noMhs) {//pengecekan kondisi dimana node akan ditempatkan
        if (START != NULL && nim == START->noMhs) {
            cout << "NIM sudah ada" << endl;
            return;
        }
        NodeBaru->next = START;
        START = NodeBaru;
        return;
    }

    node* previous = START;
    node* current = START;

    while ((current != NULL) && (nim >= current->noMhs))
    {
        if (nim == current->noMhs) {
            cout << "NIM sudah ada" << endl;
            return;
        }
        previous = current;
        current = current->next;
    }

    NodeBaru->next = current;
    previous->next = NodeBaru;
}

bool serachNode(int nim, Node* current, Node* previous) {
    previous = START;
    current = START;
    while (current != NULL && nim > current->noMhs)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return false;
    }
    else if (current->noMhs == nim) {
        return true;
    }
    else {
        return false;
    }
}
int main()
{
    std::cout << "Hello World!\n";
}
