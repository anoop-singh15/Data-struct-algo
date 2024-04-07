#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

// Recursion method
int solveRecursion(vector<int>&coins,int target)
{
    if(target==0) return 0;
    if(target<0) return INT_MAX;
    int mini=INT_MAX;
    for(int i=0;i<coins.size();i++)
    {
        int ans=solveRecursion(coins,target-coins[i]);
        if(ans!=INT_MAX) mini=min(mini,1+ans);
    }
    return mini;
}


// Recursion + Memoization
// TC==> O(target+N)
// SC==>O(target)
int solveRecursionMemo(vector<int>&coins,int target,vector<int>&dp)
{
      if(target==0) return 0;
        if(target<0) return INT_MAX;
         if(dp[target]!=-1)
         return dp[target];
         int mini=INT_MAX ;
          for(int i=0;i<coins.size();i++)
        {
            int ans=solveRecursionMemo(coins,target-coins[i],dp);
            if(ans!=INT_MAX) mini=min(mini,1+ans);
        }
        dp[target]=mini;

    return mini;
    
}

// Bottom up approach
// Tc==>O(X * N)
// SC==>O(N)
int solveTabulation(vector<int>&num,int x)
{
    vector<int>dp(x+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<num.size();j++)
        {
            if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX)
            {

            dp[i]=min(dp[i],i+dp[1-num[j]]);
            }
        }
    }
    if(dp[x]==INT_MAX)
    return -1;
    return dp[x];
}



int main()
{
    vector<int>coin={1,2,5};
    int target=25;

    // Recursion method
    // int ans=solveRecursion(coin,target);
    // if(ans==INT_MAX)cout<<-1;
    // cout<<ans<<endl;

    // Recursion + Memoization
    // vector<int>dp(target+1,-1);
    // int ans=solveRecursionMemo(coin,target,dp);
    // if(ans==INT_MAX)cout<<-1;
    // else 
    // cout<<ans;


    // Tabulation method
    int ans=solveTabulation(coin,target);
    cout<<ans;


    // space optimisation
    // NOT Possible since we take O(target space)


    return 0;
}