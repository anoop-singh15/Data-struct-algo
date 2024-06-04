#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;

class Solution
{
public:
    // Recursive approach
    int solve(int index, int diff, vector<int> &nums)
    {
        if (index < 0)
            return 0;
        int ans = 0;
        for (int i = index - 1; i >= 0; i--)
        {
            if ((nums[index] - nums[i]) == diff)
            {
                ans = max(ans, 1 + solve(i, diff, nums));
            }
        }
        return ans;
    }

    // Top down dp or recursion + memoization
     // Tc=>O(N^2)
    // Sc=>O(N^2)
    int solveMemo(int index, int diff, vector<int> &nums,unordered_map<int,int>dp[])
    {
        if (index < 0)
            return 0;
        if(dp[index].count(diff))return dp[index][diff];    
        int ans = 0;
        for (int i = index - 1; i >= 0; i--)
        {
            if ((nums[index] - nums[i]) == diff)
            {
               ans= max(ans, 1 + solveMemo(i, diff, nums,dp));
            }
        }
        dp[index][diff]=ans;
        return dp[index][diff];
    }

    // Tc=>O(N^2)
    // Sc=>O(N^2)

    int solveTab(vector<int>&nums)
    {
        int ans=0;
        unordered_map<int,int>dp[nums.size()+1];
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=nums[i]-nums[j];
                int count=1;
                if(dp[j].count(diff))
                {
                    count=dp[j][diff];
                }
                dp[i][diff]=1+count;
                ans=max(ans,dp[i][diff]);

            }
        }
        return ans;
    }

    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return n;
        int ans = 0;


        // Recursive approach

            // for(int i=0;i<n;i++)
            // {
            //     for(int j=i+1;j<n;j++)
            //     {
            //         ans=max(ans,2+solve(i,nums[j]-nums[i],nums));
            //     }
            // }

        // Memoization approach
            //    unordered_map<int,int> dp[n + 1];
            //     for (int i = 0; i < n; i++)
            //     {
            //         for (int j = i + 1; j < n; j++)
            //         {
            //             ans = max(ans, 2 + solveMemo(i, nums[j] - nums[i], nums,dp));
            //         }
            //     }


        // Bottom up approach
        ans=solveTab(nums);

        return ans;
    }
};

int main()
{
    vector<int> nums = {9, 4, 7, 2, 10};
    Solution s;
    cout << s.longestArithSeqLength(nums);
    return 0;
}