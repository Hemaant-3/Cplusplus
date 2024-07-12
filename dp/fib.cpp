#include<iostream>
#include<vector>
using namespace std;
int fibdp(int n, vector<int> &dp){
    //base case 
    if(n==1 || n==0){
        return n;
    }

    // dp store ans
    if(dp[n]!=-1){
        return dp[n];
    }
// store ans
    dp[n] = fibdp(n-1,dp) + fibdp(n-2,dp); 
    return dp[n];
}
int solveUsingTabulation(int n){
    //step1: create dp array
    vector<int> dp(n+1,-1);

    // step2 : analyse base case and fill manually
    dp[0] = 0; // dp[0] represent 1st term of fibonacci series
    if(n==0){
        return dp[0];
    }
    dp[1] = 1;

    //step3: fill remainig array
    //size = n+1;
    // index-> 0 - n
    // index fill ho chuka h 0 and 1
    //remaining index konsa = 2 - n
    for (int i = 2; i <= n; i++)
    {
        // for loop ke ander copy paste ke baad recursion ko dp me convert kr dena hai
        dp[i] = dp[i-1]+dp[i-2];
    }
    //answer return
    return dp[n];
}

//space optimization in tabulation method

int solveUsingTaboptz(int n){
    int prev = 0;
    if(n==0){
        return 0;
    }
    int curr = 1;

    if(n==1){
        return 1;
    }
    int ans = 0;

    for (int i = 2; i <= n; i++)
    {
        ans = prev+curr;
        // mt bhoolna
        prev = curr;
        curr=ans;

    }
    return ans;
}
int main()
{
    int n = 6;
// vector<int> dp(n+1,-1);

// int z = fibdp(n,dp);
// for (int i = 0; i < dp.size(); i++)
// {
//     cout<<dp[i]<<" ";
// }
// cout<<endl;
// cout<<z;
// int  z = solveUsingTabulation(n);
int  z = solveUsingTaboptz(n);
cout<<z<<" ";
return 0;
}