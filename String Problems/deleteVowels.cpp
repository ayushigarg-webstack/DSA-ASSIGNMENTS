#include <iostream>
#include<string>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void deleteVowels(char str[]) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (!isVowel(str[i])) {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    deleteVowels(str);
    cout << "String after deleting vowels: " << str << endl;

    return 0;
}
