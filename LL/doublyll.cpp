#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        prev = NULL;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

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
void printll(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }
}

void insertAtHead(Node* &head, Node* &tail, int data)
{
    // ll is empty
    if (head == NULL)
    {
       
        Node * newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {
        // ll is not empty
        Node * newnode = new Node(data);
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}
int main()
{
    Node *head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,50);
    
    printll(head);
    return 0;
}