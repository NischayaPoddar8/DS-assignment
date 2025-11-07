#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;   
        curr->next = prev;   
        prev = curr;         
        curr = next;        
    }

    return prev;  // new head
}

int main() {
    Node* head = NULL;

    // 1 -> 2 -> 3 -> 4 -> NULL
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);

    cout << "Original List: ";
    display(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    display(head);

    return 0;
}
