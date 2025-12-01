#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[1000],b[1000];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++) mp[a[i]]++;
    for(int i=0;i<n;i++) mp[b[i]]--;
    for(auto x:mp){
        if(x.second!=0){
            cout<<"false";
            return 0;
        }
    }
    cout<<"true";
}
