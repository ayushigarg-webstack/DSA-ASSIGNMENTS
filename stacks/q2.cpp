#include <iostream>
#include <cstring> // for strlen
using namespace std;

#define MAX 100   // maximum size of stack

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    // Push character to stack
    void push(char ch) {
        if (top == MAX - 1)
            cout << "Stack Overflow!" << endl;
        else
            arr[++top] = ch;
    }

    // Pop character from stack
    char pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        } else
            return arr[top--];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s;
    char str[MAX];

    cout << "Enter a string: ";
    cin >> str;

    int n = strlen(str);

    // Push all characters into stack
    for (int i = 0; i < n; i++)
        s.push(str[i]);

    // Pop all characters and form reversed string
    cout << "Reversed string: ";
    while (!s.isEmpty())
        cout << s.pop();

    cout << endl;
    return 0;
}
