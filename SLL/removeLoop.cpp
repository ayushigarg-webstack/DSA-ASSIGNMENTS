#include <iostream>
#include<map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}

bool detectLoop(Node *head)
{
    if(head == NULL)
    {
        return false;
    }
    map<Node*, bool> visited;
    Node *temp=head;
    while(temp!=NULL)
    {
        if(visited[temp]==true)
        {
            return true;
        }
        else
        {
            visited[temp]=true;
            temp=temp->next;
        }
    }
    return false;
}




int main()
{
    Node *first = new Node(7);
    Node *second = new Node(6);
    Node *third = new Node(2);
    Node *fourth = new Node(4);
    Node *fifth = new Node(9);
    Node *sixth = new Node(3);
    Node* seventh=new Node(13);
        Node* eighth=new Node(18);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next=eighth;
    eighth->next=third;
    Node *head = first;

    bool detect=detectLoop(head);
    cout<<detect<<endl                                              ;
    cout<<first->next->next->data;
}