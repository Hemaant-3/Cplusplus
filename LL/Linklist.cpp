#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        // cout<<"Default ctor"<<endl;
        this->next = NULL;
    }
    Node(int data)
    {
        // cout<<"Param ctor"<<endl;
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        cout<<"Dtor for: "<<data;
    }
};

void printll(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}
int llofl(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        /* code */
        count++;
        temp = temp->next;
    }
    return count;
}
void insertatHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // empty LL
        // step 1: create new node
        Node *newnode = new Node(data);
        // update head
        head = newnode;
        tail = newnode;
    }
    else
    {
        // create a new node
        Node *NewNode = new Node(data);
        // attached new node
        NewNode->next = head;
        // update Head
        head = NewNode;
    }
}

void insertAtEnd(Node* &head, Node* &tail, int data){
if(head == NULL){
// node is empty
    // creation of new node
    Node* newnode = new Node(data);
    //update head and tail
    head = newnode;
    tail = newnode;
} else{
    // create a new node
    Node* newnode = new Node(data);
    //attach new node
    tail->next = newnode;
    // update tail
    tail = newnode;
}
}

  void insertAtPos(Node* &head, Node* &tail, int data, int position){
    int length = 0;
    Node* temp = head;

    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }


    if(position<=1){
        insertatHead(head,tail,data);
    }
else if(position>=length+1){
        insertAtEnd(head,tail,data);
    }
  else{
    //create a new node
    Node* newNode = new Node(data);
    Node* curr = head;
    Node* prev = NULL;
    //traverse curr/prev node
    while(position!=1){
        prev = curr;
        curr = curr->next;
        position--;
    }
    // attach the node
    // prev->next = newNode;
    // newNode->next = curr;

    //using single pointer;
    newNode->next = prev->next;
    prev->next = newNode;

  }
    
    
    }

void deleteNode(Node* &head, Node* &tail, int position){
   int len = llofl(head);
    if(head==NULL){
        // empty ll
        cout<<"Cannot delete coz list is empty"<<endl;
        return;
    }
    else if(head==tail){
        // single element
        Node * temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    else if(position==1){
        // delete head
        Node* temp = head;
        head = head->next;
        temp->next = NULL; //isolate the node.
        delete temp; // it calls destructor.
    }
    
    else if(position==len){
        //delete tail
        //find prev
        Node* prev = head;
        while(prev->next != tail){
            prev = prev->next;
        }
        // prev next nul
        prev->next = NULL;

        //delete node
        delete tail;

        //update tail
        tail = prev;
    }
    else{
        // delete some middle element.

        //traverse curr/prev
        Node* prev = NULL;
        Node * curr = head;
        while (position != 1){
            prev = curr;
            curr = curr->next;
            position--;
        }
         //prev next me curr ke next ko add kro

         prev->next = curr->next;

         //node isolate kro

         curr->next = NULL;

         // delete kro 
         delete curr;
       
        
            }
}

int main()
{

Node* head = NULL;
Node* tail = NULL;

insertAtEnd(head,tail,20);
// insertAtEnd(head,tail,30);
// insertAtEnd(head,tail,40);
// insertAtEnd(head,tail,50);
// insertAtEnd(head,tail,60);
// printll(head);
// cout<<endl<<endl;
// insertAtPos(head,tail,10,1);
// insertAtPos(head,tail,90,4);
printll(head);
cout<<endl<<endl;
deleteNode(head,tail,1);
// deleteNode(head,tail,5);
// deleteNode(head,tail,3);
printll(head);

    /*
    // static object creation
    //   Node a;
    //  dynamic object crtation
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(13);
    Node *Fourth = new Node(40);
    Node *fifth = new Node(60);

    first->next = second;
    second->next = third;
    third->next = Fourth;
    Fourth->next = fifth;
    // hurry ll is created;

    Node *head = first;
    Node *tail = fifth;
    printll(head);
    // cout<<endl;
    // cout<<llofl(head)<<endl;
    cout << endl
         << endl;
    insertatHead(head, tail, 200);
    printll(head);
*/
    return 0;
}