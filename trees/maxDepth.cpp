// file: max_depth.cpp
#include <iostream>
using namespace std;
struct Node{ int val; Node* l; Node* r; Node(int v):val(v),l(NULL),r(NULL){} };

int maxDepth(Node* root){ if(!root) return 0; int L=maxDepth(root->l), R=maxDepth(root->r); return 1 + (L>R?L:R); }

int main(){
    Node* root = new Node(1);
    root->left = new Node(2); root->right = new Node(3);
    root->left->left = new Node(4); root->left->left->left = new Node(5);
    cout<<"Max depth: "<<maxDepth(root)<<"\n";
    return 0;
}
