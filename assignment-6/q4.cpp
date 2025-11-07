#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node *next, *prev;
    Node(char x){
        data = x;
        next = prev = NULL;
    }
};

bool check(Node *head, Node *tail){
    while(head != tail && tail->next != head){
        if(head->data != tail->data) return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main(){
    Node *a = new Node('r');
    Node *b = new Node('a');
    Node *c = new Node('d');
    Node *d = new Node('a');
    Node *e = new Node('r');

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    e->prev = d;
    d->prev = c;
    c->prev = b;
    b->prev = a;

    cout << check(a, e);
}
