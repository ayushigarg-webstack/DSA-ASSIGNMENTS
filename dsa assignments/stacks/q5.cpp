#include <iostream>
#include <cmath>   // for pow()
#include <cstring> // for strlen()
using namespace std;

#define MAX 100

class Stack {
    float arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(float val) {
        if (top == MAX - 1)
            cout << "Stack Overflow!" << endl;
        else
            arr[++top] = val;
    }

    float pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return 0;
        } else
            return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Function to evaluate a postfix expression
float evaluatePostfix(char postfix[]) {
    Stack s;
    int i;
    float op1, op2, result;

    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // If operand (single digit number)
        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0'); // convert char to number
        }

        // If operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            op2 = s.pop();
            op1 = s.pop();

            switch (ch) {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            case '^':
                result = pow(op1, op2);
                break;
            }
            s.push(result);
        }
    }

    return s.pop(); // final result
}

int main() {
    char postfix[MAX];

    cout << "Enter a postfix expression (single-digit operands): ";
    cin >> postfix;

    float result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;

    return 0;
}
