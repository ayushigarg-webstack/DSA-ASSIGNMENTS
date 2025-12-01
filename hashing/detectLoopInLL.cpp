#include <iostream>
#include <unordered_set>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d){ data=d; next=NULL; }
};

int main(){
    int n;
    cin>>n;
    Node* head=NULL;
    Node* tail=NULL;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        Node* t=new Node(x);
        if(!head) head=t;
        else tail->next=t;
        tail=t;
    }
    int pos; 
    cin>>pos;
    if(pos!=-1){
        Node* temp=head;
        for(int i=0;i<pos;i++) temp=temp->next;
        tail->next=temp;
    }
    unordered_set<Node*> s;
    Node* curr=head;
    while(curr){
        if(s.count(curr)){
            cout<<"true";
            return 0;
        }
        s.insert(curr);
        curr=curr->next;
    }
    cout<<"false";
}
