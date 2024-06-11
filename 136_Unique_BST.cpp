#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:

    // TC=>O(N^2)
    int solveRecursion(int n)
    {
        if(n<=1)return 1;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=solveRecursion(i-1) * solveRecursion(n-i);
        }
        return ans;
    }

    // Memoization
    // TC=>O(N^2)
    // sc=>O(N)
    int solveMemo(int n,vector<int>&dp)
    {
        if(n<=1)return 1;
        if(dp[n]!=-1)return dp[n];
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=solveMemo(i-1,dp) * solveMemo(n-i,dp);
        }
        dp[n]=ans;
        return dp[n];
    }

    // Tabulation
       // TC=>O(N^2)
    // sc=>O(N)
    int solveTab(int n)
    {
        vector<int>dp(n+1,0);
        dp[0]=dp[1]=1;

        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
       
        
    }


    int numTrees(int n)
    {
        // int ans=solveRecursion(n);
        // return ans;

        // top down dp
        // vector<int>dp(n+1,-1);
        // int ans=solveMemo(n,dp);
        // return ans;

        // Bottom up approach
        return solveTab(n);
    }
};

int main()
{
    int n=4;
    Solution s;
    cout<<s.numTrees(n);
    return 0;
}