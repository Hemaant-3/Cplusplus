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
    ~Node()
    {
        cout << "Dtor for: " << data;
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


Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;

    while (curr!=NULL)
    {
        Node *  next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void addONe(Node *&head)
{
    //reverse list
   head =  reverse(head);
    //add one
     int carry = 1;
     Node* temp = head;
     while (temp->next!=NULL)
     {
        /* this handle upto 2nd last node. */
        int totalSum = temp->data+carry;
        int digit = totalSum%10;
        carry = totalSum/10;

        temp->data = digit;
        temp = temp->next;
        if(carry==0){
            break;
        }
     }

     // processing last node
     if(carry!=0){
         int totalSum = temp->data+carry;
         int digit = totalSum%10;
         carry = totalSum/10;


         temp->data = digit;
         if(carry!=0){
            Node* newnode = new Node(carry);
            temp->next = newnode;
         }
     }
     
    //reverse
    head = reverse(head);
}


int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    insertatHead(head, tail, 9);
    // insertatHead(head, tail, 9);
    // insertatHead(head, tail, 9);
    printll(head);
    addONe(head);
    cout<<endl;
    printll(head);
    return 0;
}