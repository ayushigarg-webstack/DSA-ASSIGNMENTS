#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* random;

    Node(int d) {
        data = d;
        next = prev = random = NULL;
    }
};

// Fix the incorrect random pointer
void fixRandomPointer(Node* head) {
    if (!head) return;

    Node* temp = head;

    // Find node whose random pointer is wrong
    while (temp != NULL) {
        if (temp->random != NULL && temp->random->data != temp->data) {

            int correctValue = temp->data;

            // find correct node with same value
            Node* search = head;
            while (search != NULL) {
                if (search->data == correctValue)
                    break;
                search = search->next;
            }

            temp->random = search; // correct the random pointer
            return;
        }
        temp = temp->next;
    }
}


// Print list with random pointers
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "(";
        if (temp->random) cout << temp->random->data;
        else cout << "NULL";
        cout << ")  ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // creating sample list 1 <-> 2 <-> 3
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    // Random pointers (wrong assignment)
    n1->random = n3;  // WRONG
    n2->random = n2;  // correct
    n3->random = n3;  // correct

    cout << "Before fixing:\n";
    printList(n1);

    fixRandomPointer(n1);

    cout << "After fixing:\n";
    printList(n1);

    return 0;
}
