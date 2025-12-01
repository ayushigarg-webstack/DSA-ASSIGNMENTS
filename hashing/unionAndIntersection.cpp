#include <iostream>
#include <unordered_set>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d){ data=d; next=NULL; }
};

void print(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    Node *h1=NULL,*t1=NULL,*h2=NULL,*t2=NULL;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        Node* t=new Node(x);
        if(!h1) h1=t; else t1->next=t;
        t1=t;
    }
    for(int i=0;i<m;i++){
        int x; cin>>x;
        Node* t=new Node(x);
        if(!h2) h2=t; else t2->next=t;
        t2=t;
    }
    unordered_set<int> s1,s2;
    Node* cur=h1;
    while(cur){ s1.insert(cur->data); cur=cur->next; }
    cur=h2;
    while(cur){ s2.insert(cur->data); cur=cur->next; }
    Node *u=NULL,*ut=NULL,*in=NULL,*it=NULL;
    for(auto x:s1){
        Node* t=new Node(x);
        if(!u) u=t; else ut->next=t;
        ut=t;
    }
    for(auto x:s2){
        if(!s1.count(x)){
            Node* t=new Node(x);
            if(!u) u=t; else ut->next=t;
            ut=t;
        }
    }
    for(auto x:s1){
        if(s2.count(x)){
            Node* t=new Node(x);
            if(!in) in=t; else it->next=t;
            it=t;
        }
    }
    print(in);
    cout<<"\n";
    print(u);
}
