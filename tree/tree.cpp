#include<iostream>
#include<queue>
#include<map>
using namespace std;
class Node{
public:
int data;
Node* right;
Node* left;

Node(int val){
    this->data = val;
    this->left = NULL;
    this->right = NULL;
}

};

Node* createTree(){
    cout<<"enter the value for the node: ";
    int value;
    cin>>value;
    if(value==-1){
        return NULL;
    }

    //create node
    Node* root = new Node(value);
    cout<<"Enter in left of: "<<value<<endl;
    root->left=createTree();
    cout<<"enter in right of: "<<value<<endl;
    root->right = createTree();
 return root;
}

void PreOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(Node* root){
    if(root == NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}
void InOrder(Node* root){
    if(root == NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

    //level order
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


    void printLeftView(Node* root, int level, vector<int> &leftView){
        if(root == NULL){
            return;
        }
        if(level == leftView.size()){
            // left view ka node mil gaya
        leftView.push_back(root->data);

        }
        printLeftView(root->left,level+1,leftView);
        printLeftView(root->right,level+1,leftView);
    }

    void printrightView(Node* root, int level, vector<int> &rightView){
        if(root == NULL){
            return;
        }
        if(level == rightView.size()){
            // left view ka node mil gaya
        rightView.push_back(root->data);

        }
        printrightView(root->right,level+1,rightView);
        printrightView(root->left,level+1,rightView);
    }

void topview(Node* root){
    map<int,int> hdToNode;
    queue<pair<Node*,int>> q; // node and node level/distance
    q.push(make_pair(root,0));
    cout<<endl;
    while (!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // if there is no entry for hd in map , then create a new entry , hd stand for horizontal distance of top view -1, 0,+1
        if(hdToNode.find(hd) == hdToNode.end()){
            hdToNode[hd] = frontNode->data;
        }

        // child ko dekhlo
        if(frontNode->left!=NULL){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right!=NULL){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    for(auto i: hdToNode){
        cout<<i.second<<" ";
    }
    
}

void bottomview(Node* root){
    map<int,int> hdToNode;
    queue<pair<Node*,int>> q; // node and node level/distance
    q.push(make_pair(root,0));
    cout<<endl;
    while (!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // if there is no entry for hd in map , then create a new entry , hd stand for horizontal distance of top view -1, 0,+1


        // if(hdToNode.find(hd) == hdToNode.end()){
        //     hdToNode[hd] = frontNode->data;
        // } this condn should be remove to overwrite the values


hdToNode[hd] = frontNode->data; // overwrite the value
        // child ko dekhlo
        if(frontNode->left!=NULL){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right!=NULL){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    for(auto i: hdToNode){
        cout<<i.second<<" ";
    }
    
}

void printLeftBoundary(Node* root){
    if(root == NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }

    cout<<root->data<<" ";

    if(root->left != NULL){
        printLeftBoundary(root->left);
    }
    else{
        printLeftBoundary(root->right);
    }
}

 void leafBoundary(Node * root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right == NULL){
        cout<<root->data<<" ";
    }
    leafBoundary(root->left);
    leafBoundary(root->right);
 }

 void printRightBoundary(Node* root){
    if(root == NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }


    if(root->right != NULL){
        printLeftBoundary(root->right);
    }
    else{
        printLeftBoundary(root->left);
    }
    cout<<root->data<<" ";
 }

 void BoundaryTraversal(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" "; // print root node
    printLeftBoundary(root->left);
    leafBoundary(root);
    printRightBoundary(root->right);
   
   
 }
int main()
{
    //10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112-1 -1 113 -1 -1

    Node * root = createTree();

    // levelOrd(root);
    // cout<<"printing left view"<<endl;
    // vector<int> leftView;
    // // printLeftView(root,0,leftView);
    // printrightView(root,0,leftView);

    // for (int i = 0; i < leftView.size(); i++)
    // {
    //     cout<<leftView[i]<<" ";
    // }
    // topview(root);
    // bottomview(root);
    BoundaryTraversal(root);

return 0;
}