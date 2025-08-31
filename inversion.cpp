#include<iostream>
using namespace std;
int inversion(int arr[], int size)

{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(arr[i]>arr[j])
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    
    int size;
    cout<<"enter size of the array : ";
    cin>>size;
    int arr[size];
    cout<<"enter elements of array : ";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    int count = inversion(arr,size);
    cout<<"No. of inversions : "<<count;
}    