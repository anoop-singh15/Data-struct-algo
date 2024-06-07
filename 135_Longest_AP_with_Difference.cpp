#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits.h>

using namespace std;

 int Longest_Increasing_Memo(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp)
    {
        if (curr == nums.size())
            return 0;

        if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];

        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev])
        {
            include = 1 + Longest_Increasing_Memo(nums, curr + 1, curr,dp);
        }
        int exclude = 0 + Longest_Increasing_Memo(nums, curr + 1, prev,dp);
        dp[curr][prev+1]= max(include, exclude);
        return dp[curr][prev+1];
    }


int longest_Increasing_Subsequence(vector<int>&nums)
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
        else{
            int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            ans[index]=nums[i];
        }
    }
    return ans.size();
}





class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        unordered_map<int,int>m;
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]=1+m[arr[i]-d];
            ans=max(ans,m[arr[i]]);
        }
        for(auto i:m)
        {
            cout<<i.first<<" "<<i.second<<endl;
        }
        return ans;
    }
};



int main()
{
    vector<int>v={1,2,3,4};
    int d=1;
    
    Solution s;
    cout<<s.longestSubsequence(v,d);


    // vector<int>n={7,7,7,7,7,7,7};
    // cout<<longest_Increasing_Subsequence(n);



    return 0;
}