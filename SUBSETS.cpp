#include<iostream>
#include<vector>

using namespace std;

class Solution{

    public:

    void solve(vector<vector<int>>&ans,vector<int>&nums,vector<int>temp,int i)
    {
        if(i==nums.size())
        {
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[i]);
        solve(ans,nums,temp,i+1);
        temp.pop_back();
        solve(ans,nums,temp,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>ans;
       vector<int>temp;
       solve(ans,nums,temp,0);
       return ans;
    }
};

int main()
{
    Solution s;
    vector<int>v={1,2,3};
    vector<vector<int>>ans=s.subsets(v);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}