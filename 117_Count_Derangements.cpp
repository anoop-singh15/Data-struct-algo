#include<iostream>
#include<vector>

#define M 1000000007

using namespace std;

 // Recursion
//  tC==>exponential
int countDeRecursion(int n)
{
    if(n==1) return 0;
    if(n==2) return 1;
    int ans=((n-1)%M) * ((countDeRecursion(n-1))%M + (countDeRecursion(n-2))%M);
    return ans;
}

// Recursion + Memoization
// TC=O(N)
// SC=O(N)
int countDeMemoization(int n,vector<int>&dp)
{
    if(n==1) return 0;
    if(n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    dp[n]=(((n-1)%M) * ((countDeMemoization(n-1,dp))%M + (countDeMemoization(n-2,dp))%M)%M);
    return dp[n];
}

// Bottom up approach
// TC==>O(N)
// SC==>O(N)
long long int tabulation(int n)
{
    vector<long long int>dp(n+1,0);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++)
    {
        long long  int one=dp[i-1]%M;
        long long  int two=dp[i-2]%M;
        long long  int sum=(one +two)%M;
     long long int ans=     ((i-1)    *  sum) %M;
     dp[i]=ans;
    }
    return dp[n];
}
// Space Optimised solution
// TC==>O(N)
// SC==>O(1) 
long long int solveSpace(int n)
{
   long long  int prev1=0;
   long long  int prev2=1;
    for(int i=3;i<=n;i++)
    {
        long long int sum= (prev1%M +prev2%M)%M;
        long long int ans=((i-1)*sum)%M;
        prev1=prev2;
        prev2=ans;
    }
    return prev2;
}

int main()
{
    // Recursion
    // cout<<countDeRecursion(4);

    // Recursion+Memoization
    // int n=4;
    // vector<int>dp(n+1,-1);
    // cout<<countDeMemoization(n,dp);


    // Tabulation method
    // cout<<tabulation(4);

    // SPACE OPTIMISATION
    cout<<solveSpace(4);

    return 0;
}