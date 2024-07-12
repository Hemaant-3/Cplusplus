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

void insertAtHead(Node *&head, Node *&tail, int data)
{
    // ll is empty
    if (head == NULL)
    {

        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {
        // ll is not empty
        Node *newnode = new Node(data);
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {
        Node *newnode = new Node(data);
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void insertatPos(Node *&head, Node *&tail, int position, int data)
{
    // ll is empty
    int len = llofl(head);
    if (head == NULL)
    {

        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {

        if (position == 1)
        {
            insertAtHead(head, tail, data);
        }
        else if (position == len + 1)
        {
            insertAtTail(head, tail, data);
        }
        else
        {
            // insrt at middle
            Node *newnode = new Node(data);
            // set prev/curr
            Node *prevNode = NULL;
            Node *currNode = head;
            while (position != 1)
            {
                prevNode = currNode;
                currNode = currNode->next;
                position--;
            }
            prevNode->next = newnode;
            newnode->prev = prevNode;

            newnode->next = currNode;
            currNode->prev = newnode;
        }
    }
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    int len = llofl(head);
    if (head == NULL)
    {
        cout << "can't delete empty list" << endl;
        return;
    }
    else
    {
    if(head==tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    else if (position == 1)
        {
            // delete head
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
        }
        else if (position == len)
        {
            // delete tail
            Node *temp = tail->prev;
            temp->next = NULL;
            tail->prev = NULL;
            delete tail;
            tail = temp;
        }
        else
        {

            // delete from middle
            Node *prevNode = NULL;
            Node* currNode = head;
            while(position!=1){
                position--;
                prevNode = currNode;
                currNode = currNode->next;
            }
            Node* nextNode = currNode->next;

            // updation of nodes
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            currNode->prev = NULL;
            currNode->next = NULL;
            delete currNode;
        }
    }
}



int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
    printll(head);
    cout << endl
         << endl;
    // insertAtTail(head,tail,1000);
    // insertatPos(head, tail, 3, 1000);
    // deleteNode(head,tail,3);
    deleteNode(head,tail,1);

    printll(head);
    return 0;
}