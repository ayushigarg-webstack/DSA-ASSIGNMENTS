#include <iostream>
using namespace std;
struct Node{ int val; Node* l; Node* r; Node(int v):val(v),l(NULL),r(NULL){} };

int sumLeftLeaves(Node* root) {
    if(!root) return 0;
    int res = 0;
    if(root->left) {
        if(!root->left->left && !root->left->right) res += root->left->val;
        else res += sumLeftLeaves(root->left);
    }
    res += sumLeftLeaves(root->right);
    return res;
}

int main(){
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    cout<<"Sum of left leaves: "<<sumLeftLeaves(root)<<"\n"; // 9+15 = 24
    return 0;
}
