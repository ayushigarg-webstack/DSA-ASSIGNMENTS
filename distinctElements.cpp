#include<iostream>
using namespace std;
void findUniqueElements(int arr[], int size)
{
    
    int sizeOfDistinct=0;
    for (int i = 0; i < size; i++)
    {
        if(arr[i]!=arr[i+1])
        {
            sizeOfDistinct++;
        }
    } 
}
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
    
    int size;
    cout<<"enter size of the array : ";
    cin>>size;
    int arr[size];
    cout<<"enter elements of array : ";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    sorting(arr,size);
    findUniqueElements(arr,size);
}