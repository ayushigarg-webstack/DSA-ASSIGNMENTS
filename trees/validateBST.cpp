
#include <iostream>
#include <climits>
using namespace std;
struct Node{ int key; Node *l,*r; Node(int k):key(k),l(NULL),r(NULL){} };

bool isBSTUtil(Node* root, int minv, int maxv) {
    if(!root) return true;
    if(root->key <= minv || root->key >= maxv) return false;
    return isBSTUtil(root->l, minv, root->key) && isBSTUtil(root->r, root->key, maxv);
}

bool isBST(Node* root){ return isBSTUtil(root, INT_MIN, INT_MAX); }

int main(){
    Node* root = new Node(10);
    root->left = new Node(5); root->right = new Node(20);
    root->left->left = new Node(2); root->left->right = new Node(7);
    cout<<"isBST? "<< (isBST(root) ? "Yes":"No") <<"\n";

    
    root->right->left = new Node(15);
    root->right->left->left = new Node(100); 
    cout<<"isBST now? "<< (isBST(root) ? "Yes":"No") <<"\n";
    return 0;
}
