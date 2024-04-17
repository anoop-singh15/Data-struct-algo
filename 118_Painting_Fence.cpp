#include<iostream>
#include<vector>

#define M 1000000007

using namespace std;

int add(int a,int b)
{
    return ((a%M) + (b%M))%M;
}

int mul(int a,int b)
{
    return (a%M *1LL* b%M)%M;
}
// TC=exponential
int solveRecursion(int n,int k)
{
    if(n==1)
        return k;
    if(n==2)
        return add(k,mul(k,k-1));
        int ans=add(  mul(solveRecursion(n-1,k),k-1)  ,mul(solveRecursion(n-2,k),k-1));
        return ans;
}

// Recursion + Memoization
// TC==O(N)
// SC==O(N)
int solveMemo(int n,int k, vector<int>&dp)
{
    if(n==1) return k;
    if(n==2) return add(k,mul(k,k-1));
    if(dp[n]!=-1) return dp[n];
    dp[n]=add(  mul(solveMemo(n-1,k,dp),k-1)  ,mul(solveMemo(n-2,k,dp),k-1));
    return dp[n];
}

// Bottom up approach
// TC==O(N)
// SC==O(N)
int tabulation(int n ,int k)
{
    vector<int>dp(n+1,0);
    dp[1]=k;
    dp[2]=add(k,mul(k,k-1));
    for(int i=3;i<=n;i++)
    {
        dp[i]=add(   mul(dp[i-1],k-1)  ,   mul(dp[i-2],k-1));
    }
    return dp[n];
}

// TC==O(N)
// SC==O(1)
int solveSpace(int n,int k)
{
    int prev1=k;
    int prev2=add(k,mul(k,k-1));
    for(int i=3;i<=n;i++)
    {
        int ans=add(   mul(prev2,k-1)  ,   mul(prev1,k-1));
        prev1=prev2;
        prev2=ans;
    }
    return prev2;
}

int main()
{
    int n=3,k=3;
    // Recursion approach
    // cout<<solveRecursion(n,k);

    // Recursion + Memoization
    // vector<int>dp(n+1,-1);
    // cout<<solveMemo(n,k,dp);


    // Tabulation method
    // cout<<tabulation(n,k);

    // space optimised
    cout<<solveSpace(n,k);



    return 0;
}