#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node*prev;
    Node(int x){
        data=x;
        next=prev=NULL;
    }
};

int sizedll(Node*head){
    int c=0;
    while(head){c++;head=head->next;}
    return c;
}

int sizecll(Node*head){
    if(!head)return 0;
    int c=0;
    Node*p=head;

    do{
        c++;
        p=p->next;
    }while(p!=head);
    
    return c;
}

int main(){
    Node*a=new Node(1);
    Node*b=new Node(2);
    Node*c=new Node(3);
    a->next=b;
    b->next=c;
    cout<<sizedll(a)<<endl;

    Node*x=new Node(10);
    Node*y=new Node(20);
    Node*z=new Node(30);

    x->next=y;
    y->next=z;
    z->next=x;

    cout<<sizecll(x)<<endl;
}
