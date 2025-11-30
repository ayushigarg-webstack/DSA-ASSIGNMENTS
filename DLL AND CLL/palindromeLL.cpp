#include <iostream>
using namespace std;

// -------------------------
// Doubly Linked List Node
// -------------------------
class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char d) {
        data = d;
        next = prev = NULL;
    }
};

// -------------------------
// Doubly Linked List Class
// -------------------------
class DoublyList {
public:
    Node* head;

    DoublyList() { head = NULL; }

    void insertEnd(char ch) {
        Node* n = new Node(ch);

        if (!head) {
            head = n;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = n;
        n->prev = temp;
    }

    // Check palindrome
    bool isPalindrome() {
        if (!head || !head->next)
            return true;

        Node* left = head;
        Node* right = head;

        // move right pointer to last node
        while (right->next != NULL)
            right = right->next;

        // compare from both ends
        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;

            left = left->next;
            right = right->prev;
        }

        return true;
    }
};


// -------------------------
// MAIN FUNCTION
// -------------------------
int main() {
    DoublyList dll;

    // Example: RADAR
    dll.insertEnd('R');
    dll.insertEnd('A');
    dll.insertEnd('D');
    dll.insertEnd('A');
    dll.insertEnd('R');

    if (dll.isPalindrome())
        cout << "True (Palindrome)";
    else
        cout << "False (Not Palindrome)";

    return 0;
}
