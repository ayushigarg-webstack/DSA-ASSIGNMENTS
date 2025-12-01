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

int countAndDelete(Node* &head,int key){
    int c=0;
    while(head && head->data==key){
        Node* t=head;
        head=head->next;
        delete t;
        c++;
    }
    Node* p=head;
    while(p && p->next){
        if(p->next->data==key){
            Node* t=p->next;
            p->next=t->next;
            delete t;
            c++;
        } else p=p->next;
    }
    return c;
}

void display(Node* h){
    while(h){ cout<<h->data<<" "; h=h->next; }
}

int main(){
    Node* head=NULL;
    int x;
    while(cin>>x && x!=-1) insert(head,x);
    int key; cin>>key;
    int c=countAndDelete(head,key);
    cout<<c<<endl;
    display(head);
}
