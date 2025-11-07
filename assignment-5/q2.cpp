#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList(): head(nullptr) {}

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    int countAndDelete(int key) {
            int count = 0;
            while (head && head->data == key) { 
            Node* temp = head; 
            head = head->next; 
            delete temp; 
            count++; 
    }

        Node* curr = head;
        while (curr && curr->next) {
            if (curr->next->data == key) {
                Node* del = curr->next;
                curr->next = del->next;
                delete del;
                count++;
            } else curr = curr->next;
        }
        return count;
    }

    void display() {
        Node* temp = head;
        while (temp) { cout << temp->data << " -> "; temp = temp->next; }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    list.insertEnd(1); 
    list.insertEnd(2); 
    list.insertEnd(1);
    list.insertEnd(2); 
    list.insertEnd(1); 
    list.insertEnd(3); 
    list.insertEnd(1);

    cout << "Original List: "; 
    list.display();
    int count = list.countAndDelete(1);
    cout << "Occurrences deleted: " << count << endl;
    cout << "List after deletion: "; 
    list.display();
}
