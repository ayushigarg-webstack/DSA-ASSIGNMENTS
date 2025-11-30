#include <iostream>
using namespace std;

struct Tree { int val; Tree *l,*r; Tree(int v):val(v),l(NULL),r(NULL){} };
struct RootList { Tree* root; RootList* next; RootList(Tree* r):root(r),next(NULL){} };

Tree* cloneWithOffset(Tree* node, int offset) {
    if(!node) return NULL;
    Tree* n = new Tree(node->val + offset);
    n->l = cloneWithOffset(node->l, offset);
    n->r = cloneWithOffset(node->r, offset);
    return n;
}

// join two lists: append all combinations of left and right with root i
RootList* appendTrees(RootList* head, Tree* t) {
    if(!head) return new RootList(t);
    RootList* cur=head;
    while(cur->next) cur=cur->next;
    cur->next = new RootList(t);
    return head;
}

void freeTree(Tree* r){
    if(!r) return;
    freeTree(r->l); freeTree(r->r); delete r;
}

// generate trees for values 1..n
RootList* generate(int n) {
    RootList* result = NULL;
    for(int rootVal = 1; rootVal <= n; ++rootVal) {
        RootList* leftList = (rootVal==1) ? NULL : generate(rootVal-1);
        RootList* rightList = (rootVal==n) ? NULL : generate(n-rootVal);

        // if both sides empty => single root node
        if(!leftList && !rightList) {
            Tree* t = new Tree(rootVal);
            result = appendTrees(result, t);
        } else if(!leftList) {
            // left empty: for each right tree
            RootList* rcur = rightList;
            while(rcur) {
                Tree* root = new Tree(rootVal);
                root->l = NULL;
                root->r = cloneWithOffset(rcur->root, rootVal);
                result = appendTrees(result, root);
                rcur = rcur->next;
            }
        } else if(!rightList) {
            RootList* lcur = leftList;
            while(lcur) {
                Tree* root = new Tree(rootVal);
                root->l = lcur->root;
                root->r = NULL;
                result = appendTrees(result, root);
                lcur = lcur->next;
            }
        } else {
            RootList* lcur = leftList;
            while(lcur) {
                RootList* rcur = rightList;
                while(rcur) {
                    Tree* root = new Tree(rootVal);
                    root->l = lcur->root;
                    root->r = cloneWithOffset(rcur->root, rootVal);
                    result = appendTrees(result, root);
                    rcur = rcur->next;
                }
                lcur = lcur->next;
            }
        }
    }
    return result;
}

void printPreorderWithNulls(Tree* r) {
    if(!r) { cout<<"-1 "; return; }
    cout<<r->val<<" ";
    printPreorderWithNulls(r->l);
    printPreorderWithNulls(r->r);
}

int main(){
    int n = 3;
    
    RootList* list = generate(n);
    cout<<"All unique BSTs (preorder with -1 as NULL):\n";
    RootList* cur = list;
    int count = 0;
    while(cur) {
        printPreorderWithNulls(cur->root);
        cout<<"\n";
        ++count;
        cur = cur->next;
    }
    cout<<"Total = "<<count<<"\n";
    return 0;
}
