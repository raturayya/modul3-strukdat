#include <iostream>
using namespace std;

class Node {
public:
    string namaProduk;
    int harga;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(string namaProduk, int harga) {
        Node* newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void insertAfter(string namaProduk, int harga, string keyNamaProduk) {
        Node* current = head;
        while (current != nullptr && current->namaProduk != keyNamaProduk) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Data dengan nama produk " << keyNamaProduk << " tidak ditemukan.\n";
            return;
        }

        Node* newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = current;
        newNode->next = current->next;

        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
    }

    void deleteNode(string namaProduk) {
        Node* current = head;
        while (current != nullptr && current->namaProduk != namaProduk) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Data dengan nama produk " << namaProduk << " tidak ditemukan.\n";
            return;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        delete current;
    }

    bool update(string namaProduk, int newHarga) {
        Node* current = head;
        while (current != nullptr && current->namaProduk != namaProduk) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Data dengan nama produk " << namaProduk << " tidak ditemukan.\n";
            return false;
        }

        current->harga = newHarga;
        return true;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        cout << "Nama Produk\tHarga" << endl;
        while (current != nullptr) {
            cout << current->namaProduk << "\t\t" << current->harga << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main() {

    cout << "Nama : Balqies L Ratu Rayya" << endl;
    cout << "NIM : 2311102313" << endl;
    
    DoublyLinkedList list;
    list.push("Originote", 60000);
    list.push("Somethinc", 150000);
    list.push("Skintific", 100000);
    list.push("Wardah", 50000);
    list.push("Hanasui", 30000);

    while (true) {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string namaProduk;
                int harga;
                cout << "Enter nama produk: ";
                cin >> namaProduk;
                cout << "Enter harga: ";
                cin >> harga;
                list.push(namaProduk, harga);
                break;
            }
            case 2: {
                string namaProduk;
                cout << "Enter nama produk yang akan dihapus: ";
                cin >> namaProduk;
                list.deleteNode(namaProduk);
                break;
            }
            case 3: {
                string namaProduk;
                int newHarga;
                cout << "Enter nama produk yang akan diupdate: ";
                cin >> namaProduk;
                cout << "Enter harga baru: ";
                cin >> newHarga;
                bool updated = list.update(namaProduk, newHarga);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                string namaProduk, keyNamaProduk;
                int harga;
                cout << "Enter nama produk yang akan ditambahkan setelahnya: ";
                cin >> keyNamaProduk;
                cout << "Enter nama produk baru: ";
                cin >> namaProduk;
                cout << "Enter harga: ";
                cin >> harga;
                list.insertAfter(namaProduk, harga, keyNamaProduk);
                break;
            }
            case 5: {
                // Implement delete specific position if needed
                break;
            }
            case 6: {
                list.deleteAll();
                break;
            }
            case 7: {
                cout << "Data Produk:\n";
                list.display();
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
