// file: merge_bsts_dll.cpp
#include <iostream>
using namespace std;

struct Node{ int key; Node *left,*right; Node(int k):key(k),left(NULL),right(NULL){} };

// convert BST to sorted DLL in-place (returns head)
void bstToDLLUtil(Node* root, Node*& head, Node*& tail) {
    if(!root) return;
    bstToDLLUtil(root->left, head, tail);
    // append root
    if(!head) { head = root; tail = root; }
    else {
        tail->right = root;
        root->left = tail;
        tail = root;
    }
    // detach further links before processing right
    Node* right = root->right;
    root->right = NULL;
    bstToDLLUtil(right, head, tail);
}

Node* mergeDLLs(Node* h1, Node* h2) {
    if(!h1) return h2;
    if(!h2) return h1;
    Node dummy(0); Node* tail = &dummy;
    while(h1 && h2) {
        if(h1->key < h2->key) { tail->right = h1; h1->left = tail; h1 = h1->right; tail = tail->right; tail->right = NULL; }
        else { tail->right = h2; h2->left = tail; h2 = h2->right; tail = tail->right; tail->right = NULL; }
    }
    Node* rest = h1? h1 : h2;
    while(rest) { tail->right = rest; rest->left = tail; tail = tail->right; rest = rest->right; tail->right = NULL; }
    // head is dummy.right; detach dummy
    Node* head = dummy.right;
    if(head) head->left = NULL;
    return head;
}

void printDLL(Node* head) {
    Node* cur = head;
    while(cur) { cout<<cur->key; if(cur->right) cout<<" <-> "; cur = cur->right; }
    cout<<"\n";
}

Node* insert(Node* root, int k) {
    if(!root) return new Node(k);
    if(k < root->key) root->left = insert(root->left, k);
    else if(k > root->key) root->right = insert(root->right, k);
    return root;
}

int main(){
    Node* t1 = NULL;
    t1 = insert(t1, 20); t1 = insert(t1, 10); t1 = insert(t1, 30); t1 = insert(t1, 25);
    Node* t2 = NULL;
    t2 = insert(t2, 5); t2 = insert(t2, 70); t2 = insert(t2, 50);

    Node *h1=NULL, *t1tail=NULL;
    bstToDLLUtil(t1, h1, t1tail);
    Node *h2=NULL, *t2tail=NULL;
    bstToDLLUtil(t2, h2, t2tail);

    Node* merged = mergeDLLs(h1,h2);
    cout<<"Merged DLL: "; printDLL(merged);
    return 0;
}
