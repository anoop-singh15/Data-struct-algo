#include<iostream>
#include<vector>

using namespace std;

// Recursion + MEMOIZATION ===> Top-Down Approach 1st Method
// TC=SC= O(N)
int fib(int n,vector<int>&dp)
{
    
    if(n==1 || n==0)
    return n;
    if(dp[n]!=-1)
    return dp[n];
    dp[n]=fib(n-1,dp)+fib(n-2,dp);
    return dp[n];
}



// fib using method 2 BOTTOM-UP APPROACH (Tabulation)
// TC=SC= O(N)
int fib_bottomUp(int n,vector<int>&dp)
{
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}


// Last Space Optimised Logic
// TC=O(N)
// sc=O(1)
int fib_space(int n)
{
    int prev1=0,prev2=1,curr;
    for(int i=2;i<=n;i++)
    {
        curr=prev1+prev2;
        prev1=prev2;
        prev2=curr;
    }
    return prev1;
}

int main()
{
    // int n=65;
    // vector<int>dp(n+1);
    // for(int i=0;i<=n;i++)
    // {
    //     dp[i]=-1;
    // }

    // method 1 function calling
    // cout<<fib(n,dp);


    // method 2 function calling
    // cout<<fib_bottomUp(n,dp);


    // Method 3 for space optimisation
    // sometimes handle case for n=0
    cout<<fib_space(2);

    return 0;
}