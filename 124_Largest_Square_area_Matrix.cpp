#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    // Recursive approach
    int solve(vector<vector<int>> &mat, int i, int j, int &maxn)
    {
        if (i >= mat.size() || j >= mat[0].size())
            return 0;

        int right = solve(mat, i, j + 1, maxn);
        int diagonal = solve(mat, i + 1, j + 1, maxn);
        int bottom = solve(mat, i + 1, j, maxn);
        if (mat[i][j] == 1)
        {
            int ans = 1 + min(right, min(bottom, diagonal));
            maxn = max(maxn, ans);
        }
        else
            return 0;
    }

    // Recursive+Memoization
    // TC=>O(m*n)
    // SC=>O(m*n)
    int solveMem(vector<vector<int>> &mat, int i, int j, int &maxn, vector<vector<int>> &dp)
    {
        if (i >= mat.size() || j >= mat[0].size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solveMem(mat, i, j + 1, maxn, dp);
        int diagonal = solveMem(mat, i + 1, j + 1, maxn, dp);
        int bottom = solveMem(mat, i + 1, j, maxn, dp);
        if (mat[i][j] == 1)
        {
            dp[i][j] = 1 + min(right, min(bottom, diagonal));
            maxn = max(maxn, dp[i][j]);
            return dp[i][j];
        }
        else
            return dp[i][j] = 0;
    }

    // Tabulation method
    int solveTab(vector<vector<int>> &mat,int&maxans)
    {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> dp(r+1, vector<int>(c+1, 0));
        for (int i = r - 1; i >= 0; i--)
        {
            for (int j = c - 1; j >= 0; j--)
            {
                int right =dp[i][j + 1];
                int diagonal = dp[i+1][j+1];
                int bottom = dp[i+1][j];
                if (mat[i][j] == 1)
                {
                    dp[i][j] = 1 + min(right, min(bottom, diagonal));
                    maxans = max(maxans, dp[i][j]);
                   
                }
                else 
                   dp[i][j] = 0;
            }
        }
        return 1;
    }

    // Space Optimisation O(m)
    int solveSpace(vector<vector<int>> &mat,int&maxans)
    {
        int r = mat.size();
        int c = mat[0].size();
        vector<int>curr(c+1,0);
        vector<int>next(c+1,0);
        for (int i = r - 1; i >= 0; i--)
        {
            for (int j = c - 1; j >= 0; j--)
            {
                int right =curr[j + 1];
                int diagonal = next[j+1];
                int bottom = next[j];
                if (mat[i][j] == 1)
                {
                    curr[j] = 1 + min(right, min(bottom, diagonal));
                    maxans = max(maxans, curr[j]);
                   
                }
                else 
                  curr[j] = 0;
            }
            next=curr;
        }
        return 1;
    }

    
    

    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        // Recursive approach
                //    int maxans=0;
                //    int ans=solve(mat,0,0,maxans);
                //    return maxans;

        // Memoization (top down approach)
                // int maxn=0;
                // vector<vector<int>>dp(n,vector<int>(m,-1));
                // int ans=solveMem(mat,0,0,maxn,dp);
                // return maxn;

        // Tabulation (bottom up approach)
                // int maxans=0;
                // int a=solveTab(mat,maxans);
                // return maxans;

        //Space Optimisation
                // int maxans=0;
                // int a=solveSpace(mat,maxans);
                // return maxans;
        
 
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat = {{1, 1},
                               {1, 1}};
    cout << s.maxSquare(2, 2, mat);
}
