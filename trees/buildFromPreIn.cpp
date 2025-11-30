// file: build_pre_in.cpp
#include <iostream>
using namespace std;
struct Node{ int val; Node *l,*r; Node(int v):val(v),l(NULL),r(NULL){} };

int findIndex(int arr[], int start, int end, int val) {
    for(int i=start;i<=end;i++) if(arr[i]==val) return i;
    return -1;
}

Node* build(int preorder[], int preStart, int preEnd, int inorder[], int inStart, int inEnd) {
    if(preStart>preEnd || inStart>inEnd) return NULL;
    int rootVal = preorder[preStart];
    Node* root = new Node(rootVal);
    int inRootIdx = findIndex(inorder, inStart, inEnd, rootVal);
    int leftSize = inRootIdx - inStart;
    root->l = build(preorder, preStart+1, preStart+leftSize, inorder, inStart, inRootIdx-1);
    root->r = build(preorder, preStart+leftSize+1, preEnd, inorder, inRootIdx+1, inEnd);
    return root;
}

void preorderPrint(Node* r){ if(!r) return; cout<<r->val<<" "; preorderPrint(r->l); preorderPrint(r->r); }

int main(){
    int preorder[] = {3,9,20,15,7};
    int inorder[]  = {9,3,15,20,7};
    int pre2[] = {1,2,4,5,3,6};
    int in2[]  = {4,2,5,1,3,6};
    Node* root = build(pre2,0,5,in2,0,5);
    cout<<"Preorder of constructed tree: "; preorderPrint(root); cout<<"\n";
    return 0;
}
