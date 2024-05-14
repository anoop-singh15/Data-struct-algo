#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// Leetocode Russian Doll Envelopes question
class Russian_Doll_Envelopes {
public:
// comparator for sorting based on descending order of second element
static bool comp(pair<int,int> &a,pair<int,int>&b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        else{
            return a.first<b.first;
        }
    }

    int maxEnvelopes(vector<vector<int>>& env) {
        vector<pair<int,int>>v;
        for(int i=0;i<env.size();i++)
        {
            v.push_back({env[i][0],env[i][1]});
        }
        sort(v.begin(),v.end(),comp);
       vector<int>h;
       for(auto i:v)
       {
        h.push_back(i.second);
       }
        // now longest increasing subsequence 
        vector<int>ans;
        ans.push_back(h[0]);
        for(int i=0;i<h.size();i++)
        {
            if(h[i]>ans.back())
            {
                ans.push_back(h[i]);
            }
            else
            {
                int index=lower_bound(ans.begin(),ans.end(),h[i])-ans.begin();
                ans[index]=h[i];
            }
        }

        return ans.size();
    }
};






class Solution
{
public:
    int solveRecursion(vector<int> &nums, int curr, int prev)
    {

        if (curr == nums.size())
            return 0;
        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev])
        {
            include = 1 + solveRecursion(nums, curr + 1, curr);
        }
        int exclude = 0 + solveRecursion(nums, curr + 1, prev);
        int ans = max(include, exclude);
        return ans;
    }

    // Memoization
    // TC==> O(N^2)
    // SC==> O(N^2)

    int solveMemo(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp)
    {
        if (curr == nums.size())
            return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev])
        {
            include = 1 + solveMemo(nums, curr + 1, curr, dp);
        }
        int exclude = 0 + solveMemo(nums, curr + 1, prev, dp);
        dp[curr][prev + 1] = max(include, exclude);
        return dp[curr][prev + 1];
    }

    // Tabulation method
    // TC==> O(N^2)
    // SC==> O(N^2)

    int solveTab(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || nums[curr] > nums[prev])
                {
                    include = 1 + dp[curr + 1][curr + 1];
                }
                int exclude = 0 + dp[curr + 1][prev + 1];
                dp[curr][prev + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    // Space optimisation
    // TC==> O(N^2)
    // SC==> O(N)

    int solveSpace(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> currR(n + 1, 0);
        vector<int> nextR(n + 1, 0);
        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || nums[curr] > nums[prev])
                {
                    include = 1 + nextR[curr + 1];
                }
                int exclude = 0 + nextR[prev + 1];
                currR[prev + 1] = max(include, exclude);
            }
            nextR = currR;
        }
        return nextR[0];
    }

     // optimise solution
    // TC==> O(NlogN)
    // SC==> O(N)
    int solveOptimal(vector<int>&nums)
    {
        int n=nums.size();
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=0;i<n;i++)
        {
            if(nums[i]>ans.back())
            {
                 ans.push_back(nums[i]);
            }
            else
            {
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int> &nums)
    {

        int n = nums.size();
            // int ans = solveRecursion(nums, 0, -1);
            // return ans;

        // Memoization top down dp
            // vector<vector<int>>dp(n,vector<int>(n+1,-1));
            // int ans=solveMemo(nums,0,-1,dp);
            // return ans;

        // bottom up approach
            // int ans = solveTab(nums);
            // return ans;

        // Space optimisation
            // int ans = solveSpace(nums);
            // return ans;

        // optimal solution
            int ans=solveOptimal(nums);
            return ans;
    }
};

int main()
{
    vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution s;
    cout << s.lengthOfLIS(v);
    return 0;
}