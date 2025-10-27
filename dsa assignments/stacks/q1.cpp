#include <iostream>
using namespace std;

#define MAX 5  // maximum size of stack

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    // Function to add element to stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed to stack." << endl;
        }
    }

    // Function to remove element from stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    // Function to check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to check if stack is full
    bool isFull() {
        return top == MAX - 1;
    }

    // Function to display top element
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    // Function to display all elements in stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements are: ";
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

// Main menu-driven program
int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- Stack Operations Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. isEmpty" << endl;
        cout << "4. isFull" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            if (s.isEmpty())
                cout << "Stack is Empty." << endl;
            else
                cout << "Stack is Not Empty." << endl;
            break;
        case 4:
            if (s.isFull())
                cout << "Stack is Full." << endl;
            else
                cout << "Stack is Not Full." << endl;
            break;
        case 5:
            s.display();
            break;
        case 6:
            s.peek();
            break;
        case 7:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
