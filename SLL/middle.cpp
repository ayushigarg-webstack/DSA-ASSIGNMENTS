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

int middle(Node* head){
    Node* s=head;
    Node* f=head;
    while(f && f->next){
        s=s->next;
        f=f->next->next;
    }
    return s->data;
}

int main(){
    Node* head=NULL;
    int x;
    while(cin>>x && x!=-1) insert(head,x);
    cout<<middle(head);
}
