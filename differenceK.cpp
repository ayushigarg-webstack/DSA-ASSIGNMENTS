#include <iostream>
using namespace std;
int differenceOfK(int arr[], int size, int k)
{
    int pairCount = 0;
    cout<<"No. (i,j)"<<endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(abs(arr[i]-arr[j]==k))
            {
                pairCount++;
                cout<<pairCount<<".  ("<<arr[i]<<","<<arr[j]<<")"<<endl;
            }
        }
        
    }
    return pairCount;
}
int main()
{
    int size;
    cout << "enter size of array : ";
    cin >> size;
    cout << "enter elements of array : ";
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int k;
    cout << "enter a positive integer k : ";
    cin >> k;
    int noOfPairs = differenceOfK(arr, size, k);
    cout<<noOfPairs<<" number of pairs"<<endl;
}