#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Rcursive approach
    int solveRecursion(int N, int index, int arr[], int target)
    {
        if (index >= N)
            return 0;
        if (target < 0)
            return 0;
        if (target == 0)
            return 1;

        int include = solveRecursion(N, index + 1, arr, target - arr[index]);
        int exclude = solveRecursion(N, index + 1, arr, target);

        return include | exclude;
    }

    // Top down dp
    int solveMemo(int N, int index, int arr[], int target, vector<vector<int>> &dp)
    {
        if (index >= N)
            return 0;
        if (target < 0)
            return 0;
        if (target == 0)
            return 1;
        if (dp[index][target] != -1)
            return dp[index][target];

        int include = solveMemo(N, index + 1, arr, target - arr[index], dp);
        int exclude = solveMemo(N, index + 1, arr, target, dp);
        dp[index][target] = include | exclude;
        return dp[index][target];
    }

    // Tabulation
    // TC=O(sum * N)
    int solveTab(int N, int arr[], int total)
    {
        vector<vector<int>> dp(N + 1, vector<int>(total + 1, 0));
        for (int i = 0; i <= N; i++)
        {
            dp[i][0] = 1;
        }

        for (int index = N - 1; index >= 0; index--)
        {
            for (int target = 0; target <= (total/2 ); target++)
            {   
                bool include=0;
                if((target-arr[index])>=0)
                 include = dp[index + 1][target - arr[index]];


                bool exclude = dp[index + 1][target-0];
                dp[index][target] = include or exclude;
            }
        }
        return dp[0][total/2];
    }

    // Space optimisation
    // TC=O(sum * N)
    // SC=> O(sum of elements)
    int solveSpace(int N, int arr[], int total)
    {
        // vector<vector<int>> dp(N + 1, vector<int>(total + 1, 0));
        vector<int>curr(total+1,0);
        vector<int>next(total+1,0);
        curr[0]=1;
        next[0]=1;
       
        for (int index = N - 1; index >= 0; index--)
        {
            for (int target = 0; target <= (total/2 ); target++)
            {   
                bool include=0;
                if((target-arr[index])>=0)
                 include = next[target - arr[index]];


                bool exclude = next[target-0];
                curr[target] = include or exclude;
            }
            next=curr;
        }
        return curr[total/2];
    }

    int equalPartition(int N, int arr[])
    {

        int total = 0;
        for (int i = 0; i < N; i++)
        {
            total += arr[i];
        }
        if (total & 1)
            return 0;

        // Recursion approach
        // int ans = solveRecursion(N,0, arr, total / 2);

        // Memoization approach
        // vector<vector<int>>dp(N+1,vector<int>(total+1,-1));
        // int ans=solveMemo(N,0,arr,total/2,dp);

        // Bottom up approach
        // bool ans = solveTab(N, arr, total);

        // Space Optimisation
        bool ans = solveSpace(N, arr, total);
        return ans;
    }
};

int main()
{
    int arr[] = {2, 4 ,11, 10, 5};
    Solution s;
    cout << s.equalPartition(5, arr);
}