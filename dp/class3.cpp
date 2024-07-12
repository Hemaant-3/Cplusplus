#include <iostream>
#include <vector>
using namespace std;
// solving painting fence;
int solveUsingRec(int n, int k)
{
    // base case
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return k + k * (k - 1);
    }

    int ans = (solveUsingRec(n - 1, k) + solveUsingRec(n - 2, k)) * (k - 1);
    return ans;
}

int solverUsingMem(int n, int k, vector<int> &dp)
{
    // base case
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return k + k * (k - 1);
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = (solverUsingMem(n - 1, k, dp) + solverUsingMem(n - 2, k, dp)) * (k - 1);

    return dp[n];
}
int solveTab(int n, int k)
{
    vector<int> dp(n + 1, -1);
    dp[1] = k;
    dp[2] = k + k * (k - 1);

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
    }
    return dp[n];
}

int spaceopti(int n, int k)
{
    int prev2 = k;
    int prev1 = k + k * (k - 1);
    int curr;
    if (n == 1)
    {
        return prev2;
    }
    if (n == 2)
    {
        return prev1;
    }
    for (int i = 3; i <= n; i++)
    {
        curr = (prev1 + prev2) * (k - 1);
        // shift
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

// solving knapsack problem 2d dp

int solveUsingRecNap(int capacity, int wt[], int profit[], int index, int n)
{
    // base case
     if(index>=n){
        return 0;
    }
    // if (index == n - 1)
    // {
    //     if (wt[index] <= capacity)
    //     {
    //         return profit[index];
    //     }
    //     else
    //     {
    //         return 0; // no profit possible
    //     }
    // }

    // inc / exc
    int include = 0;
    if (wt[index] <= capacity)
    {
        include = profit[index] + solveUsingRecNap(capacity - wt[index], wt, profit, index + 1, n);
    }

    int exclude = 0 + solveUsingRecNap(capacity, wt, profit, index + 1, n);

    int ans = max(include, exclude);
    return ans;

}

    void printdpArray( vector<vector<int>> &dp){
        cout<<endl<<endl<<"printing dp array    "<<endl;
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[0].size(); j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
        cout<<endl<<endl;
    }

int NapSackMem(int capacity, int wt[], int profit[], int index, int n, vector<vector<int>> &dp)
{
    // base case
    // if (index == n - 1)
    // {
    
        // if (wt[index] <= capacity)
        // {
        //     return profit[index];
        // }
        // else
        // {
        //     return 0; // no profit possible
        // }
    // }
    if(index>=n){
        return 0;
    }

    if (dp[capacity][index] != -1)
    {
        return dp[capacity][index];
    }

    // inc / exc
    int include = 0;
    if (wt[index] <= capacity)
    {
        include = profit[index] + NapSackMem(capacity - wt[index], wt, profit, index + 1, n, dp);
    }

    int exclude = 0 + NapSackMem(capacity, wt, profit, index + 1, n, dp);

    dp[capacity][index] = max(include, exclude);
    return dp[capacity][index];
    
}

int NapsackTabu(int capacity, int wt[], int profit[], int n)
{
     vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));

     // base case analyse

     for(int row = 0; row<=capacity;row++){
        //inserting in column
        dp[row][n] = 0;
     }

     for (int i = 0; i <=capacity; i++)
     {
        for (int j = n-1; j >=0; j--)
        {
            // inc / exc
    int include = 0;
    if (wt[j] <= i)
    {
        include = profit[j] + dp[i - wt[j]][j+1];
    }

    int exclude = 0 + dp[i][j+1];

    dp[i][j] = max(include, exclude);
        }
        
     }
     printdpArray(dp);
     return dp[capacity][0];
}

int NapsackTabuSO(int capacity,int wt[],int profit[],int n){
    vector<int>next(capacity+1,0);// we should initiliaze with zero coz base case.
    vector<int>curr(capacity+1,-1);

    for (int j = n-1; j >=0; j--)
    {
        for (int i = 0; i <=capacity; i++)
        {
            int include = 0;
            if (wt[j]<=i)
            {
                include = profit[j]+next[i-wt[j]];
            }
            int exclude = 0 + next[i];
            curr[i] = max(include,exclude);
        }
        //shifting
        next = curr;
        
    }
    return curr[capacity];
}

int NapsackTabuSO2(int capacity,int wt[],int profit[],int n){
    vector<int>next(capacity+1,0);// we should initiliaze with zero coz base case.
    // vector<int>curr(capacity+1,-1);

    for (int j = n-1; j >=0; j--)
    {
        for (int i = capacity; i >=0; i--)
        {
            int include = 0;
            if (wt[j]<=i)
            {
                include = profit[j]+next[i-wt[j]];
            }
            int exclude = 0 + next[i];
            next[i] = max(include,exclude);
        }
        //shifting
        // next = curr;
        
    }
    return next[capacity];
}
int main()
{
    /*
    int n = 3;
    int k = 3;
        vector<int>dp(n+1,-1); // if i access nth index then size should be n+1; coz in nth array the size is n-1;
        // int ans = solverUsingMem(n,k,dp);
        // int ans = solveTab(n,k);
        int ans = spaceopti(n,k);

        // int ans = solveUsingRec(n,k);
        cout<<"Ans: "<<ans;
     */
    int capacity = 6;
    int wt[] = {1, 2, 3};
    int profit[] = {10, 15, 40};
    int index = 0;
    int n = 3;

    vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));

    // int ans = solveUsingRecNap(capacity, wt, profit, index, n);
    // int ans = NapSackMem(capacity, wt, profit, index, n, dp);
    int ans = NapsackTabuSO2(capacity, wt, profit,n);
    

    cout << "max profit: " << ans << endl;

    return 0;
}