#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int A[1000],B[1000];
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<m;i++) cin>>B[i];
    unordered_set<int> s;
    for(int i=0;i<n;i++) s.insert(A[i]);
    for(int i=0;i<m;i++) if(s.count(B[i])) cout<<B[i]<<" ";
}
