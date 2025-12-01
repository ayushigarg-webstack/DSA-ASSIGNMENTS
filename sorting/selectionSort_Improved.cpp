#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n){
    int l=0, r=n-1;
    while(l<r){
        int min=l, max=l;
        for(int i=l;i<=r;i++){
            if(a[i]<a[min]) min=i;
            if(a[i]>a[max]) max=i;
        }
        int t=a[l]; a[l]=a[min]; a[min]=t;
        if(max==l) max=min;
        t=a[r]; a[r]=a[max]; a[max]=t;
        l++; r--;
    }
}

int main(){
    int n; cin>>n;
    int a[1000];
    for(int i=0;i<n;i++) cin>>a[i];
    improvedSelectionSort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
