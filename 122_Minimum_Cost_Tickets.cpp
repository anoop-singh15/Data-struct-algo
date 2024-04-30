#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// Recursion solution
int solve(int n, vector<int> &days, vector<int> &cost, int index)
{
    if (index >= n)
        return 0;
    int a = cost[0] + solve(n, days, cost, index + 1);

    int i;
    for (i = index; i < n && days[i] < (days[index] + 7); i++)
        ;
    int b = cost[1] + solve(n, days, cost, i);

    for (i = index; i < n && days[i] < (days[index] + 30); i++)
        ;
    int c = cost[2] + solve(n, days, cost, i);

    int ans = min(a, min(b, c));
    return ans;
}

// Recursion +Memoization
int solveMemo(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
{
    if (index >= n)
        return 0;
    if (dp[index] != -1)
        return dp[index];

    int a = cost[0] + solveMemo(n, days, cost, index + 1, dp);

    int i;
    for (i = index; i < n && days[i] < (days[index] + 7); i++)
        ;

    int b = cost[1] + solveMemo(n, days, cost, i, dp);

    for (i = index; i < n && days[i] < (days[index] + 30); i++)
        ;

    int c = cost[2] + solveMemo(n, days, cost, i, dp);

    dp[index] = min(a, min(b, c));
    return dp[index];
}

// Tabulation methiod
int solveTab(int n, vector<int> &days, vector<int> &cost)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    for (int j= n - 1; j >= 0; j--)
    {
        int a = cost[0] + dp[j + 1];

        int i;
        for (i = j; i < n && days[i] < (days[j] + 7); i++)
            ;

        int b = cost[1] + dp[i];

        for (i = j; i < n && days[i] < (days[j] + 30); i++)
            ;

        int c = cost[2] +dp[i];

        dp[j] = min(a, min(b, c));
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    //Recursion 


    // int ans = solve(n, days, cost, 0);
    // return ans;

    // Recursion + Memoization

    // vector<int> dp(n + 1, -1);
    // int ans = solveMemo(n, days, cost, 0, dp);
    // return ans;

    // Tabulation
    return solveTab(n,days,cost);
}

int main()
{
    vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    vector<int> cost = {2, 7, 15};

    cout << minimumCoins(days.size(), days, cost);
    return 0;
}