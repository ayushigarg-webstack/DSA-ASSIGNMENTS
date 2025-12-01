#include <iostream>
using namespace std;
void selectionSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]) min=j;
        }
        int t=a[i]; a[i]=a[min]; a[min]=t;
    }
}
int main(){
    int n; cin>>n;
    int a[1000];
    for(int i=0;i<n;i++) cin>>a[i];
    selectionSort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
