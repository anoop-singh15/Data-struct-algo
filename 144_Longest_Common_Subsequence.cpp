#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int solveRecursion(string a, string b, int i, int j)
    {
        if (i == a.length())
            return 0;
        if (j == b.length())
            return 0;
        int ans = 0;
        if (a[i] == b[j])
        {
            ans = 1 + solveRecursion(a, b, i + 1, j + 1);
        }
        else
        {
            ans = max(solveRecursion(a, b, i + 1, j), solveRecursion(a, b, i, j + 1));
        }
        return ans;
    }

    // top Down dp
    // TC=>O(N*M)
    // SC=>O(N*M)
    int solveMemo(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {
        if (i == a.length())
            return 0;
        if (j == b.length())
            return 0;
        int ans = 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (a[i] == b[j])
        {
            ans = 1 + solveMemo(a, b, i + 1, j + 1, dp);
        }
        else
        {
            ans = max(solveMemo(a, b, i + 1, j, dp), solveMemo(a, b, i, j + 1, dp));
        }
        return dp[i][j] = ans;
    }

    // Bottom up dp
    // TC=>O(N*M)
    // SC=>O(N*M)

    int solveTab(string &a, string &b)
    {
        vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));
        for (int i = a.size() - 1; i >= 0; i--)
        {
            for (int j = b.size() - 1; j >= 0; j--)
            {
                int ans = 0;
             
                if (a[i] == b[j])
                {
                    ans = 1 + dp[i + 1][ j + 1];
                }
                else
                {
                    ans = max(dp[i + 1][ j], dp[i][ j + 1]);
                }
               dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }

    // top Down dp
    // TC=>O(N*M)
    // SC=>O(M)
    int solveSpace(string &a, string &b)
    {
        vector<int>curr(b.size()+1,0);
        vector<int>next(b.size()+1,0);
        for (int i = a.size() - 1; i >= 0; i--)
        {
            for (int j = b.size() - 1; j >= 0; j--)
            {
                int ans = 0;
             
                if (a[i] == b[j])
                {
                    ans = 1 +next[ j + 1];
                }
                else
                {
                    ans = max(next[ j], curr[ j + 1]);
                }
               curr[j]=ans;
            }
            next=curr;
        }
        return curr[0];
    }

    int longestCommonSubsequence(string &text1, string &text2)
    {
        // return solveRecursion(text1,text2,0,0);

        // Memoization
        // vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        // return solveMemo(text1,text2,0,0,dp);

        // Tabulation
        // return solveTab(text1, text2);

        // Space Optimisation
        return solveSpace(text1,text2);
    }
};

int main()
{
    string text1 = "abc", text2 = "abc";
    Solution s;

    cout << s.longestCommonSubsequence(text1, text2);
    return 0;
}