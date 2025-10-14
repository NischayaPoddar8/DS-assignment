#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList(){
        head = nullptr;
    }

    // (a) Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // (b) Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // (c) Insert before/after a specific node
    void insertBefore(int target, int val) {
        if (!head) return;
        if (head->data == target) { insertAtBeginning(val); return; }
        Node* temp = head;
        while (temp->next && temp->next->data != target) temp = temp->next;
        if (temp->next) {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void insertAfter(int target, int val) {
        Node* temp = head;
        while (temp && temp->data != target) temp = temp->next;
        if (temp) {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // (d) Delete from beginning
    void deleteFromBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // (e) Delete from end
    void deleteFromEnd() {
        if (!head) return;
        if (!head->next) { delete head; head = nullptr; return; }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    // (f) Delete a specific node
    void deleteNode(int target) {
        if (!head) return;
        if (head->data == target) { deleteFromBeginning(); return; }
        Node* temp = head;
        while (temp->next && temp->next->data != target) temp = temp->next;
        if (temp->next) {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }

    // (g) Search for a node
    void searchNode(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Found " << key << " at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << key << " not found!" << endl;
    }

    // (h) Display list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, key;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert Before Node\n4. Insert After Node\n";
        cout << "5. Delete from Beginning\n6. Delete from End\n7. Delete Specific Node\n";
        cout << "8. Search Node\n9. Display List\n00. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: cout << "Enter value: "; cin >> val; list.insertAtBeginning(val); break;
        case 2: cout << "Enter value: "; cin >> val; list.insertAtEnd(val); break;
        case 3: cout << "Enter target & value: "; cin >> key >> val; list.insertBefore(key, val); break;
        case 4: cout << "Enter target & value: "; cin >> key >> val; list.insertAfter(key, val); break;
        case 5: list.deleteFromBeginning(); break;
        case 6: list.deleteFromEnd(); break;
        case 7: cout << "Enter node to delete: "; cin >> key; list.deleteNode(key); break;
        case 8: cout << "Enter key to search: "; cin >> key; list.searchNode(key); break;
        case 9: list.display(); break;
        }
    } while (choice != 0);

    return 0;
}
