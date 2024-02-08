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
   Node* head =  reverse(head);
    //add one
     int carry = 1;
     Node* temp = head;
     while (/* condition */)
     {
        /* code */
     }
     
    //reverse
}
int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    insertatHead(head, tail, 8);
    insertatHead(head, tail, 3);
    insertatHead(head, tail, 1);
    printll(head);
    return 0;
}