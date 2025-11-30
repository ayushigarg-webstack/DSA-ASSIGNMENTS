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

class CircularList {
public:
    Node* head;

    CircularList() { head = NULL; }

    void insertEnd(int x) {
        Node* n = new Node(x);
        if (!head) {
            head = n;
            n->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = n;
        n->next = head;
    }

    // ------- SPLIT FUNCTION -------
    void splitCLL(Node*& head1, Node*& head2) {
        if (!head || head->next == head) return;

        Node *slow = head, *fast = head;

        // Find the middle using slow-fast pointers
        while (fast->next != head && fast->next->next != head) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // head1 starts from original head
        head1 = head;

        // head2 starts after slow
        head2 = slow->next;

        // Make first half circular
        slow->next = head1;

        // Bring fast to last node
        if (fast->next == head)
            fast = fast;  // even number of nodes
        else
            fast = fast->next;  // odd number of nodes

        // Make second half circular
        fast->next = head2;
    }

    // Display circular list
    void display(Node* h) {
        if (!h) return;

        Node* temp = h;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != h);
        cout << endl;
    }
};

int main() {
    CircularList cll;

    // Example: 10 -> 4 -> 9
    cll.insertEnd(10);
    cll.insertEnd(4);
    cll.insertEnd(9);

    Node *head1 = NULL, *head2 = NULL;

    cll.splitCLL(head1, head2);

    cout << "First Circular List: ";
    cll.display(head1);

    cout << "Second Circular List: ";
    cll.display(head2);

    return 0;
}
