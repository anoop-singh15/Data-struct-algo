#include<iostream>
#include<vector>


using namespace std;


int solveRecursion(vector<int>&nums,int n)
{
    if(n<0) return 0;
    if(n==0) return nums[0];
    int incl=solveRecursion(nums,n-2)+nums[n];
    int excl=solveRecursion(nums,n-1)+ 0;

    return max(incl,excl);
   

}

// Recursion + Memoization
// TC=O(N)
// SC=O(N)+O(N)
int solveMemo(vector<int>&nums,int n,vector<int>&dp)
{
    if(n<0) return 0;
    if(n==0) return nums[0];
    if(dp[n]!=-1)
    return dp[n];
    int incl=solveMemo(nums,n-2,dp)+nums[n];
    int excl=solveMemo(nums,n-1,dp) + 0;
    dp[n]=max(incl,excl);
    return dp[n];
}

// Tabulation Method bottom up
// TC=O(N)
// SC=O(N)
int solveTabulation(vector<int>&nums)
{
    int n=nums.size();
   vector<int>dp(n,0);
   dp[0]=nums[0];
    for(int i=1;i<n;i++)
    {
          int incl=dp[i-2]+nums[i];
            int excl=dp[i-1] + 0;
            dp[i]=max(incl,excl);
    }
  
   
    return dp[n-1];
}


int SolveSpace(vector<int>&nums)
{
    int n=nums.size();
    int prev1=0,prev2=nums[0];
     for(int i=1;i<n;i++)
    {
          int incl=prev1+nums[i];
            int excl=prev2 + 0;
           int ans=max(incl,excl);
           prev1=prev2;
           prev2=ans;
    }
    return prev2;

}

int main()
{
    vector<int>nums={1,2,4};
    int n=nums.size();
    // int n=nums.size();
    // int ans=solveRecursion(nums,n-1);

    // Recursion + Memo
    // vector<int>dp(n,-1);
    // int ans=solveMemo(nums,n-1,dp);
    // cout<<ans;

    // Tabulation method
    // int ans=solveTabulation(nums);
    // cout<<ans;

    // Space Optimisation
    cout<<SolveSpace(nums);


    return 0;
}