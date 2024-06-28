#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int solveRecursion(int index, int opNo, int k, vector<int> &prices)
    {
        if (index == prices.size())
            return 0;

        if (opNo == 2 * k)
            return 0;

        int profit = 0;
        if (opNo % 2 == 0)
        {
            int by = -prices[index] + solveRecursion(index + 1, opNo + 1, k, prices);
            int skip = 0 + solveRecursion(index + 1, opNo, k, prices);
            profit = max((by), (skip));
        }
        else
        {
            int sell = +prices[index] + solveRecursion(index + 1, opNo + 1, k, prices);
            int skip = 0 + solveRecursion(index + 1, opNo, k, prices);
            profit = max((sell), (skip));
        }
        return profit;
    }

    // Memoization
    // TC=>O(N*K)
    // SC=>O(N*K)
    int solveMemo(int index, int opNo, int k, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index == prices.size())
            return 0;

        if (opNo == 2 * k)
            return 0;

        if (dp[index][opNo] != -1)
            return dp[index][opNo];
        int profit = 0;
        if (opNo % 2 == 0)
        {
            int by = -prices[index] + solveMemo(index + 1, opNo + 1, k, prices, dp);
            int skip = 0 + solveMemo(index + 1, opNo, k, prices, dp);
            profit = max((by), (skip));
        }
        else
        {
            int sell = +prices[index] + solveMemo(index + 1, opNo + 1, k, prices, dp);
            int skip = 0 + solveMemo(index + 1, opNo, k, prices, dp);
            profit = max((sell), (skip));
        }
        return dp[index][opNo] = profit;
    }


    // Bottom up dp
     // TC=>O(N*K)
    // SC=>O(N*K)
    int solveTab(int k, vector<int> &prices)
    {

        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2 * k+1, 0));
        
        for (int index = n - 1; index >= 0; index--)
        {
            for (int opNo = 0; opNo < 2 * k; opNo++)
            {
                
                 
                    int profit = 0;
                    if (opNo % 2 == 0)
                    {
                        int by = -prices[index] + dp[index + 1][ opNo + 1];
                        int skip = 0 + dp[index + 1][ opNo];
                        profit = max((by), (skip));
                    }
                    else
                    {
                        int sell = +prices[index] + dp[index + 1][ opNo + 1];
                        int skip = 0 + dp[index + 1][ opNo];
                        profit = max((sell), (skip));
                    }
                dp[index][opNo]=profit;
            }
        }
        return dp[0][0];
    }

     // TC=>O(N*K)
    // SC=>O(K)
    int solveSpace(int k,vector<int>&prices)
    {
          int n = prices.size();
      vector<int>curr(2*k+1,0);
      vector<int>next(2*k+1,0);
        
        for (int index = n - 1; index >= 0; index--)
        {
            for (int opNo = 0; opNo < 2 * k; opNo++)
            {
                
                 
                    int profit = 0;
                    if (opNo % 2 == 0)
                    {
                        int by = -prices[index] + next[ opNo + 1];
                        int skip = 0 + next[ opNo];
                        profit = max((by), (skip));
                    }
                    else
                    {
                        int sell = +prices[index] + next[ opNo + 1];
                        int skip = 0 + next[ opNo];
                        profit = max((sell), (skip));
                    }
                curr[opNo]=profit;
            }
            next=curr;
        }
        return next[0];
    }


    int maxProfit(int k, vector<int> &prices)
    {
        // return solveRecursion(0,0,k,prices);

        // Top down dp
        // vector<vector<int>>dp(prices.size(),vector<int>(2*k,-1));
        // return solveMemo(0,0,k,prices,dp);

        // Tabulation
        // return solveTab(k, prices);

        // Space Optimisation
        return solveSpace(k,prices);
    }
};

int main()
{

    vector<int> p = {3, 3, 5, 0, 0, 3, 1, 4};
    Solution s;
    int k = 2;
    cout << s.maxProfit(k, p);
    return 0;
}