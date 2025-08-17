#include <iostream>
#include<string>
using namespace std;

int main() {
    string firstname = "Hello";
    string lastname = "World";

   firstname = firstname +" "+ lastname;

    cout << "Concatenated string: " <<firstname<< endl;
    return 0;
}
