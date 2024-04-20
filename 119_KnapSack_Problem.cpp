#include <iostream>
#include <vector>

using namespace std;

// Recursion approach
int solveRecursion(vector<int> &weight, vector<int> &value, int index, int maxWeight)
{
    if (index == 0)
    {
        if (weight[0] <= maxWeight)

            return value[0];

        return 0;
    }
    int include = 0;
    if (weight[index] <= maxWeight)
        include = value[index] + solveRecursion(weight, value, index, maxWeight - weight[index]);

    int exclude = 0 + solveRecursion(weight, value, index - 1, maxWeight);
    int ans = max(include, exclude);
    return ans;
}

// Recursion + memoization approach
// TC==>O(n*maxweight)
// SC=O(n*maxWeight)
int solveMemo(vector<int> &weight, vector<int> &value, int n, int maxWeight, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (weight[0] <= maxWeight)

            return value[0];

        return 0;
    }

    if (dp[n][maxWeight] != -1)
    {
        return dp[n][maxWeight];
    }

    int include = 0;
    if (weight[n] <= maxWeight)
        include = value[n] + solveMemo(weight, value, n - 1, maxWeight - weight[n], dp);

    int exclude = 0 + solveMemo(weight, value, n - 1, maxWeight, dp);
    dp[n][maxWeight] = max(include, exclude);
    return dp[n][maxWeight];
}

// Tabulation method
// n== row maxweight=column
// TC==>O(n*maxweight)

int solveTab(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        if (weight[0] <= maxWeight)
            dp[0][i] = value[0];
        else
            dp[0][i] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <=maxWeight; j++)
        {
            int include = 0;
            if (weight[i] <= j)
                include = value[i] + dp[ i - 1][ j - weight[i]];

            int exclude = 0 + dp[ i- 1][ j];
            dp[i][j] = max(include, exclude);
        }
    }
    return dp[n-1][maxWeight];
}

// Space Optimisation
// SC==> O(2*maxWeight)
int solveSpace(vector<int>&weight,vector<int>&value,int n,int maxWeight)
{
    vector<int>prev(maxWeight+1,0);
    vector<int>curr(maxWeight+1,0);     
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        if (weight[0] <= maxWeight)
            prev[i] = value[0];
        else
            prev[i] = 0;
    }
     for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <=maxWeight; j++)
        {
            int include = 0;
            if (weight[i] <= j)
                include = value[i] + prev[ j - weight[i]];

            int exclude = 0 + prev[j];
           curr[j] = max(include, exclude);
        }
        prev=curr;
    }
    return prev[maxWeight]; 
}

// space is more optimised
// SC==>O(maxWeight)
int solveSpaceBetter(vector<int>&weight,vector<int>&value,int n,int maxWeight)
{
   
     vector<int>curr(maxWeight+1,0);     
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        if (weight[0] <= maxWeight)
            curr[i] = value[0];
        else
            curr[i] = 0;
    }
     for (int i = 1; i < n; i++)
    {
        for (int j = maxWeight; j >=0; j--)
        {
            int include = 0;
            if (weight[i] <= j)
                include = value[i] +curr[ j - weight[i]];

            int exclude = 0 + curr[j];
           curr[j] = max(include, exclude);
        }
       
    }
    return curr[maxWeight]; 


}

int main()
{
    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    int maxWeight = 5;
    int n = weight.size();

    // Using recursion approach
    // cout<<solveRecursion(weight,value,n-1,maxWeight);

    // using memoization approach
    // create dp array in this case create 2d array
    // vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
    // cout<<solveMemo(weight,value,n-1,maxWeight,dp);

    // Tabulation approach
    // cout << solveTab(weight, value, n, maxWeight);

    // Space optimisation

    // cout<<solveSpace( weight,value,n,maxWeight);

    // Better space optimisation
    cout<<solveSpaceBetter( weight,value,n,maxWeight);



    return 0;
}