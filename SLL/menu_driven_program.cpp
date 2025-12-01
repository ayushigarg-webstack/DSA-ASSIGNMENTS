#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d){ data=d; next=NULL; }
};

void display(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void insertAtBeginning(Node* &head,int x){
    Node* t=new Node(x);
    t->next=head;
    head=t;
}

void insertAtEnd(Node* &head,int x){
    Node* t=new Node(x);
    if(!head){ head=t; return; }
    Node* p=head;
    while(p->next) p=p->next;
    p->next=t;
}

void insertBefore(Node* &head,int key,int x){
    if(!head) return;
    if(head->data==key){
        insertAtBeginning(head,x);
        return;
    }
    Node* p=head;
    while(p->next && p->next->data!=key) p=p->next;
    if(p->next){
        Node* t=new Node(x);
        t->next=p->next;
        p->next=t;
    }
}

void insertAfter(Node* head,int key,int x){
    while(head && head->data!=key) head=head->next;
    if(head){
        Node* t=new Node(x);
        t->next=head->next;
        head->next=t;
    }
}

void deleteBeginning(Node* &head){
    if(!head) return;
    Node* t=head;
    head=head->next;
    delete t;
}

void deleteEnd(Node* &head){
    if(!head) return;
    if(!head->next){
        delete head;
        head=NULL;
        return;
    }
    Node* p=head;
    while(p->next->next) p=p->next;
    delete p->next;
    p->next=NULL;
}

void deleteSpecific(Node* &head,int key){
    if(!head) return;
    if(head->data==key){
        deleteBeginning(head);
        return;
    }
    Node* p=head;
    while(p->next && p->next->data!=key) p=p->next;
    if(p->next){
        Node* t=p->next;
        p->next=t->next;
        delete t;
    }
}

int searchNode(Node* head,int key){
    int pos=1;
    while(head){
        if(head->data==key) return pos;
        head=head->next;
        pos++;
    }
    return -1;
}

int main(){
    Node* head=NULL;
    int ch,x,key;
    while(true){
        cin>>ch;
        if(ch==1){ cin>>x; insertAtBeginning(head,x); }
        else if(ch==2){ cin>>x; insertAtEnd(head,x); }
        else if(ch==3){ cin>>key>>x; insertBefore(head,key,x); }
        else if(ch==4){ cin>>key>>x; insertAfter(head,key,x); }
        else if(ch==5) deleteBeginning(head);
        else if(ch==6) deleteEnd(head);
        else if(ch==7){ cin>>key; deleteSpecific(head,key); }
        else if(ch==8){ cin>>key; cout<<searchNode(head,key)<<endl; }
        else if(ch==9) display(head);
        else break;
    }
}
