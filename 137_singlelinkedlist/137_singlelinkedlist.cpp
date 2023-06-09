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

bool serachNode(int nim, node* current, node* previous) {
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

bool deleteNode(int nim) {
    node* current = START;
    node* previous = START;
    if (serachNode(nim, previous, current) == false)
        return false;
    previous->next = current->next;
    if (current == START)
        START = current->next;
    return true;
}

bool listEmpty() {
    if (START == NULL)
        return true;
    else
        return false;
}

void traverse() {
    if (listEmpty()) {
        cout << "List Kosong" << endl;
        system("pause");
        system("cls");
        return;
    }
    else
    {
        node* currentNode = START;
        while (currentNode != NULL)
        {
            cout << "NIM" << currentNode->noMhs << ", Nama: " << currentNode->name << endl;
            currentNode = currentNode->next;
        }
    }
}

void searchData() {
    if (listEmpty()) {
        cout << "List Kosong" << endl;
        system("pause");
        system("cls");
        return;
    }
    else
    {
        int nim;
        cout << "Masukan NIM: ";
        cin >> nim;
        node* currentNode = START;
        while (currentNode != NULL)
        {
            if (currentNode->noMhs == nim)
            {
                cout << "NIM" << currentNode->noMhs << ", Nama: " << currentNode->name << endl;
                return;
            }
            currentNode = currentNode->next;
        }
        cout << "Data tidak ditemukan" << endl;
    }
}

int main()
{
    int pilihan;
    do //jalankan sekali lalu ulangi ketika while true
    {
        try {// penaganan pengecualian
            cout << "1. Tambah Data" << endl;
            cout << "2. Hapus Data" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Cari data" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilihan: " << endl;
            cin >> pilihan;
            switch (pilihan)
            {
            case 1:
                addnode();
                cout << "Data Berhasil Ditambahkan" << endl;
                system("pause");
                system("cls");
                break;
            case 2:
                if (listEmpty()) {
                    cout << "list kosong" << endl;
                    system("pause");
                    system("cls");
                    break;
                }
                int nim;
                cout << "Masukan NIM: ";
                cin >> nim;
                if (deleteNode(nim)) {
                    cout << "nim: " << nim << " berhasil dihapus" << endl;
                    system("pause");
                    system("cls");
                }
                else
                {
                    cout << "Data tidak ditemukan" << endl;
                }
                break;
            case 3:
                traverse();
                break;
            case 4:
                searchData();
                break;
            case 5:
                break;
            default:
                cout << "pilihan tidak ada" << endl;
                break;
            }
        }
        catch (exception e) {// lakukan penanganan sesuai apa yang terjadi di try
            cout << "Terjadi kesalahan" << endl;
        }
    } while (pilihan !=5);
}
