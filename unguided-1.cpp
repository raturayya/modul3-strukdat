#include <iostream>
using namespace std;

struct Node {
    string nama;
    int usia;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Function to insert data at the beginning of the list
    void insertAtBeginning(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = head;
        head = newNode;
    }

    // Function to insert data at the end of the list
    void insertAtEnd(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to insert data after a specific node
    void insertAfter(string nama, int usia, string keyNama) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != keyNama) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Data dengan nama " << keyNama << " tidak ditemukan.\n";
            return;
        }

        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete a node with given nama
    void deleteNode(string nama) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->nama == nama) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->nama != nama) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Data dengan nama " << nama << " tidak ditemukan.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    // Function to display all data in the list
    void display() {
        Node* temp = head;
        cout << "Nama\tUsia\n";
        while (temp != nullptr) {
            cout << temp->nama << "\t" << temp->usia << endl;
            temp = temp->next;
        }
    }
};

int main() {

    cout << "Nama : Balqies L Ratu Rayya" << endl;
    cout << "NIM : 2311102313" << endl;
    
    LinkedList list;
    list.insertAtBeginning("Rayya", 19);
    list.insertAtEnd("John", 19);
    list.insertAtEnd("Jane", 20);
    list.insertAtEnd("Michael", 18);
    list.insertAtEnd("Yusuke", 19);
    list.insertAtEnd("Akechi", 20);
    list.insertAtEnd("Hoshino", 18);
    list.insertAtEnd("Karin", 18);

    cout << "Data awal:\n";
    list.display();

    cout << "\nHapus data Akechi:\n";
    list.deleteNode("Akechi");
    list.display();

    cout << "\nTambahkan data Futaba setelah John:\n";
    list.insertAfter("Futaba", 18, "John");
    list.display();

    cout << "\nTambahkan data Igor di awal:\n";
    list.insertAtBeginning("Igor", 20);
    list.display();

    cout << "\nUbah data Michael menjadi Reyn:\n";
    list.deleteNode("Michael");
    list.insertAtEnd("Reyn", 18);
    list.display();

    return 0;
}
