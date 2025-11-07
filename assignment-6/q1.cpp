#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next,*prev;
    Node(int x){data=x;next=prev=NULL;}
};

Node *dhead=NULL,*dtail=NULL;
Node *chead=NULL;

void dinsfirst(int x){
    Node*t=new Node(x);
    if(!dhead){dhead=dtail=t;return;}
    t->next=dhead;
    dhead->prev=t;
    dhead=t;
}

void dinslast(int x){
    Node*t=new Node(x);
    if(!dhead){dhead=dtail=t;return;}
    dtail->next=t;
    t->prev=dtail;
    dtail=t;
}

void cinsfirst(int x){
    Node*t=new Node(x);
    if(!chead){chead=t;chead->next=chead;return;}
    Node*p=chead;
    while(p->next!=chead)p=p->next;
    t->next=chead;
    p->next=t;
    chead=t;
}

void cinslast(int x){
    Node*t=new Node(x);
    if(!chead){chead=t;chead->next=chead;return;}
    Node*p=chead;
    while(p->next!=chead)p=p->next;
    p->next=t;
    t->next=chead;
}

int main(){
    int ch,x;
    while(1){
        cin>>ch;
        if(ch==1){cin>>x;dinsfirst(x);}
        else if(ch==2){cin>>x;dinslast(x);}
        else if(ch==3){cin>>x;cinsfirst(x);}
        else if(ch==4){cin>>x;cinslast(x);}
        else break;
    }
}
