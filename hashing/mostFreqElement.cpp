#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int n; 
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++) cin>>a[i];
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++) mp[a[i]]++;
    int ans=a[0], freq=mp[a[0]];
    for(auto x:mp){
        if(x.second>freq || (x.second==freq && x.first>ans)){
            freq=x.second;
            ans=x.first;
        }
    }
    cout<<ans;
}
