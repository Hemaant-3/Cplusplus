#include <iostream>
#include <stack>
#include <string>
#include<vector>
using namespace std;
bool redundantBracket(string &str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            int operatorCount = 0;
            while (!st.empty() && st.top() != '(')
            {
                char temp = st.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
                {
                    operatorCount++;
                }
                st.pop();
            }
            // yaha tk ap tb pachogoge jb stack ke top pr ek opening bracket hoga
            st.pop();

            if (operatorCount == 0)
            {
                // redundant bracket is present
                return true;
            }
        }
    }
    // yaha tk ane ke baad pakka hai, ek brakcet ke pair me ek operator pakka mila hoga
    return false;
}

// next smaller element


vector<int> PrevsmallerEele(int *arr, int size, vector<int> &ans) {
    stack<int> st;
    st.push(-1);

    for(int i = 0; i<size; i++){
        int curr = arr[i];
        // ans find karo curr k liye
        while (st.top()>= curr)
        {
            st.pop();
        }
         ans[i] = st.top();
        st.push(curr);  
    }
    return ans;
}
int main()
{
    /*
    string str = "((a+b)*(c+d))";

    bool ans = redundantBracket(str);
    if (ans == true)
    {
        cout << "Redundant Bracket present" << endl;
    }
    else
    {
        cout << "Redundant Bracket is not present" << endl;
    } */

    int arr[] = {8,4,6,2,3};
    int size = 5;
    vector<int> ans(size);
    ans = nextsmallerEele(arr,size,ans);

for(auto i:ans){
    cout<<i<<" ";
}
cout<<endl;
cout<<endl;
cout<<endl;

    vector<int> prev(size);
    prev = PrevsmallerEele(arr,size,prev);

for(auto i:prev){
    cout<<i<<" ";
}

    return 0;
}