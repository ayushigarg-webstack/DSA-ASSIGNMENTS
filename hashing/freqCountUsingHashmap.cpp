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
    for(auto x:mp) cout<<x.first<<" "<<x.second<<"\n";
}
