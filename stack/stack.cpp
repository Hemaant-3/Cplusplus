
#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int> st, int pos, int &ans){
    //base
    if(pos==1){
        ans = st.top();
        return;
    }
    // 1 case h, solve
    pos--;
    int temp = st.top();
    st.pop();

    //recusrion
    solve(st,pos,ans);

    //backtrack
    st.push(temp);
}

int getMiddleElemene(stack<int> st){
    int size = st.size();
    if(st.empty()){
        return -1;
    } 
    else{
        //stack is not empty
        // odd
        int pos = 0;
        if(size&1){
            pos = (size/2)+1;
        } else{
            // even
            pos = size/2;

        }
        int ans = -1;
        solve(st,pos,ans); 
        return ans; 
    }
}

void insertatBottom(stack<int> &st, int &element){
    // base case
    if(st.empty()){
        st.push(element);
        return;
    }
    // 1 case mai slove kkrunga
    int temp = st.top();
    st.pop();

    //backi recursion
    insertatBottom(st,element);

    // backtrack
    st.push(temp);
}

void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    // 1 case mai solve krunga
    int temp = st.top();
    st.pop();

    //recursion
    reverseStack(st);
    // bactrack
    insertatBottom(st,temp);
}
int main()
{
stack<int> st;
st.push(10);
st.push(20);
st.push(40);
st.push(30);

// int mid = getMiddleElemene(st);
// cout<<st.size()<<endl;
// cout<<st.top()<<endl;
// // cout<<mid<<endl;
// int element = 400;
// insertatBottom(st,element);

reverseStack(st);
while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
}
}