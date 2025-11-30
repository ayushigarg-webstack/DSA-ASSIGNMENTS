#include <iostream>
using namespace std;

// ---------------------------
// DOUBLY LINKED LIST (DLL)
// ---------------------------
class DNode {
public:
    int data;
    DNode *next, *prev;

    DNode(int d) {
        data = d;
        next = prev = NULL;
    }
};

class DoublyList {
public:
    DNode* head;

    DoublyList() { head = NULL; }

    void insertEnd(int x) {
        DNode* n = new DNode(x);
        if (!head) {
            head = n;
            return;
        }
        DNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    int sizeDLL() {
        int count = 0;
        DNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};


// ---------------------------
// CIRCULAR LINKED LIST (CLL)
// ---------------------------
class CNode {
public:
    int data;
    CNode* next;

    CNode(int d) {
        data = d;
        next = NULL;
    }
};

class CircularList {
public:
    CNode* head;

    CircularList() { head = NULL; }

    void insertEnd(int x) {
        CNode* n = new CNode(x);
        if (!head) {
            head = n;
            n->next = head;
            return;
        }
        CNode* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = n;
        n->next = head;
    }

    int sizeCLL() {
        if (!head) return 0;

        int count = 0;
        CNode* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }
};


// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    DoublyList dll;
    CircularList cll;

    // Insert some nodes into DLL
    dll.insertEnd(10);
    dll.insertEnd(20);
    dll.insertEnd(30);
    dll.insertEnd(40);

    // Insert nodes into CLL
    cll.insertEnd(5);
    cll.insertEnd(15);
    cll.insertEnd(25);

    cout << "Size of Doubly Linked List: " << dll.sizeDLL() << endl;
    cout << "Size of Circular Linked List: " << cll.sizeCLL() << endl;

    return 0;
}
