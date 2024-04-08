#include<iostream>
#include<queue>
#include<map>
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
// it return root node of tree
Node* createTree(){ 
    cout<<"enter the value"<<endl;
    int data;
    cin>>data;
    if(data== -1){
        return NULL;
        // base case....
        // -1 for stop creating tree
    }

    // step1 create done
    Node* root = new Node(data);

    //step2 create left subtree
    cout<<"left of Node: "<<root->data<<endl;
    root->left = createTree();

    //step3 create right subtree
    cout<<"right of Node: "<<root->data<<endl;

    root->right = createTree();
    return root;
}

void preOrderTraversal(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    // NLR
    //N
    cout<<root->data<<" ";
    //L
    preOrderTraversal(root->left);
    //R
    preOrderTraversal(root->right);
}

void inOrederTr(Node* root){
    if(root==NULL){
        return;
    }
    //LNR
    // L
    inOrederTr(root->left);
    //N
    cout<<root->data<<" ";
    //R
    inOrederTr(root->right);
}

void postOrderTr(Node* root){
    if(root==NULL){
        return;
    }
    //LRN
    //L
    postOrderTr(root->left);
    //R
    postOrderTr(root->right);
    //N
    cout<<root->data<<" ";
}

void LevelOrder(Node* root){
queue<Node*> q;
q.push(root);

    // asli traversal
    while (!q.empty())
    {
        /* code */
        Node* front = q.front();
        q.pop();
        cout<<front->data<<" ";

        if(front->left!=NULL){
            q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
        }
    }
    
}


void LevelOrderTre(Node* root){
    queue<Node*> q;
        q.push(root);
    q.push(NULL);

    // asli traversal
    //** while (q.size()>1)
    while(!q.empty())
    {
        /* code */
        Node* front = q.front();
        q.pop();

        if(front==NULL){
            cout<<endl;
            //** q.push(NULL); // check marks for level complete

            if(!q.empty()){
                q.push(NULL); // work with While(!q.empty())
            }
        }
else{
        cout<<front->data<<" ";

        if(front->left!=NULL){
            q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
        }
    }
    }
}



int searchpos(int inorder[],int element,int size){
    for (int i = 0; i < size; i++)
    {
        if(inorder[i]==element){
            return i;
        }
    }
    return -1;
    
}


void createMap(int inorder[],int size, map<int,int> &valueMap){
    for (int i = 0; i < size; i++)
    {
        int value = inorder[i];
        int index = i;
        valueMap[value] = index;
    }
    
}

Node* ConstructTreeFromPerePost(map<int,int> &PosMap,int preOrder[],int inOrder[],int &preIndex, int inorderStart, int inorderEnd, int size){
    // base case
    if(preIndex>=size || inorderStart>inorderEnd){
        return NULL;
    }
    // 1case mai solve krunga
    int element = preOrder[preIndex];
    preIndex++;
    Node* root = new Node(element);
    // int position = searchpos(inOrder,element,size);
    int position = PosMap[element];

    root->left = ConstructTreeFromPerePost(PosMap,preOrder,inOrder,preIndex,inorderStart,position-1,size);

    root->right = ConstructTreeFromPerePost(PosMap,preOrder,inOrder,preIndex,position+1,inorderEnd,size);

    return root;
}

Node* ConstructTreeFromInoPost(map<int,int> &PosMap,int postorder[],int inOrder[],int &postIndex, int inorderStart, int inorderEnd, int size){

    if(postIndex< 0 || inorderStart>inorderEnd){
        return NULL;
    }
    // 1 case solve
        int element = postorder[postIndex];
        postIndex--;
        Node* root = new Node(element);
        int position = PosMap[element];
         


    //backi recursion
    // rigth ki call phle rhegi qki postorder = LRN == N->R->L
    root->right = ConstructTreeFromInoPost(PosMap,postorder,inOrder,postIndex,position+1,inorderEnd,size);
    root->left = ConstructTreeFromInoPost(PosMap,postorder,inOrder,postIndex,inorderStart,position-1,size);
    return root;
}
int main()
{
//  Node* root = createTree();
//  cout<<endl<<endl;
//  preOrderTraversal(root);
//  cout<<endl<<endl;
//  inOrederTr(root);
//  cout<<endl<<endl;
//  postOrderTr(root); 
// LevelOrder(root);
// LevelOrderTre(root);


/*
int inorder[] = {10,8,6,2,4,12};
int preorder[] = {2,8,10,6,4,12};
 int size = 6;
 int preOrderIndex = 0;
 int inorderStart = 0;
 int inorderEnd = 5;
map<int,int> PosMap;
createMap(inorder,size,PosMap);
Node* root = ConstructTreeFromPerePost(PosMap,preorder,inorder,preOrderIndex,inorderStart,inorderEnd,size);

LevelOrderTre(root);
*/
int inorder [] = {8,14,6,2,10,4};
int postorder[] = {8,6,14,4,10,2};
int size = 6;
int postIndex = size-1;
int inOrds = 0;
int inOrde = size - 1;
map<int,int> PosMap;
createMap(inorder,size,PosMap);
Node* root = ConstructTreeFromInoPost(PosMap,postorder,inorder,postIndex,inOrds,inOrde,size);

LevelOrderTre(root);
return 0;
}