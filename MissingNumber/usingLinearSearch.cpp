#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 5, 6};
    int n = 6;

    int totalSum = n * (n + 1) / 2;
    int arrSum = 0;

    for (int i = 0; i < n - 1; i++)
    {
        arrSum += arr[i];
    }

    cout << "Missing number is: " << totalSum - arrSum << endl;
    return 0;
}
