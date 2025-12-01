#include <iostream>
#include <unordered_set>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d){ data=d; left=right=NULL; }
};

bool check(Node* root, unordered_set<int>& s){
    if(!root) return false;
    if(s.count(root->data)) return true;
    s.insert(root->data);
    return check(root->left,s) || check(root->right,s);
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->right->left=new Node(2);
    unordered_set<int> s;
    if(check(root,s)) cout<<"Duplicates Found";
    else cout<<"No Duplicates";
}
