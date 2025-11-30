#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d): data(d), left(NULL), right(NULL) {}
};

void preorder(Node* r) {
    if(!r) return;
    cout<<r->data<<" ";
    preorder(r->left);
    preorder(r->right);
}

void inorder(Node* r) {
    if(!r) return;
    inorder(r->left);
    cout<<r->data<<" ";
    inorder(r->right);
}

void postorder(Node* r) {
    if(!r) return;
    postorder(r->left);
    postorder(r->right);
    cout<<r->data<<" ";
}

int main() {
   
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"Preorder: "; preorder(root); cout<<"\n";
    cout<<"Inorder: "; inorder(root); cout<<"\n";
    cout<<"Postorder: "; postorder(root); cout<<"\n";

    
    return 0;
}
