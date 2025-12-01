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

// Reverse K nodes
Node* reverseKGroup(Node* head, int k) {
    if (head == NULL || k == 1)
        return head;

    // Step 1: check if at least k nodes exist
    Node* temp = head;
    int count = 0;
    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }

    if (count < k) {
        // fewer than k nodes → do not reverse
        return head;
    }

    // Step 2: reverse first k nodes
    Node* curr = head;
    Node* prev = NULL;
    Node* nextNode = NULL;
    count = 0;

    while (curr != NULL && count < k) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        count++;
    }

    // Step 3: connect rest of the list (recursive)
    head->next = reverseKGroup(curr, k);

    // prev is the new head after reversing
    return prev;
}

// Utility: Print list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create sample list: 1→2→3→4→5→6→7
    Node *node1 = new Node(1); //1->2->1->2->1->3->1 
    
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = NULL;
    Node *head = node1;

    int k = 3;

    cout << "Original List: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
