#include <iostream>
using namespace std;

struct PQueue {
    int *arr;
    int capacity;
    int size;
    PQueue(int cap=100){ capacity=cap; arr = new int[capacity]; size=0; }
    ~PQueue(){ delete[] arr; }
    void push(int x){
        if(size==capacity){
            int newcap = capacity*2;
            int* b = new int[newcap];
            for(int i=0;i<size;i++) b[i]=arr[i];
            delete[] arr; arr=b; capacity=newcap;
        }
        int i = size++;
        arr[i] = x;
        while(i>0){
            int p = (i-1)/2;
            if(arr[p] < arr[i]) { int t=arr[p]; arr[p]=arr[i]; arr[i]=t; i=p; }
            else break;
        }
    }
    int top(){ if(size==0) return -1; return arr[0]; }
    void pop(){
        if(size==0) return;
        arr[0] = arr[--size];
        int i=0;
        while(true){
            int l=2*i+1, r=2*i+2, largest=i;
            if(l<size && arr[l]>arr[largest]) largest=l;
            if(r<size && arr[r]>arr[largest]) largest=r;
            if(largest==i) break;
            int t=arr[i]; arr[i]=arr[largest]; arr[largest]=t;
            i=largest;
        }
    }
    bool empty(){ return size==0; }
};

int main(){
    PQueue pq;
    pq.push(5); pq.push(1); pq.push(10); pq.push(7);
    cout<<"Top: "<<pq.top()<<"\n"; // 10
    pq.pop();
    cout<<"Top after pop: "<<pq.top()<<"\n"; // 7
    while(!pq.empty()){ cout<<pq.top()<<" "; pq.pop(); } cout<<"\n";
    return 0;
}
