#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d){ data=d; next=NULL; }
};

void insert(Node* &head,int x){
    Node* t=new Node(x);
    if(!head){ head=t; return; }
    Node* p=head;
    while(p->next) p=p->next;
    p->next=t;
}

Node* reverse(Node* head){
    Node* p=NULL;
    Node* c=head;
    Node* n;
    while(c){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    return p;
}

void display(Node* head){
    while(head){ cout<<head->data<<" "; head=head->next; }
}

int main(){
    Node* head=NULL;
    int x;
    while(cin>>x && x!=-1) insert(head,x);
    head=reverse(head);
    display(head);
}
