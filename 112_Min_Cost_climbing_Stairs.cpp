#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

#define M 1000000007 


// // You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.


// Recursion code
int solveR(vector<int>&cost,int n)
{
    if(n==0) return cost[0];
    if(n==1) return cost[1];
    int ans=cost[n]+min(solveR(cost,n-1),solveR(cost,n-2));
    return ans;
}
// TC=O(N)
// SC=O(N) ==> O(n)+O(n)
int solveRM(vector<int>&cost,int n,vector<int>&dp)
{
    if(n==0) return cost[0];
    if(n==1) return cost[1];
    if(dp[n]!=-1)
    return dp[n];
    dp[n]=cost[n]+min(solveRM(cost,n-1,dp),solveRM(cost,n-2,dp));
    return dp[n];
}


// Bottom up approach
// TC=O(N)
// SC=O(N)
int solveBottom(vector<int>&cost,vector<int>&dp,int n)
{
    dp[0]=cost[0];
    dp[1]=cost[1];
    for(int i=2;i<cost.size();i++)
    {
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}


// Space optimised
// TC=O(N)
// SC=O(1)
int solveSpace(int n,vector<int>&cost)
{
    int prev1=cost[0],prev2=cost[1],curr;
    for(int i=2;i<n;i++)
    {
        curr=cost[i]+min(prev2,prev1);
        prev1=prev2;
        prev2=curr;
    }
    return min(prev1,prev2);
    
}


int main()
{
    vector<int>cost={10,15,20};
    int n=cost.size();
    // WITHOUT MEMOIZATION
    // int ans=min(solveR(cost,n-1),solveR(cost,n-2));

    // Recursion with memoization
    // vector<int>dp(n+1,-1);
    // int ans=min(solveRM(cost,n-1,dp),solveRM(cost,n-2,dp));

    // Bottom up approach
    // vector<int>dp(n+1);
    // int ans=solveBottom(cost,dp,n);


    // space optimised solution
    int ans=solveSpace(n,cost);
    cout<<ans<<endl;
    return 0;
}