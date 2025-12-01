#include <iostream>
using namespace std;

class Node {
public:
    int coeff;   // coefficient
    int power;   // power of x
    Node* next;

    Node(int c, int p) {
        coeff = c;
        power = p;
        next = NULL;
    }
};

// Function to add two polynomial linked lists
Node* addPolynomial(Node* poly1, Node* poly2) {
    Node* resultHead = NULL;
    Node* resultTail = NULL;

    while (poly1 != NULL && poly2 != NULL) {

        Node* newNode = NULL;

        if (poly1->power == poly2->power) {
            // Add coefficients
            newNode = new Node(poly1->coeff + poly2->coeff, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->power > poly2->power) {
            // Take poly1 term
            newNode = new Node(poly1->coeff, poly1->power);
            poly1 = poly1->next;
        }
        else {
            // Take poly2 term
            newNode = new Node(poly2->coeff, poly2->power);
            poly2 = poly2->next;
        }

        // Append to result
        if (resultHead == NULL) {
            resultHead = newNode;
            resultTail = newNode;
        } else {
            resultTail->next = newNode;
            resultTail = newNode;
        }
    }

    // If any list has remaining terms
    while (poly1 != NULL) {
        Node* newNode = new Node(poly1->coeff, poly1->power);
        resultTail->next = newNode;
        resultTail = newNode;
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        Node* newNode = new Node(poly2->coeff, poly2->power);
        resultTail->next = newNode;
        resultTail = newNode;
        poly2 = poly2->next;
    }

    return resultHead;
}

// Utility to print polynomial
void printPoly(Node* head) {
    while (head != NULL) {
        cout << head->coeff << "x^" << head->power;
        head = head->next;
        if (head != NULL)
            cout << " + ";
    }
    cout << endl;
}

int main() {
    // First polynomial: 5x^3 + 4x^2 + 2x^1
    Node* poly1 = new Node(5, 3);
    poly1->next = new Node(4, 2);
    poly1->next->next = new Node(2, 1);

    // Second polynomial: 3x^3 + 2x^1 + 6
    Node* poly2 = new Node(3, 3);
    poly2->next = new Node(2, 1);
    poly2->next->next = new Node(6, 0);

    cout << "Polynomial 1: ";
    printPoly(poly1);
    cout << "Polynomial 2: ";
    printPoly(poly2);

    Node* result = addPolynomial(poly1, poly2);

    cout << "Result: ";
    printPoly(result);

    return 0;
}
