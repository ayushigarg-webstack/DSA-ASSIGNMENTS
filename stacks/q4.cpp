#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(char ch) {
        if (top == MAX - 1)
            cout << "Stack Overflow!" << endl;
        else
            arr[++top] = ch;
    }

    char pop() {
        if (top == -1)
            return '\0';
        else
            return arr[top--];
    }

    char peek() {
        if (top == -1)
            return '\0';
        else
            return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Function to determine precedence of operators
int precedence(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        // If operand, add to output
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix[j++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            s.push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                postfix[j++] = s.pop();
            s.pop(); // remove '('
        }
        // If operator, pop higher or equal precedence operators
        else if (isOperator(ch)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch))
                postfix[j++] = s.pop();
            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.isEmpty())
        postfix[j++] = s.pop();

    postfix[j] = '\0'; // null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    cout << "Enter an infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
