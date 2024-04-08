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
Node* root = 0;
createBST(root);
cout<<"printing bst"<<endl;
levelOrd(root);

root = convertBSttomaxheap(root);

cout<<endl<<"printing heap"<<endl;
levelOrd(root);


return 0;
}