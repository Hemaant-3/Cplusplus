#include <iostream>
using namespace std;
class stack
{
public:
    int *arr;
    int top;
    int size;

    // ctor
    stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "stack overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "stack underflow" << endl;
            return;
        }
        else
        {
            top--;
        }
    }
    int getTop()
    {
        if (top == -1)
        {
            cout << "Empty stack" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
    int getSize()
    {
        return top + 1;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print()
    {
        // cout << "Top: " << top;
        // cout << "Top element: " << getTop() << endl;
        for (int i = getSize() - 1; i >= 0; i--)

        {

            cout << arr[i];
            cout << endl;
        }
        cout << endl
             << endl;
    }
};

class stack2
{
public:
    int *arr;
    int size;
    int top1;
    int top2;
    stack2(int size)
    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }
    void push1(int data){
        if(top2-top1==1){
            cout<<"stack overflow"<<endl;
        } else{
            top1++;
            arr[top1] = data;
        }
    }
      void push2(int data){
        if(top2-top1==1){
            cout<<"stack overflow"<<endl;
        } else{
            top2--;
            arr[top2] = data;
        }
    }

    void pop1(){
        if(top1==-1){
            cout<<"stack underflow"<<endl;
        } else{
            top1--;
        }
    }
    void pop2(){
        if(top2==size){
            cout<<"stack underflow"<<endl;
        } else{
            top2++;
        }
    }

    auto getTop1(){
        if(top1==-1){
            cout<<"stack is empty" <<endl;
            return -1;
        } else{
            return arr[top1];
        }
    }
    auto getTop2(){
        if(top2==size){
            cout<<"stack is empty"<<endl;
            return size;
        } else{
            return arr[top2];
        }
    }
    
};
int main()
{
    stack2 st(5);
    st.push1(1);
    st.push1(2);
    st.push2(3);
    st.push2(4);
    st.pop1();
    st.pop1();
    st.pop1();
    st.pop2();
    st.pop2();
    st.pop2();

    // stack st(5);
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // st.push(4);
    // st.push(4);
    // st.push(4);

    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    // // st.pop();
    // cout << "Top1 element: " << st.getTop() << endl;
    // cout << "Top2 element: " << st.getTop();

    cout << "Top1 element: " << st.getTop1() << endl;
    cout << "Top2 element: " << st.getTop2();

    // st.print();
    // st.push(5);
    // st.pop();

    // st.print();
    // st.pop();
    // st.pop();
    // st.pop();
    // st.print();

    return 0;
}