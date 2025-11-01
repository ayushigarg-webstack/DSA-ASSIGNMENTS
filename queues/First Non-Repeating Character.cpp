#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    int freq[26] = {0};  // frequency of each lowercase letter

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        freq[ch - 'a']++;   // increase frequency
        q.push(ch);         // push character into queue

        // remove characters from front which are repeating
        while (!q.empty() && freq[q.front() - 'a'] > 1)
            q.pop();

        // if queue is empty -> no non-repeating char
        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Enter the string (characters separated by spaces optional): ";
    getline(cin, str);

    // remove spaces (if input like "a a b c")
    string cleaned = "";
    for (char c : str)
        if (c != ' ')
            cleaned += c;

    cout << "Output: ";
    firstNonRepeating(cleaned);

    return 0;
}
