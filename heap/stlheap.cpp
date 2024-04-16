#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }

};

Node* insertIntoBST(Node* root, int data){
    if(root==NULL){
        root = new Node(data);
        return root;
    }
    // its not the first node
    if(data>root->data){
       root->right = insertIntoBST( root->right, data);
    } else{
        root->left = insertIntoBST(root->left,data);
    }
}
void createBST(Node* &root){
    // cout<<"Enter data: "<<endl;
    int data;
    cin>>data;

    while (data != -1)      
    {
        root = insertIntoBST(root,data);
    // cout<<"Enter data: "<<endl;

        cin>>data;
    }
   
}

 void levelOrd(Node* root){
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        cout<<endl;
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            if(temp==NULL){
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            } else{
                cout<<temp->data<<" ";
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }

            }
        }
}
void storeInorder(Node* root,vector<int> &in){
    if(root==0){
        return;
    }
    //LNR
    storeInorder(root->left,in);
    in.push_back(root->data);
    storeInorder(root->right,in);
}
void replaceUsingPost(Node* root,vector<int> in, int &index){
    if(root==0){
        return;
    }
    //LRN
    replaceUsingPost(root->left,in,index);
    replaceUsingPost(root->right,in,index);
    root->data = in[index];
    index++;
}

Node* convertBSttomaxheap(Node* root){
 vector<int> inorder;
 //store in order
 storeInorder(root,inorder);
//replace the node value
int index = 0;
replaceUsingPost(root,inorder,index);
return root;

}

class info{
    public:
    int data;
    int rowIndex;
    int colIndex;

    info(int val, int row, int col){
        this->data = val;
        this->rowIndex = row;
        this->colIndex = col;
    }
};
class compare{
    public:
    bool operator()(info* a, info* b){
        return a->data>b->data;
    }
};

void MergeKsortedArray(int arr[][4],int n, int k,vector<int> &ans){
    priority_queue<info*,vector<info*>,compare>pq;
    //step1: process first k element
    for (int row = 0; row < k; row++)
    {
        int element = arr[row][0];
        info* temp= new info(element,row,0);
        pq.push(temp);
    }
    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        int topData = temp->data;
        int toprow = temp->rowIndex;
        int topcol = temp->colIndex;

        //store ans in vector
        ans.push_back(topData);
        //next element for the same row, jisme se pop kia h just abhi
        // use insert bhi krne hai

        if(topcol+1<n){
            //iska mtlb row me avi element hai
            info* newInfo = new info(arr[toprow][topcol+1],toprow,topcol+1);
            pq.push(newInfo);
        }
    }
    
    
}


int main()
{
//create max heap by default it created
// priority_queue<int> pq;  
//insertion
//creatin of min heap
/*
priority_queue<int,vector<int>,greater<int>>pq;
pq.push(10);
pq.push(20);
pq.push(40);
pq.push(50);
pq.push(30);

cout<<"top element of heap: "<<pq.top();
cout<<endl;
pq.pop();
cout<<"top element of heap: "<<pq.top()<<endl;
cout<<"size of max heap: "<<pq.size();
*/
// Node* root = 0;
// createBST(root);
// cout<<"printing bst"<<endl;
// levelOrd(root);

// root = convertBSttomaxheap(root);

// cout<<endl<<"printing heap"<<endl;
// levelOrd(root);

int arr[3][4] = {
    {1,4,8,11},{2,3,6,10},{5,7,12,14}

};
int n = 4;
int k = 3;
vector<int>ans;
MergeKsortedArray(arr,n,k,ans);
cout<<"printing ans array"<<endl;
for (int i = 0; i < ans.size(); i++)
{
    cout<<ans[i]<<" ";
}



return 0;
}