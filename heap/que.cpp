#include<iostream>
#include<queue>
#include<climits>
using namespace std;

// kth smallest element
int getKthSmallestelement(int arr[],int k,int n){
    priority_queue<int>   pq;
    //first k element in heap
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    //remaining element ko tabhi insert krenge jb wo root se choote honge
    for (int i = k; i < n; i++)
    {
        int element = arr[i];
        if(pq.top()> element){

            pq.pop();
            pq.push(element);
        }
    }
    
    int ans = pq.top();
    return ans;
}
// kth greatest element
int kthgreatestelement(int arr[],int k,int n){
    priority_queue<int,vector<int>, greater<int> >   pq;
    //first k element in heap
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    //remaining element ko tabhi insert krenge jb wo root se choote honge
    for (int i = k; i < n; i++)
    {
        int element = arr[i];
        if(pq.top()< element){

            pq.pop();
            pq.push(element);
        }
    }
    
    int ans = pq.top();
    return ans;
}
class info{
    public:
    int maxVal;
     bool isHeap;
     info(int a, bool b){
        this->maxVal = a;
        this->isHeap = b;
     }
     info(){

     }
};
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data = d;
        this->left = 0;
        this->right = 0;
    }
};
//given cbt is heap or not
info checkMaxHeapCBT(Node* root){
    //base case
   if(root = NULL){
        info temp;
        temp.isHeap = true;
        temp.maxVal = INT_MIN;
        return temp;

    }
    //leaf node
    if(root->left==0 && root->right == 0){
        info temp;
        temp.isHeap = true;
        temp.maxVal = root->data;
        return temp;
    }
    info leftAns = checkMaxHeapCBT(root->left);
    info rightAns = checkMaxHeapCBT(root->right);

    //1 case muje solve krna hai
    if(root->data>leftAns.maxVal && root->data>rightAns.maxVal && leftAns.isHeap && rightAns.isHeap){
        info ans;
        ans.maxVal = root->data;
        ans.isHeap = true;
        return ans;
    } else{
        info ans;
        ans.maxVal = max(root->data,max(leftAns.maxVal,rightAns.maxVal));
        ans.isHeap = false;
    }
}

int main()
{
 int arr[] = {3,5,4,6,9,8,7}; 
 int n = 7;
 int k = 3;
 int m = getKthSmallestelement(arr,k,n);
//  cout<<m<<endl;
int j = kthgreatestelement(arr,k,n);
cout<<j<<endl;


return 0;
}