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
            return '\0'; // return null character when empty
        else
            return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Function to check for balanced parentheses
bool isBalanced(char expr[]) {
    Stack s;
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }

        // If closing bracket, pop and check
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty())
                return false; // no matching opening bracket

            char topChar = s.pop();

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false; // mismatched pair
            }
        }
    }

    // If stack is empty, all brackets matched
    return s.isEmpty();
}

int main() {
    char expr[MAX];

    cout << "Enter an expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "The expression has balanced parentheses." << endl;
    else
        cout << "The expression does NOT have balanced parentheses." << endl;

    return 0;
}
