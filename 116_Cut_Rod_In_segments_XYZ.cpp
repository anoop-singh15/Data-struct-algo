#include<iostream>
#include<vector>
#include<limits.h>


using namespace std;

int solveRecursion(int n,int x,int y,int z)
{
    // Base Case
    if(n==0) return 0;
    if(n<0) return INT_MIN;
    int a=solveRecursion(n-x,x,y,z)+1;
    int b=solveRecursion(n-y,x,y,z)+1;
    int c=solveRecursion(n-z,x,y,z)+1;
    int ans=max(a,max(b,c));
    return ans;
}

// TC==> O(N)
// SC==>O(N)
int solveMemo(int n,int x,int y,int z,vector<int>&dp)
{
    if(n==0)
    {
        return 0;
    }
    if(n<0) return INT_MIN;
    if(dp[n]!=-1) return dp[n];
    int a=solveMemo(n-x,x,y,z,dp)+1;
    int b=solveMemo(n-y,x,y,z,dp)+1;
    int c=solveMemo(n-z,x,y,z,dp)+1;
    dp[n]=max(a,max(b,c));
    return dp[n];
}

// TC==> O(N)
// SC==>O(N)
int solveTab(int n,int x,int y,int z)
{
    vector<int>dp(n+1,INT_MIN);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(i-x>=0 && dp[i-x]!=-1)
        dp[i]=max(dp[i],dp[i-x]+1);
       
       
        if(i-y>=0 && dp[i-y]!=-1)
        dp[i]=max(dp[i],dp[i-y]+1);
        
        
        if(i-z>=0 && dp[i-z]!=-1)
        dp[i]=max(dp[i],dp[i-z]+1);
    }
    return dp[n];
}

int main()
{
    // Recursive Code
    // if(ans<0) return 0;
    // cout<<solveRecursion(7,5,2,2);


    // Memoization code
    // int n=7;
    // vector<int>dp(n+1,-1);
    // cout<<solveMemo(n,5,2,2,dp);

    // Tabulation method
    int ans=solveTab(7,5,2,2);
    if(ans<0) cout<<0;
    else cout<<ans;

    // Space optimisation not possible


    return 0;
}