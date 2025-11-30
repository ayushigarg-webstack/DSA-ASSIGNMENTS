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

// Function to check circular linked list
bool isCircular(Node* head) {
    if (head == NULL)
        return false;

    Node* temp = head->next;

    // Traverse until we hit NULL or come back to head
    while (temp != NULL && temp != head)
        temp = temp->next;

    return (temp == head);
}


// ---------------------
// MAIN FUNCTION
// ---------------------
int main() {
    // Creating nodes manually
    Node* head = new Node(2);
    Node* n1 = new Node(4);
    Node* n2 = new Node(6);
    Node* n3 = new Node(7);
    Node* n4 = new Node(5);

    // Link nodes
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // Make list circular:
    n4->next = head;

    // Check circular or not
    if (isCircular(head))
        cout << "True (Circular Linked List)";
    else
        cout << "False (Not Circular)";

    return 0;
}
