#include<iostream>
#include<vector>
#include<stack>

using namespace std;


class Solution {
    public:
      
      vector<int> nextLargerElement(vector<int>& arr) {
        stack<int>s;
        vector<int>ans(arr.size(),-1);
        for(int i=0;i<arr.size();i++)
        {
            while(!s.empty() && arr[s.top()]<arr[i])
            {
                ans[s.top()]=arr[i];
                s.pop();
            }
            s.push(i);
        }
            return ans;  
      }
      
  };
  

int main()
{
    vector<int>arr={1,3,2,4};
    Solution s;
    vector<int>ans=s.nextLargerElement(arr);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}