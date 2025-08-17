#include <iostream>
using namespace std;

char toLowercase(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + ('a' - 'A');
    }
    return ch;
}

int main() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    char lower = toLowercase(ch);
    cout << "Lowercase character: " << lower << endl;

    return 0;
}