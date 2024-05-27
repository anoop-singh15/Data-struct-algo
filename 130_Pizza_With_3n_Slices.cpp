#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Recursion
    int solve(int strtind, int endind, vector<int> &slice, int n)
    {
        if (n == 0 || strtind > endind)
            return 0;
        int include = slice[strtind] + solve(strtind + 2, endind, slice, n - 1);
        int exclude = 0 + solve(strtind + 1, endind, slice, n);
        return max(include, exclude);
    }

    // Topdown
    int solveMemo(int strtind, int endind, vector<int> &slice, int n, vector<vector<int>> &dp)
    {
        if (n == 0 || strtind > endind)
            return 0;
        if (dp[strtind][n] != -1)
            return dp[strtind][n];
        int include = slice[strtind] + solveMemo(strtind + 2, endind, slice, n - 1, dp);
        int exclude = 0 + solveMemo(strtind + 1, endind, slice, n, dp);
        dp[strtind][n] = max(include, exclude);
        return dp[strtind][n];
    }

    // Tabulation
    int solveTab(vector<int> &slice)
    {
        int n = slice.size();
        vector<vector<int>> dp1(n+2, vector<int>(n+2, 0));
        vector<vector<int>> dp2(n+2, vector<int>(n+2, 0));

        for (int index = n - 2; index >= 0; index--)
        {
            for (int i = 1; i <= (n/3); i++)
            {
                int include = slice[index] + dp1[index + 2][i - 1];
                int exclude = 0 + dp1[index + 1][i];
                dp1[index][i] = max(include, exclude);
            }
        }
        int case1 = dp1[0][n / 3];

        for (int index = n - 1; index >= 1; index--)
        {
            for (int i = 1; i <=(n/3); i++)
            {
                int include = slice[index] + dp2[index + 2][i - 1];
                int exclude = 0 + dp2[index + 1][i];
                dp2[index][i] = max(include, exclude);
            }
        }
        int case2 = dp2[1][n / 3];
        return max(case1 , case2);
    }


    // Space Optimisation
    // TC==>O(N^2)
    // SC==>O(6*N)
    int solveSpace(vector<int> &slice)
    {
        int n = slice.size();
        vector<int> prev1(n+2, 0);
        vector<int> curr1(n+2, 0);
        vector<int> next1(n+2, 0);
        
        vector<int> prev2(n+2, 0);
        vector<int> curr2(n+2, 0);
        vector<int> next2(n+2, 0);
        
        for (int index = n - 2; index >= 0; index--)
        {
            for (int i = 1; i <= (n/3); i++)
            {
                int include = slice[index] + next1[i - 1];
                int exclude = 0 + curr1[i];
                prev1[i] = max(include, exclude);
            }
            next1=curr1;
            curr1=prev1;
        }
        int case1 = curr1[n / 3];

        for (int index = n - 1; index >= 1; index--)
        {
            for (int i = 1; i <=(n/3); i++)
            {
                int include = slice[index] +  next2[i - 1];
                int exclude = 0 + curr2[i];
                prev2[i] = max(include, exclude);
            }
             next2=curr2;
            curr2=prev2;
        }
        int case2 = curr2[n / 3];
        return max(case1 , case2);
    }

    int maxSizeSlices(vector<int> &slices)
    {
        // Recursion
        // int n = slices.size();
        // int left = solve(0, n - 2, slices, n / 3);
        // int right = solve(1, n - 1, slices, n / 3);
        // return max(left, right);

        // Memoization
        //  int n = slices.size();
        // vector<vector<int>>dp1(n,vector<int>(n,-1));
        // vector<vector<int>>dp2(n,vector<int>(n,-1));
        // int left = solveMemo(0, n - 2, slices, n / 3,dp1);
        // int right = solveMemo(1, n - 1, slices, n / 3,dp2);
        // return max(left, right);

        // Tabulation
        
        // return  solveTab(slices);


        // Space optimisation
        return solveSpace(slices);
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    Solution s;
    cout << s.maxSizeSlices(v);
    return 0;
}