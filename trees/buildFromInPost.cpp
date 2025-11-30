// file: build_in_post.cpp
#include <iostream>
using namespace std;
struct Node{ int val; Node *l,*r; Node(int v):val(v),l(NULL),r(NULL){} };

int findIndex(int arr[], int start, int end, int val) {
    for(int i=start;i<=end;i++) if(arr[i]==val) return i;
    return -1;
}

Node* build(int inorder[], int inStart, int inEnd, int postorder[], int postStart, int postEnd) {
    if(inStart>inEnd || postStart>postEnd) return NULL;
    int rootVal = postorder[postEnd];
    Node* root = new Node(rootVal);
    int inRootIdx = findIndex(inorder, inStart, inEnd, rootVal);
    int leftSize = inRootIdx - inStart;
    root->l = build(inorder, inStart, inRootIdx-1, postorder, postStart, postStart+leftSize-1);
    root->r = build(inorder, inRootIdx+1, inEnd, postorder, postStart+leftSize, postEnd-1);
    return root;
}

void inorderPrint(Node* r){ if(!r) return; inorderPrint(r->l); cout<<r->val<<" "; inorderPrint(r->r); }

int main(){
    int inorder[] = {9,3,15,20,7};
    int postorder[] = {9,15,7,20,3};
    // These form a valid tree (pre was [3,9,20,15,7])
    Node* root = build(inorder,0,4,postorder,0,4);
    cout<<"Inorder of constructed tree: "; inorderPrint(root); cout<<"\n";
    return 0;
}
