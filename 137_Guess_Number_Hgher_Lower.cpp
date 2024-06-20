#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution
{
public:
    // Recursive solution
    int solveRecursion(int s, int e)
    {
        if (s >= e)
            return 0;
        int ans = INT_MAX;
        for (int i = s; i <= e; i++)
        {
            ans = min(ans, i + max(solveRecursion(s, i - 1), solveRecursion(i + 1, e)));
        }
        return ans;
    }

    // Top down dp solution

     // TC=>O(N^2)
    // SC=O(N^2)
    int sovleMemo(int s, int e, vector<vector<int>> &dp)
    {
        if (s >= e)
            return 0;
        if (dp[s][e] != -1)
            return dp[s][e];
        int ans = INT_MAX;
        for (int i = s; i <= e; i++)
        {
            ans = min(ans, i + max(sovleMemo(s, i - 1, dp), sovleMemo(i + 1, e, dp)));
        }
        dp[s][e] = ans;
        return dp[s][e];
    }

    // Bottom up dp

    // TC=>O(N^2)
    // SC=O(N^2)
    int solveTab(int n)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int strt = n; strt >= 1; strt--)
        {
            for (int end = strt; end <= n; end++)
            {
                if (strt == end)
                    continue;
                else
                {
                    int ans = INT_MAX;
                    for (int i = strt; i <= end; i++)
                    {
                        ans = min(ans, i + max(dp[strt][ i - 1], dp[i + 1][ end]));
                    }
                  dp[strt][end]=ans;
                }
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n)
    {
        // Recursive solution
        // int ans=solveRecursion(1,n);
        // return ans;

        // Memoization solution
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // int ans=sovleMemo(1,n,dp);
        // return ans;

        // Tabulation
        return solveTab(n);
    }
};

int main()
{
    int n = 10;
    Solution s;
    cout << s.getMoneyAmount(n);
    return 0;
}
