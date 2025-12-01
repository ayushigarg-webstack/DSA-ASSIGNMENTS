#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

int getLength(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* getIntersection(Node* headA, Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    Node* ptrA = headA;
    Node* ptrB = headB;

    int diff = lenA - lenB;

    if (diff < 0) {
        diff = -diff;        
        while (diff--) ptrB = ptrB->next;
    } 
    else {
        while (diff--) ptrA = ptrA->next;
    }

    
    while (ptrA != NULL && ptrB != NULL) {
        if (ptrA == ptrB)      
            return ptrA;

        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }

    return NULL;   
}

int main() {
    
    Node* common = new Node(8);
    common->next = new Node(5);

    Node* headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = common;

    Node* headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = common;

    Node* intersection = getIntersection(headA, headB);

    if (intersection)
        cout << "Intersected at " << intersection->data;
    else
        cout << "No intersection";

    return 0;
}
