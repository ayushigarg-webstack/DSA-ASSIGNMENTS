#include <iostream>
using namespace std;

int missingNumber(int arr[], int n)
{
    int low = 0, high = n - 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] != mid + 1)
        {
            if (mid == 0 || arr[mid - 1] == mid)
            {
                return mid + 1;
            }
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return n;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int n = 8;
    cout << "Missing number is: " << missingNumber(arr, n) << endl;
    return 0;
}
