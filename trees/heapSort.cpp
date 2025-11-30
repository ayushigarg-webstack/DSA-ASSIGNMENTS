#include<iostream>
#include<vector>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    } 
};
void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if(largest != i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapSort(vector<int>&arr)
{
    int n = arr.size();
    for(int i = n/2 - 1; i > 0; i--)
    {
        heapify(arr,n,i);   
    }
    for(int i = n-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }
}
void storeTree(Node *root, vector<int>&arr)
{
    if(root == NULL)
    return;
    storeTree(root->left, arr);
    arr.push_back(root->data);
    storTree(root->right, arr);
}
void printArray(const vector<int>&arr)
{
    for(int val : arr)
    {
        cout<<val<< " ";
    }
    cout<<endl;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    vector<int> elements;
    storeTree(root, elements);

    cout << "Tree elements (Inorder): ";
    printArray(elements);

    heapSort(elements);        

    cout << "Sorted elements (using Heap Sort): ";
    printArray(elements);

    return 0;

}