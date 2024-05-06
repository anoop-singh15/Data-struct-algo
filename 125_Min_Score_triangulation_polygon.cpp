#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    // Recursion
    int solveRecursion(vector<int> &values, int i, int j)
    {
        if (i + 1 == j)
            return 0;

        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            int mul = values[i] * values[j] * values[k];
            ans = min(ans, mul + solveRecursion(values, i, k) + solveRecursion(values, k, j));
        }
        return ans;
    }
    // Recursion + Memoization
    // TC==>O(N^3)
    // SC==>O(N^2)
    int solveMem(vector<int> &values, int i, int j, vector<vector<int>> &dp)
    {
        if (i + 1 == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            int mul = values[i] * values[j] * values[k];
            ans = min(ans, mul + solveMem(values, i, k, dp) + solveMem(values, k, j, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    // Tabulation Method
    // TC==>O(N^3)
    // SC==>O(N^2)
    int solveTab(vector<int> &values)
    {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            {
                int ans = INT_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    int mul = values[i] * values[j] * values[k];
                    ans = min(ans, mul + dp[i][k] + dp[ k][ j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }

    int minScoreTriangulation(vector<int> &values)
    {
        // Recursive apporoach
             // return solveRecursion(values,0,values.size()-1);

        // Top down  apporoach
            // vector<vector<int>> dp(values.size(), vector<int>(values.size(), -1));
            // return solveMem(values, 0, values.size() - 1, dp);

        // Bottom up approach
        return solveTab(values);
    }
};

int main()
{
    Solution s;
    vector<int> value = {1, 3, 1, 4, 1, 5};
    cout << s.minScoreTriangulation(value);
    return 0;
}