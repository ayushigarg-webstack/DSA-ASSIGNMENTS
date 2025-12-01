#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    int n; 
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++) cin>>a[i];
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        if(s.count(a[i])){
            cout<<"true";
            return 0;
        }
        s.insert(a[i]);
    }
    cout<<"false";
}
