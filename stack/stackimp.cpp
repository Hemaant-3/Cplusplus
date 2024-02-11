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
        cout<<endl<<endl;
    }
};
int main()
{
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<"Top element: "<<st.getTop()<<endl;
    cout<<"Top element: "<<st.getSize();
    
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