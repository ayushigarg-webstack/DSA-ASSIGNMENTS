#include <iostream>
using namespace std;

struct Node { int key; Node *left, *right; Node(int k):key(k),left(NULL),right(NULL){} };

Node* insert(Node* root, int k) {
    if(!root) return new Node(k);
    if(k < root->key) root->left = insert(root->left, k);
    else if(k > root->key) root->right = insert(root->right, k);
    return root;
}

Node* searchRec(Node* root, int k) {
    if(!root || root->key==k) return root;
    if(k < root->key) return searchRec(root->left, k);
    return searchRec(root->right, k);
}

Node* searchNonRec(Node* root, int k) {
    Node* cur = root;
    while(cur) {
        if(cur->key == k) return cur;
        if(k < cur->key) cur = cur->left;
        else cur = cur->right;
    }
    return NULL;
}

Node* findMin(Node* root) {
    Node* cur = root;
    if(!cur) return NULL;
    while(cur->left) cur = cur->left;
    return cur;
}

Node* findMax(Node* root) {
    Node* cur = root;
    if(!cur) return NULL;
    while(cur->right) cur = cur->right;
    return cur;
}

Node* inorderSuccessor(Node* root, Node* node) {
    if(!root || !node) return NULL;
    if(node->right) return findMin(node->right);
    Node* succ = NULL;
    Node* cur = root;
    while(cur) {
        if(node->key < cur->key) { succ = cur; cur = cur->left;}
        else if(node->key > cur->key) cur = cur->right;
        else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* node) {
    if(!root || !node) return NULL;
    if(node->left) return findMax(node->left);
    Node* pred = NULL;
    Node* cur = root;
    while(cur) {
        if(node->key > cur->key) { pred = cur; cur = cur->right; }
        else if(node->key < cur->key) cur = cur->left;
        else break;
    }
    return pred;
}

int main(){
    Node* root = NULL;
    int keys[] = {20,10,30,5,15,25,40};
    for(int i=0;i<7;i++) root = insert(root, keys[i]);

    Node* s1 = searchRec(root,15);
    cout<<"searchRec 15: "<<(s1? "found":"not found")<<"\n";
    Node* s2 = searchNonRec(root,100);
    cout<<"searchNonRec 100: "<<(s2? "found":"not found")<<"\n";

    cout<<"Min: "<< (findMin(root)->key) <<"\n";
    cout<<"Max: "<< (findMax(root)->key) <<"\n";

    Node* node = searchNonRec(root,20);
    Node* succ = inorderSuccessor(root, node);
    Node* pred = inorderPredecessor(root, node);
    cout<<"Successor of 20: "<< (succ? to_string(succ->key) : string("NULL")) <<"\n";
    cout<<"Predecessor of 20: "<< (pred? to_string(pred->key) : string("NULL")) <<"\n";
    return 0;
}
