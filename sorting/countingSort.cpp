#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int a[1000];
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>mx) mx=a[i];
    }
    int c[10000]={0};
    for(int i=0;i<n;i++) c[a[i]]++;
    int idx=0;
    for(int i=0;i<=mx;i++){
        while(c[i]--) a[idx++]=i;
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
