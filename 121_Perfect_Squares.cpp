#include<iostream>
#include<vector>
#include<limits.h>

 using namespace std;

// recursive solution
 int solveRecursion(int n)
 {

    if(n==0) return 0;
    int ans=n;
    for(int i=01;i*i<=n;i++)
    {
        ans=min(ans,1+solveRecursion(n-(i*i)));
    }
    return ans;

 }

// Memoization
 int solveMemo(int n,vector<int>&dp)
 {
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int ans=n;
    for(int i=1;i*i<=n;i++)
    {
        ans=min(ans,1+solveMemo(n-(i*i),dp));
    }
    dp[n]=ans;
    return dp[n];
 }
// Bottom up Approach
 int  solveTab(int n)
 {
    vector<int>dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i=1; i<=n;i++)
    {
        for(int j=1;j*j<=n;j++)
        {
            if(i-(j*j)>=0)
            dp[i]=min(dp[i],1+dp[i-(j*j)]);
        }
        
    }
    return dp[n];
 }




 int main()
 {
    int n=12;
    // cout<<solveRecursion(n);

    // Memoization solution
    // vector<int>dp(n+1,-1);
    // cout<<solveMemo(n,dp);
    
    // Tabulation method
    // cout<<solveTab(n);

    // Space Optimisation
    // NOT POSSIBLE in this case
    return 0;
 }