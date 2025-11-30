#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class CircularList
{
public:
    Node *head;

    CircularList() { head = NULL; }

    void insertEnd(int x)
    {
        Node *n = new Node(x);

        if (!head)
        {
            head = n;
            n->next = head; // make circular
            return;
        }

        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = n;
        n->next = head;
    }

    // Display with repeating head node at end
    void displayWithRepeat()
    {
        if (!head)
            return;

        Node *temp = head;

        // Print normal circular traversal
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        // Print head again
        cout << head->data;
    }
};

int main()
{
    CircularList cll;

    cll.insertEnd(20);
    cll.insertEnd(100);
    cll.insertEnd(40);
    cll.insertEnd(80);
    cll.insertEnd(60);

    cll.displayWithRepeat();

    return 0;
}
