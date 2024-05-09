#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution
{
public:
    // Recursive Approach
    int solveRecursion(vector<int> &obstacles, int currlane, int pos)
    {
        int n = obstacles.size() - 1;
        if (pos == n)
            return 0;
        if (obstacles[pos + 1] != currlane)
        {
            return solveRecursion(obstacles, currlane, pos + 1);
        }
        else
        {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (currlane != i && obstacles[pos] != i)
                    ans = min(ans, 1 + solveRecursion(obstacles, i, pos));
            }
            return ans;
        }
    }

    // Top down
    // TC =>O(3*N)
    int solveMemo(vector<int> &obstacles, int currlane, int pos, vector<vector<int>> &dp)
    {
        int n = obstacles.size() - 1;
        if (pos == n)
            return 0;

        if (dp[currlane][pos] != -1)
            return dp[currlane][pos];

        if (obstacles[pos + 1] != currlane)
        {
            return solveMemo(obstacles, currlane, pos + 1, dp);
        }
        else
        {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (currlane != i && obstacles[pos] != i)
                    ans = min(ans, 1 + solveMemo(obstacles, i, pos, dp));
            }
            dp[currlane][pos] = ans;
            return dp[currlane][pos];
        }
    }

    // Bottom up approach
    // TC =>O(3*N)
    int solveTab(vector<int> &obstacles)
    {
        int n = obstacles.size() - 1;
        vector<vector<int>> dp(4, vector<int>(n + 1, 1e9));
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;
        for (int pos = n-1; pos >= 0; pos--)
        {
            for (int lane = 1; lane <= 3; lane++)
            {
                if (obstacles[pos + 1] != lane)
                {
                    dp[lane][ pos ]=dp[lane][pos+1];
                }
                else
                {
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (lane != i && obstacles[pos] != i)
                            ans = min(ans, 1 + dp[i][pos+1]);
                    }
                    dp[lane][pos]= ans;
                }
            }
        }
        // +1 for side ways jump
        return min(dp[2][0],min(dp[1][0]+1,dp[3][0]+1));
    }


    // Bottom up approach
    // SC=++> O(1)
    // TC =>O(3*N)
    int solveSpace(vector<int> &obstacles)
    {
       int n=obstacles.size()-1;
        vector<int>curr(4,1e9);
        vector<int>next(4,0);
       
        for (int pos = n-1; pos >= 0; pos--)
        {
            for (int lane = 1; lane <= 3; lane++)
            {
                if (obstacles[pos + 1] != lane)
                {
                    curr[lane]=next[lane];
                }
                else
                {
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (lane != i && obstacles[pos] != i)
                            ans = min(ans, 1 + next[i]);
                    }
                  curr[lane]= ans;
                }
            }
            next=curr;
        }
        // +1 for side ways jump
        return min(next[2],min(next[1]+1,next[3]+1));
    }

    int minSideJumps(vector<int> &obstacles)
    {
        // Recursion
                 // return solveRecursion(obstacles, 2, 0);

        // Recursion + Memoization
                // vector<vector<int>>dp(4,vector<int>(obstacles.size(),-1));
                // return solveMemo(obstacles,2,0,dp);

        // Tabulation
                //  return solveTab(obstacles);
        // Space optimisation
                 return solveSpace(obstacles);
    }
};

int main()
{
    vector<int> obstacle = {0, 2, 1, 0, 3, 0};
    Solution s;
    cout << s.minSideJumps(obstacle);
    return 0;
}