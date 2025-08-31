#include<iostream>
using namespace std;
void sorting(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
        
    }
    
}
int main()
{
    int arr[] = {2, 0, 1, 2, 1, 0, 0, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"before sorting : "<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sorting(arr,size);
    cout<<"after sorting : "<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}