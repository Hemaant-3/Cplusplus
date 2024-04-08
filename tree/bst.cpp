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
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;

    while (data != -1)      
    {
        root = insertIntoBST(root,data);
    cout<<"Enter data: "<<endl;

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

Node* Minele(Node* root){
    if(root == NULL){
        return NULL;
    }
    Node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}
Node* Maxele(Node* root){
    if(root == NULL){
        return NULL;
    }
    Node* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}

bool searchBST(Node* root, int target){
    if(root == NULL){
        return false;
    }
    // 1 case muje solve krna hai
    if(root->data == target){
        return true;
    }
    bool leftAns = false;
    bool rightAns = false;
    if(target>root->data){
        rightAns = searchBST(root->right,target);
    }
    else{
        leftAns = searchBST(root->left,target);
    }
    return leftAns || rightAns;
}

Node* deleteFromBST(Node* root, int target){
    if(root == NULL){
        return NULL;
    }
    if(root->data == target){
        // 4 cases deletion

        //1- case leaf node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // 2 - case left non null and right null
        else if(root->left != NULL & root->right == NULL){
            Node* childSubtree = root->left;
            delete root;
            return childSubtree;
        }

        // 3 - case left is null and right is not null
        else if(root->left==NULL && root->right!= NULL){
            Node* childSubtree = root->right;
            delete root;
            return childSubtree;
        }

        //4- left is not null and right is not null
        else{
            // a-> left subtree ki max value laao
          Node* maxi =  Maxele(root->left);
          // replacement
          root->data = maxi->data;
          // delete actual maxi wali node
        // mistakes kiiya tha return lik ke
    
          root->left = deleteFromBST(root->left,maxi->data);


          return root;

        }
    }
    // searching 
    else if(root->data>target){
        //left me jao
        // mistakes kiiya tha return lik ke
        // updated tree se jo value mil rhi hai use attach to krna padega na
        root->left = deleteFromBST(root->left,target);
    }
    else{
        //right me jaao
        // mistakes kiiya tha return lik ke
        // updated tree se jo value mil rhi hai use attach to krna padega na
        root->right =  deleteFromBST(root->right,target);
    }
    return root;
}

Node* bstFromInorder(int inorder[], int s, int e){
    // base case
    if(s>e){
        return NULL;
    }
    // 1 case solve kro
    int mid = (s+e)/2;
    int element = inorder[mid];
    Node* root = new Node(element);

     // recursion
     root->left = bstFromInorder(inorder,s,mid-1);
     root->right = bstFromInorder(inorder,mid+1,e);
     return root;
}

//convert bst into sorted doubly ll
void convertBstDll(Node* root, Node* & head){
    if(root ==0){
        return;
    }
    //0 = NULL
    //RNL

    convertBstDll(root->right,head);

    //N
    //node ke left me connection phle se hua pada hai isliye hm left me update nahi kr rhe hai dll bnana ke liye
    //attachong next pointer of current node to head of ll
    root->right = head;
    //attaching prev pointer of head to ll to current node
    if(head!=0){
    head->left = root;
    }
    //head update
    head = root;

    //l
    convertBstDll(root->left,head);
}
void printLL(Node* head){
    Node* temp = head;
    cout<<endl<<"print ll"<<endl;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
    
}
 //convert dll to bst
 Node* convertdllToBst(Node* &head,int n){
    // base
    if(head==0 || n<=0){
        return 0;
    }
//LNR
        //L
        Node* leftSubtree = convertdllToBst(head,n/2);

        //N
        Node* root = head;
        root->left = leftSubtree;
        //head update
        head = head->right;

        //R
        Node* rightSubtree = convertdllToBst(head, n-(n/2)-1);
        root->right = rightSubtree;


        return root;
 }
int main()
{
    /*
     Node* root = NULL;
     createBST(root);
     levelOrd(root);
    //  cout<<endl<<endl;
    //  Node* min = Minele(root);
    //  cout<<min->data<<endl;
    //  Node* max = Maxele(root);
    //  cout<<max->data<<endl;

 50 30 60 25 40 70 80 55 -1
    int t; 
    cout<<"enter the target"<<endl;
    cin>>t;
    while (t!=-1)
    {
        bool ans = searchBST(root,t);
        if(ans == true){
            cout<<"found"<<endl;
        }else{
            cout<<"Not found"<<endl;
        }
        cout<<"enter the target"<<endl;
        cin>>t;
    }
    */
/*
   int target = -1;
   cout<<"enter the value of target"<<endl;
   cin>>target;
   while (target != -1)
   {
    root = deleteFromBST(root,target);
    cout<<"printing level order traversal"<<endl;
    levelOrd(root);

    cout<<"enter the value of target"<<endl;
   cin>>target;
   }
   
int inorder[] = {10,20,30,40,50,60,70};
int size = 7;
int s = 0;
int e = size-1;
 Node* root = bstFromInorder(inorder,s,e);
 levelOrd(root);
 Node* head = NULL;
convertBstDll(root,head);
printLL(head);
*/

Node* first = new Node(10);
Node* sec = new Node(20);
Node* thi = new Node(30);
    first->right = sec;
    sec->left = first;
    sec->right = thi;
    thi->left = sec;
    Node* head = first;
    Node* root = convertdllToBst(head,3);
    levelOrd(root);
return 0;
}