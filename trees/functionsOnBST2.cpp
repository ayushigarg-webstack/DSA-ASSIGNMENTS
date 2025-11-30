#include <iostream>
using namespace std;
struct Node{ int key; Node*left,*right; Node(int k):key(k),left(NULL),right(NULL){} };

Node* insert(Node* root, int k) {
    if(!root) return new Node(k);
    if(k < root->key) root->left = insert(root->left, k);
    else if(k > root->key) root->right = insert(root->right, k);
    return root;
}

Node* findMin(Node* r){ while(r && r->left) r=r->left; return r; }

Node* removeNode(Node* root, int k) {
    if(!root) return NULL;
    if(k < root->key) root->left = removeNode(root->left, k);
    else if(k > root->key) root->right = removeNode(root->right, k);
    else {
        // found
        if(!root->left) { Node* r = root->right; delete root; return r; }
        else if(!root->right) { Node* l = root->left; delete root; return l; }
        else {
            Node* minRight = findMin(root->right);
            root->key = minRight->key;
            root->right = removeNode(root->right, minRight->key);
        }
    }
    return root;
}

int maxDepth(Node* r){ if(!r) return 0; int l=maxDepth(r->left), rr=maxDepth(r->right); return 1 + (l>rr?l:rr); }
int minDepth(Node* r){ if(!r) return 0; if(!r->left) return 1+minDepth(r->right); if(!r->right) return 1+minDepth(r->left); int l=minDepth(r->left), rr=minDepth(r->right); return 1 + (l<rr?l:rr); }

void inorder(Node* r){ if(!r) return; inorder(r->left); cout<<r->key<<" "; inorder(r->right); }

int main(){
    Node* root = NULL;
    int arr[] = {20,10,30,5,15,25,35,12};
    for(int i=0;i<8;i++) root = insert(root, arr[i]);
    cout<<"Inorder: "; inorder(root); cout<<"\n";
    cout<<"Max depth: "<<maxDepth(root)<<"\n";
    cout<<"Min depth: "<<minDepth(root)<<"\n";
    root = removeNode(root, 10); // delete 10
    cout<<"After deleting 10, inorder: "; inorder(root); cout<<"\n";
    return 0;
}
