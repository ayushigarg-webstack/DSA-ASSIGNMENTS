#include <iostream>
using namespace std;
void occurenceOf2(int arr[], int size)
{
    
    for (int i = 0; i < size; i++)
    {
        
        if(arr[i]==2)
        {
            int n = size-1;
            while(n>i)
            {
                
                arr[n+1] = arr[n];
                n--;
                
            } 
            size++;
            cout<<endl;
            arr[i+1]=2;
            i++;       
        }
    } 
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }  
}
int main()
{
    int arr[] = {4,2,8,1,3,2,3,6,1,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    occurenceOf2(arr,size);
} 

