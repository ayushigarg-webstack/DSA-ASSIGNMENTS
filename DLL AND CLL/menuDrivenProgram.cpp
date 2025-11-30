#include <iostream>
using namespace std;

// ------------------------
// Doubly Linked List Node
// ------------------------
class DNode {
public:
    int data;
    DNode *next, *prev;

    DNode(int d) {
        data = d;
        next = prev = NULL;
    }
};

// ------------------------
// Doubly Linked List Class
// ------------------------
class DoublyList {
public:
    DNode* head;
    DoublyList() { head = NULL; }

    // Insert at beginning
    void insertFirst(int x) {
        DNode* n = new DNode(x);
        if (head != NULL) {
            n->next = head;
            head->prev = n;
        }
        head = n;
    }

    // Insert at end
    void insertLast(int x) {
        DNode* n = new DNode(x);
        if (!head) { head = n; return; }

        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    // Insert after a specific node
    void insertAfter(int key, int x) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Key not found\n"; return; }

        DNode* n = new DNode(x);
        n->next = temp->next;
        n->prev = temp;
        if (temp->next) temp->next->prev = n;
        temp->next = n;
    }

    // Insert before a specific node
    void insertBefore(int key, int x) {
        if (!head) return;

        if (head->data == key) {
            insertFirst(x);
            return;
        }

        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;

        if (!temp) { cout << "Key not found\n"; return; }

        DNode* n = new DNode(x);
        n->next = temp;
        n->prev = temp->prev;

        temp->prev->next = n;
        temp->prev = n;
    }

    // Delete node
    void deleteNode(int key) {
        if (!head) return;

        DNode* temp = head;

        // delete head
        if (temp->data == key) {
            head = temp->next;
            if (head) head->prev = NULL;
            delete temp;
            return;
        }

        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;

        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;

        delete temp;
    }

    // Search a node
    void search(int key) {
        DNode* temp = head;
        while (temp) {
            if (temp->data == key) {
                cout << "Found\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Not Found\n";
    }

    // Display
    void display() {
        DNode* temp = head;
        cout << "DLL: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


// ------------------------
// Circular Linked List Node
// ------------------------
class CNode {
public:
    int data;
    CNode* next;

    CNode(int d) {
        data = d;
        next = NULL;
    }
};

// ------------------------
// Circular Linked List Class
// ------------------------
class CircularList {
public:
    CNode* head;
    CircularList() { head = NULL; }

    // Insert at beginning
    void insertFirst(int x) {
        CNode* n = new CNode(x);

        if (!head) {
            head = n;
            n->next = head;
            return;
        }

        CNode* temp = head;
        while (temp->next != head)
            temp = temp->next;

        n->next = head;
        temp->next = n;
        head = n;
    }

    // Insert at end
    void insertLast(int x) {
        CNode* n = new CNode(x);

        if (!head) {
            head = n;
            n->next = head;
            return;
        }

        CNode* temp = head;
        while (temp->next != head) temp = temp->next;

        temp->next = n;
        n->next = head;
    }

    // Insert after a value
    void insertAfter(int key, int x) {
        if (!head) return;

        CNode* temp = head;
        do {
            if (temp->data == key) {
                CNode* n = new CNode(x);
                n->next = temp->next;
                temp->next = n;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Key not found\n";
    }

    // Insert before a value
    void insertBefore(int key, int x) {
        if (!head) return;

        // Case: key at head
        if (head->data == key) {
            insertFirst(x);
            return;
        }

        CNode* temp = head;
        CNode* prev = NULL;

        do {
            prev = temp;
            temp = temp->next;

            if (temp->data == key) {
                CNode* n = new CNode(x);
                n->next = temp;
                prev->next = n;
                return;
            }

        } while (temp != head);

        cout << "Key not found\n";
    }

    // Delete a node
    void deleteNode(int key) {
        if (!head) return;

        CNode *temp = head, *prev = NULL;

        // Head node delete
        if (head->data == key) {

            if (head->next == head) { // single node
                delete head;
                head = NULL;
                return;
            }

            CNode* last = head;
            while (last->next != head) last = last->next;

            last->next = head->next;
            CNode* del = head;
            head = head->next;

            delete del;
            return;
        }

        // Other node delete
        do {
            prev = temp;
            temp = temp->next;

            if (temp->data == key) {
                prev->next = temp->next;
                delete temp;
                return;
            }

        } while (temp != head);
    }

    // Search
    void search(int key) {
        if (!head) { cout << "Not Found\n"; return; }

        CNode* temp = head;
        do {
            if (temp->data == key) {
                cout << "Found\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Not Found\n";
    }

    // Display
    void display() {
        if (!head) { cout << "CLL empty\n"; return; }
        CNode* temp = head;

        cout << "CLL: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};


// ------------------------
// MAIN PROGRAM
// ------------------------
int main() {
    DoublyList dll;
    CircularList cll;

    int choice, listType;
    int x, key;

    while (1) {
        cout << "\nChoose List Type:\n";
        cout << "1. Doubly Linked List\n";
        cout << "2. Circular Linked List\n";
        cout << "3. Exit\n";
        cin >> listType;

        if (listType == 3) break;

        cout << "\n--- MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete Node\n";
        cout << "6. Search\n";
        cout << "7. Display\n";
        cout << "8. Back to Main Menu\n";
        cin >> choice;

        if (listType == 1) {          // DLL OPERATIONS
            switch (choice) {
                case 1: cout << "Enter value: "; cin >> x; dll.insertFirst(x); break;
                case 2: cout << "Enter value: "; cin >> x; dll.insertLast(x); break;
                case 3: cout << "Key? "; cin >> key; cout << "Value? "; cin >> x; dll.insertAfter(key, x); break;
                case 4: cout << "Key? "; cin >> key; cout << "Value? "; cin >> x; dll.insertBefore(key, x); break;
                case 5: cout << "Delete value: "; cin >> key; dll.deleteNode(key); break;
                case 6: cout << "Search value: "; cin >> key; dll.search(key); break;
                case 7: dll.display(); break;
                case 8: continue;
            }
        }
        else if (listType == 2) {      // CLL OPERATIONS
            switch (choice) {
                case 1: cout << "Enter value: "; cin >> x; cll.insertFirst(x); break;
                case 2: cout << "Enter value: "; cin >> x; cll.insertLast(x); break;
                case 3: cout << "Key? "; cin >> key; cout << "Value? "; cin >> x; cll.insertAfter(key, x); break;
                case 4: cout << "Key? "; cin >> key; cout << "Value? "; cin >> x; cll.insertBefore(key, x); break;
                case 5: cout << "Delete value: "; cin >> key; cll.deleteNode(key); break;
                case 6: cout << "Search value: "; cin >> key; cll.search(key); break;
                case 7: cll.display(); break;
                case 8: continue;
            }
        }
    }

    return 0;
}
