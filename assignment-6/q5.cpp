#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

bool isc(Node *head){
    if(!head) return false;
    Node *p = head->next;
    while(p && p != head){
        p = p->next;
    }
    return p == head;
}

int main(){
    Node *a = new Node(10);
    Node *b = new Node(20);

    a->next = b;
    b->next = a;

    cout << isc(a);
}
