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
    while (temp->next != NULL) temp = temp->next;
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

Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;  // Empty list

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;  // slow is the middle
}

int main() {
    Node* head = NULL;

    // 1 -> 2 -> 3 -> 4 -> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);
    cout << "Linked List: ";
    display(head);

    Node* mid = findMiddle(head);
    if (mid != NULL) cout << "Middle element is: " << mid->data << endl;
    else cout << "List is empty." << endl;
    return 0;
}
