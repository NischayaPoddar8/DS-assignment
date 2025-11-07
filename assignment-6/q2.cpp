#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

void print(Node*head){
    if(!head)return;
    Node*p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
    
    cout<<head->data;
}

int main(){
    Node*a=new Node(20);
    Node*b=new Node(100);
    Node*c=new Node(40);
    Node*d=new Node(80);
    Node*e=new Node(60);
    a->next=b;b->next=c;c->next=d;d->next=e;e->next=a;
    print(a);
}
