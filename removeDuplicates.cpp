#include <iostream>
using namespace std;

int main() {
    int arr[100], n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements (sorted): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int j = 0; 
    for (int i = 1; i < n; i++) {
        if (arr[j] != arr[i]) {
            j++;
            arr[j] = arr[i];
        }
    }
    n = j + 1;

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
