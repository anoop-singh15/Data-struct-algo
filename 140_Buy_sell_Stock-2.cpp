#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Solve Recursion
    int solveRecursion(vector<int> &price, int index, int buy)
    {
        if (index == price.size())
            return 0;
        int profit = 0;
        if (buy)
        {
            int by = -price[index] + solveRecursion(price, index + 1, 0);
            int skip = 0 + solveRecursion(price, index + 1, 1);
            profit = max((by), (skip));
        }
        else
        {
            int sell = +price[index] + solveRecursion(price, index + 1, 1);
            int skip = 0 + solveRecursion(price, index + 1, 0);
            profit = max((sell), (skip));
        }
        return profit;
    }

    // Top Down approach Memoization
    // TC=O(N)
    // SC=O(N)
    int solveMemo(vector<int> &price, int index, int buy, vector<vector<int>> &dp)
    {
        if (index == price.size())
            return 0;
        if (dp[index][buy] != -1)
            return dp[index][buy];
        int profit = 0;
        if (buy)
        {
            int by = -price[index] + solveMemo(price, index + 1, 0, dp);
            int skip = 0 + solveMemo(price, index + 1, 1, dp);
            profit = max((by), (skip));
        }
        else
        {
            int sell = +price[index] + solveMemo(price, index + 1, 1, dp);
            int skip = 0 + solveMemo(price, index + 1, 0, dp);
            profit = max((sell), (skip));
        }
        dp[index][buy] = profit;
        return dp[index][buy];
    }

    
    // Tabulation - top down approach
    // TC=O(N)
    // SC=O(N)
    int solveTab(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    int by = -prices[index] + dp[ index + 1][ 0];
                    int skip = 0 + dp[index + 1][ 1];
                    profit = max((by), (skip));
                }
                else
                {
                    int sell = prices[index] + dp[index + 1][1];
                    int skip = 0 + dp[ index + 1][ 0];
                    profit = max((sell), (skip));
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }

    // Space OPtimisation
     // TC=O(N)
    // SC=O(1)
    int solveSpace(vector<int>&prices)
    {
        int n = prices.size();
      vector<int>curr(2,0);
      vector<int>next(2,0);
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    int by = -prices[index] + next[ 0];
                    int skip = 0 + next[ 1];
                    profit = max((by), (skip));
                }
                else
                {
                    int sell = prices[index] + next[1];
                    int skip = 0 + next[ 0];
                    profit = max((sell), (skip));
                }
                curr[buy]=profit;
            }
               next=curr;
        }
        return next[1];
    }

    // function calling
    int maxProfit(vector<int> &prices)
    {

        // Recursive calling

            // int ans=solveRecursion(prices,0,1);
            // return ans;

        // Memoization

            // int n=prices.size();
            // vector<vector<int>>dp(n+1,vector<int>(2,-1));
            // int ans=solveMemo(prices,0,1,dp);
            // return ans;

        // Tabulation
            // return solveTab(prices);

        // space optimisation 
        return solveSpace(prices);
    }
};

int main()
{

    vector<int> p = {7, 1, 5, 3, 6, 4};
    Solution s;
    cout << s.maxProfit(p);
    return 0;
}