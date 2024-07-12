
#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int> st, int pos, int &ans)
{
    // base
    if (pos == 1)
    {
        ans = st.top();
        return;
    }
    // 1 case h, solve
    pos--;
    int temp = st.top();
    st.pop();

    // recusrion
    solve(st, pos, ans);

    // backtrack
    st.push(temp);
}

int getMiddleElemene(stack<int> st)
{
    int size = st.size();
    if (st.empty())
    {
        return -1;
    }
    else
    {
        // stack is not empty
        //  odd
        int pos = 0;
        if (size & 1)
        {
            pos = (size / 2) + 1;
        }
        else
        {
            // even
            pos = size / 2;
        }
        int ans = -1;
        solve(st, pos, ans);
        return ans;
    }
}

void insertatBottom(stack<int> &st, int &element)
{
    // base case
    if (st.empty())
    {
        st.push(element);
        return;
    }
    // 1 case mai slove kkrunga
    int temp = st.top();
    st.pop();

    // backi recursion
    insertatBottom(st, element);

    // backtrack
    st.push(temp);
}

void reverseStack(stack<int> &st)
{

    if (st.empty())
    {
        return;
    }
    // 1 case mai solve krunga
    int temp = st.top();
    st.pop();

    // recursion
    reverseStack(st);
    // bactrack
    insertatBottom(st, temp);
}

void insertInSortedManner(stack<int> &st, int element)
{
    // base case
    if (st.empty() || element > st.top()) // ordering matter
    {
        st.push(element);
        return; 
    }
    // 1 case smabhalo
    int temp = st.top();
    st.pop();// check is it empty or not 

    //recursion

    insertInSortedManner(st,element);

    // back track
    st.push(temp);
}

void sortStack(stack<int>&st){
    // base case
    if(st.empty()){
        return;
    }
    // 1 case
   int temp = st.top();
    st.pop();

    // recursion
    sortStack(st);

     // backtrack
     insertInSortedManner(st,temp); 
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(8);
    st.push(11);
    st.push(7);
    st.push(2);

    // int mid = getMiddleElemene(st);
    // cout<<st.size()<<endl;
    // cout<<st.top()<<endl;
    // // cout<<mid<<endl;
    // int element = 400;
    // insertatBottom(st,element);

    // reverseStack(st);
    // insertInSortedManner(st,5);

//2 7 11 8 10

sortStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}