#include <iostream>
#include <queue>
#include <deque>
using namespace std;

class Queue
{
public:
    int front;
    int *arr;
    int rear;
    int size;

    Queue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }
    void push(int val)
    {
        if (rear == size - 1)
        {
            // full overflow
            cout << "Overflow" << endl;
            return;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else
        {
            // normal case
            rear++;
            arr[rear] = val;
        }
    }
    void pop()
    {
        if (front == -1 && rear == -1)
        {
            cout << "underflow" << endl;
            return;
        }
        else if (front == rear)
        {
            // empty case for single element
            arr[front] = -1;
            front = 1;
            rear = -1;
        }
        else
        {
            // normal case
            arr[front] = -1;
            front++;
        }
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getSize()
    {
        if (front == -1 && rear == -1)
        {
            return 0;
            // yhh bhool jata hoon
        }
        else
            return rear - front + 1;
    }

    int getfront()
    {
        if (front == -1)
        {
            cout << "No element found" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
    void print()
    {
        cout << "printing queue" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class cQueue
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    cQueue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }
    void push(int val)
    {
        // overflow
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            cout << "overflow" << endl;
            // yaha condn 2 likne me log mistake krte hai
        }
        // empty cas
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
            // single element log handle krna bhool jate hai
        }
        // circular
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = val;
        }
        // normal
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    void pop()
    {
        // underflow
        // single element case
        // circular
        // normal
        if (front == -1 && rear == -1)
        {
            cout << "underflow" << endl;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
            // single eleent me mistake krte hai
        }
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    void print()
    {
        cout << "printing queue" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Deque
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    Deque(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }
    void pushBack(int val)
    {
         // overflow
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            cout << "overflow" << endl;
            // yaha condn 2 likne me log mistake krte hai
        }
        // empty cas
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
            // single element log handle krna bhool jate hai
        }
        // circular
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = val;
        }
        // normal
        else
        {
            rear++;
            arr[rear] = val;
        }
    }
    void pushFront(int n)
    {
        //overflow
        //empty
        //normal
        if((front==0 && rear==size-1)||(rear==front-1)){
            cout<<"overflow"<<endl;
        }
        else if(front==-1 && rear==-1){
            front++;
            rear++;
            arr[front] = n;
        }
        else if(front==0 && rear!=size-1){
            front = size-1;
            arr[front] = n; // circual nature maintain
        }
        else{
            front--;
            arr[front] = n;
        }
    }
    void popFront()
    {
        // underflow
        // single element case
        // circular
        // normal
        if (front == -1 && rear == -1)
        {
            cout << "underflow" << endl;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
            // single eleent me mistake krte hai
        }
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }
    void popBack()
    {
        //underflow
        //single element
        //normal
        if(front==-1 && rear==-1){
            cout<<"underflow"<<endl;
        } else if(front==rear){
            arr[rear] = -1;
            front = -1;
            rear=-1;
        } 
        else if(rear==0){
            arr[rear] = -1;
            rear = size-1; // circular nature
        }
        
        else{
            arr[rear] = -1;
            rear--;
        }
    }
};
int main()
{
    // queue<int> q;
    // q.push(5);
    /*
        Queue q(5);
        q.push(10);
        q.push(20);
        q.push(30);
        q.push(40);
        q.push(50);
        q.print();

        q.pop();
        q.print();
        cout<<q.getSize()<<endl;

        cout<<q.isEmpty()<<endl;

        q.push(20);
    */

    /*
    cQueue q(5);
    q.print();
        q.push(10);
        q.print();

        q.push(20);
        q.push(30);
        q.push(40);
        q.push(50);

        q.print();
        q.push(50);

        q.pop();
        q.pop();
        q.pop();
        q.print();

        q.push(55);
        q.print();
        q.push(110);
        q.print();
        q.push(230);
        q.print();
        q.push(330);
        q.print();
        */

    //    deque<int> dq;
    //    dq.push_back(10);
    //    dq.push_front(20);
    //    cout<<dq.size()<<endl ;
    //    cout<<dq.front()<<endl;
    //    cout<<dq.back()<<endl;

Deque dq(3);
dq.pushBack(10);
dq.pushFront(20);

    return 0;
}