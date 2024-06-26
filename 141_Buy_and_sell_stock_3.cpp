#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Solve Recursion
    int solveRecursion(vector<int> &price, int index, int buy, int limit)
    {
        if (index == price.size())
            return 0;

        if (limit == 0)
            return 0;

        int profit = 0;
        if (buy)
        {
            int by = -price[index] + solveRecursion(price, index + 1, 0, limit);
            int skip = 0 + solveRecursion(price, index + 1, 1, limit);
            profit = max((by), (skip));
        }
        else
        {
            int sell = +price[index] + solveRecursion(price, index + 1, 1, limit - 1);
            int skip = 0 + solveRecursion(price, index + 1, 0, limit);
            profit = max((sell), (skip));
        }
        return profit;
    }

    // Top Down approach Memoization
    // TC=O(N)
    // SC=O(N)
    int solveMemo(vector<int> &price, int index, int buy, int limit, vector<vector<vector<int>>> &dp)
    {
        if (index == price.size())
            return 0;

        if (limit == 0)
            return 0;

        if (dp[index][buy][limit] != -1)
            return dp[index][buy][limit];
        int profit = 0;
        if (buy)
        {
            int by = -price[index] + solveMemo(price, index + 1, 0, limit, dp);
            int skip = 0 + solveMemo(price, index + 1, 1, limit, dp);
            profit = max((by), (skip));
        }
        else
        {
            int sell = +price[index] + solveMemo(price, index + 1, 1, limit - 1, dp);
            int skip = 0 + solveMemo(price, index + 1, 0, limit, dp);
            profit = max((sell), (skip));
        }
        dp[index][buy][limit] = profit;
        return dp[index][buy][limit];
    }

    // Tabulation - top down approach
    // TC=O(N)
    // SC=O(N)
    int solveTab(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1  ; limit <= 2; limit++)
                {
                    int profit = 0;
                    if (buy)
                    {
                        int by = -prices[index] + dp[index + 1][0][limit];
                        int skip = 0 + dp[index + 1][1][limit];
                        profit = max((by), (skip));
                    }
                    else
                    {
                        int sell = prices[index] + dp[index + 1][1][limit-1];
                        int skip = 0 + dp[index + 1][0][limit];
                        profit = max((sell), (skip));
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }

    // Space OPtimisation
    // TC=O(N)
    // SC=O(1)
    int solveSpace(vector<int> &prices)
    {
        int n = prices.size();
      vector<vector<int>>curr(2,vector<int>(3,0));
      vector<vector<int>>next(2,vector<int>(3,0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1  ; limit <= 2; limit++)
                {
                    int profit = 0;
                    if (buy)
                    {
                        int by = -prices[index] + next[0][limit];
                        int skip = 0 + next[1][limit];
                        profit = max((by), (skip));
                    }
                    else
                    {
                        int sell = prices[index] + next[1][limit-1];
                        int skip = 0 + next[0][limit];
                        profit = max((sell), (skip));
                    }
                  curr[buy][limit] = profit;
                }
            }
            next=curr;
        }
        return next[1][2];
    }

    // function calling
    int maxProfit(vector<int> &prices)
    {

        // Recursive calling

                    // int ans=solveRecursion(prices,0,1,2);
                    // return ans;

        // Memoization

                    // int n=prices.size();
                    // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
                    // int ans=solveMemo(prices,0,1,2,dp);
                    // return ans;

        // Tabulation
                    //  return solveTab(prices);

        // space optimisation
                    return solveSpace(prices);
    }
};

int main()
{

    vector<int> p = {3, 3, 5, 0, 0, 3, 1, 4};
    Solution s;
    cout << s.maxProfit(p);
    return 0;
}