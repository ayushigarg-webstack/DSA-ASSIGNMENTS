#include <iostream>
using namespace std;

// ------------------------------------
// DOUBLY LINKED LIST NODE
// ------------------------------------
class DNode {
public:
    int data;
    DNode *next, *prev;

    DNode(int d) {
        data = d;
        next = prev = NULL;
    }
};
int parity(int x) {
    int count = 0;
    while (x > 0) {
        if (x & 1) count++;
        x >>= 1;
    }
    return count;
}

// ------------------------------------
// DOUBLY LINKED LIST CLASS
// ------------------------------------
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

    void removeEvenParityNodes() {
        DNode* temp = head;

        while (temp) {
            DNode* nextNode = temp->next;

            if (parity(temp->data) % 2 == 0) {
                // delete temp
                if (temp == head) {
                    head = temp->next;
                    if (head) head->prev = NULL;
                    delete temp;
                } else {
                    if (temp->prev) temp->prev->next = temp->next;
                    if (temp->next) temp->next->prev = temp->prev;
                    delete temp;
                }
            }

            temp = nextNode;
        }
    }

    void display() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


// ------------------------------------
// CIRCULAR LINKED LIST NODE
// ------------------------------------
class CNode {
public:
    int data;
    CNode* next;

    CNode(int d) {
        data = d;
        next = NULL;
    }
};

// ------------------------------------
// CIRCULAR LINKED LIST CLASS
// ------------------------------------
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

    void deleteValue(int key) {
        if (!head) return;

        CNode *curr = head, *prev = NULL;

        // Case: deleting head
        if (head->data == key) {
            if (head->next == head) {       // only one node
                delete head;
                head = NULL;
                return;
            }

            // find last node
            CNode* last = head;
            while (last->next != head)
                last = last->next;

            last->next = head->next;
            CNode* del = head;
            head = head->next;
            delete del;
            return;
        }

        // Delete non-head
        prev = head;
        curr = head->next;

        while (curr != head && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == head) return; // not found

        prev->next = curr->next;
        delete curr;
    }

    void removeEvenParityNodes() {
        if (!head) return;

        CNode* temp = head;

        do {
            CNode* nextNode = temp->next;

            if (parity(temp->data) % 2 == 0)
                deleteValue(temp->data);

            temp = nextNode;
        } while (temp != head);
    }

    void display() {
        if (!head) return;

        CNode* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};


// ------------------------------------
// MAIN
// ------------------------------------
int main() {
    // ---------------------
    // Example for CLL
    // ---------------------
    CircularList cll;
    cll.insertEnd(9);
    cll.insertEnd(11);
    cll.insertEnd(34);
    cll.insertEnd(6);
    cll.insertEnd(13);
    cll.insertEnd(21);

    cout << "Original CLL: ";
    cll.display();

    cll.removeEvenParityNodes();

    cout << "CLL after removing even parity nodes: ";
    cll.display();


    // ---------------------
    // Example for DLL
    // ---------------------
    DoublyList dll;
    dll.insertEnd(18);
    dll.insertEnd(15);
    dll.insertEnd(8);
    dll.insertEnd(9);
    dll.insertEnd(14);

    cout << "\nOriginal DLL: ";
    dll.display();

    dll.removeEvenParityNodes();

    cout << "DLL after removing even parity nodes: ";
    dll.display();

    return 0;
}
