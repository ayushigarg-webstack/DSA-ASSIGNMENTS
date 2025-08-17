#include <iostream>
using namespace std;

#define SIZE 100

int arr[SIZE], n = 0;

void create() 
{
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }    
}

void display() 
{
    if (n == 0)
    { 
        cout << "Array is empty\n"; 
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }   
    cout << endl;
}

void insertElement() 
{
    int pos, val;
    cout << "Enter position (0-based index): "; 
    cin >> pos;
    cout << "Enter value: "; 
    cin >> val;
    if (pos < 0 || pos > n) 
    { 
        cout << "Invalid position\n";  
    }
    for (int i = n; i > pos; i--) 
    {
        arr[i] = arr[i-1];
    }
    arr[pos] = val;
    n++;
}

void deleteElement() 
{
    int pos;
    cout << "Enter position to delete (0-based index): "; 
    cin >> pos;
    if (pos < 0 || pos >= n) 
    { 
        cout << "Invalid position\n";
    }
    for (int i = pos; i < n-1; i++) 
    {
        arr[i] = arr[i+1];
    }    
    n--;
}

void linearSearch() {
    int key, flag = 0;
    cout << "Enter element to search: "; cin >> key;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == key) 
        {
            cout << "Element found at index " << i << endl;
            flag = 1; 
            break;
        }
    }
    if (!flag) 
    {
        cout << "Element not found\n";
    }    
}

int main() 
{
    int choice;
    do 
    {
        cout << "\n---MENU---\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) 
        {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while(choice != 6);
    return 0;
}
