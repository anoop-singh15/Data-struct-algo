#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &satis, int index, int time)
    {
        if (index == satis.size())
            return 0;

        int incl = satis[index] * (time + 1) + solve(satis, index + 1, time + 1);
        int excl = 0 + solve(satis, index + 1, time);

        return max(incl, excl);
    }
    // Top down approach
    int solveMemo(vector<int> &satis, int index, int time, vector<vector<int>> &dp)
    {
        if (index == satis.size())
            return 0;
        if (dp[index][time] != -1)
            return dp[index][time];

        int incl = satis[index] * (time + 1) + solveMemo(satis, index + 1, time + 1, dp);
        int excl = 0 + solveMemo(satis, index + 1, time, dp);

        dp[index][time] = max(incl, excl);
        return dp[index][time];
    }
    
    // TC=>O(N^2)
    // SC=>O(N^2)
// Bottom up approach
    int solveTab(vector<int> &satis)
    {
        int n = satis.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int index= n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 0; time--)
            {

                int incl = satis[index] * (time + 1) +dp[index + 1][ time + 1];
                int excl = 0 + dp[index + 1][ time ];

                dp[index][time] = max(incl, excl);
                
            }
        }
        return dp[0][0];
    }

    // SC==>O(N)
    int solveSpace(vector<int>&satis)
    {
       int n = satis.size();
        
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);

        for (int index= n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 0; time--)
            {

                int incl = satis[index] * (time + 1) +next[ time + 1];
                int excl = 0 +next[ time ];

                curr[time] = max(incl, excl);
                
            }
            next=curr;
        }
        return curr[0];;
    }

    // tc=>O(N)
    // SC=>O(n)
    // greedy approach
    int solveGreedy(vector<int>&satis)
    {
       sort(satis.begin(),satis.end());
       int n=satis.size();
       int ans=0,sum=0;
       for(int i=n-1;i>=0;i--)
       {
           sum+=satis[i];
           if(sum<0)break;
            ans+=sum;
       }
       return ans;
    }

    int maxSatisfaction(vector<int> &satis)
    {
        sort(satis.begin(), satis.end());
        // Recursion
            // int ans=solve(satis,0,0);
            // return ans;

        // Recursion + Memoization
            // vector<vector<int>>dp(satis.size()+1,vector<int>(satis.size()+1,-1));
            // int ans=solveMemo(satis,0,0,dp);
            // return ans;

        // tabulation
            // int ans = solveTab(satis);
            // return ans;

        // Space Optimisation
            // int ans=solveSpace(satis); 
            // return ans;

        //  Greedy approach
            int ans=solveGreedy(satis);
            return ans;
    }
};

int main()
{
    vector<int> v = {-1, -8, 0, 5, -9};
    Solution s;
    cout << s.maxSatisfaction(v);
}