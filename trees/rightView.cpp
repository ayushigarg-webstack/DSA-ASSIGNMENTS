// file: right_view.cpp
#include <iostream>
using namespace std;
struct Node{ int val; Node* l; Node* r; Node(int v):val(v),l(NULL),r(NULL){} };

struct Q {
    Node** arr; int cap, head, tail, sz;
    Q(int c=200){ cap=c; arr = new Node*[cap]; head=0; tail=0; sz=0; }
    ~Q(){ delete[] arr; }
    bool empty(){ return sz==0; }
    void push(Node* p){ arr[tail]=p; tail=(tail+1)%cap; ++sz; }
    Node* pop(){ Node* r = arr[head]; head=(head+1)%cap; --sz; return r; }
    int size(){ return sz; }
};

void rightView(Node* root) {
    if(!root) return;
    Q q(500);
    q.push(root);
    while(!q.empty()){
        int levelSize = q.size();
        for(int i=0;i<levelSize;i++){
            Node* node = q.pop();
            if(i==levelSize-1) cout<<node->val<<" ";
            if(node->l) q.push(node->l);
            if(node->r) q.push(node->r);
        }
    }
    cout<<"\n";
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2); root->right = new Node(3);
    root->left->right = new Node(5); root->right->right = new Node(4);
    cout<<"Right view: ";
    rightView(root); // expected: 1 3 4
    return 0;
}
