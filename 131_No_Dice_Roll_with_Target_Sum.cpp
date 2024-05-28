#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
    long long solveRecursion(int dice, int face, int target)
    {
        if (target < 0)
            return 0;
        if (dice == 0 && target != 0)
            return 0;
        if (dice != 0 && target == 0)
            return 0;
        if (target == 0 && dice == 0)
            return 1;

        long long ans = 0;
        for (int i = 1; i <= face; i++)
        {
            ans += solveRecursion(dice - 1, face, target - i);
        }
        return ans;
    }

    // Memoization
     // TC=>O(N*M*X)
    // SC=>O(N*X)
    long long solveMemo(int dice, int face, int target, vector<vector<long long>> &dp)
    {
        if (target < 0)
            return 0;
        if (dice == 0 && target != 0)
            return 0;
        if (dice != 0 && target == 0)
            return 0;
        if (target == 0 && dice == 0)
            return 1;

        if (dp[dice][target] != -1)
            return dp[dice][target];

        long long ans = 0;
        for (int i = 1; i <= face; i++)
        {
            ans += solveMemo(dice - 1, face, target - i, dp);
        }
        dp[dice][target] = ans;
        return dp[dice][target];
    }

    // Bottom up approach
    // TC=>O(N*M*X)
    // SC=>O(N*X)
    long long solveTab(int d, int f, int t)
    {
        vector<vector<long long>> dp(d + 1, vector<long long>(t + 1, 0));
        dp[0][0] = 1;
        for (int dice = 1; dice <= d; dice++)
        {
            for (int target = 1; target <= t; target++)
            {
                long long ans = 0;
                for (int i = 1; i <= f; i++)
                {
                    if(target-i>=0)
                    ans += dp[dice - 1][target - i];
                }
                dp[dice][target] = ans;
                
            }
        }
        return dp[d][t];
    }

    // Space Optimisation approach
    // TC=>O(N*M*X)
    // 
    long long solveSpace(int d, int f, int t)
    {
       vector<long long>prev(t+1,0);
       vector<long long>curr(t+1,0);
        prev[0]=1;
        for (int dice = 1; dice <= d; dice++)
        {
            for (int target = 1; target <= t; target++)
            {
                long long ans = 0;
                for (int i = 1; i <= f; i++)
                {
                    if(target-i>=0)
                    ans += prev[target - i];
                }
               curr[target] = ans;
                
            }
            prev=curr;
        }
        return prev[t];
    }

    long long noOfWays(int M, int N, int X)
    {
        // Recursive approach
        // long long ans=solveRecursion(N,M,X);
        // return ans;

        // Memoization top down dp
        // vector<vector<long long>>dp(N+1,vector<long long>(X+1,-1));
        // long long ans=solveMemo(N,M,X,dp);
        // return ans;

        // Tabulation Method
        // return solveTab(N, M, X);

        // Space Optimisation
        return solveSpace(N,M,X);
    }
};

int main()
{
    int m = 6, n = 3, x = 12;
    Solution s;
    cout << s.noOfWays(m, n, x);
    return 0;
}