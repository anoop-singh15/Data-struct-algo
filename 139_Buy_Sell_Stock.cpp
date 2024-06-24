#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0],profit=0;
        for(int i=1;i<prices.size();i++)
        {
            int diff=prices[i]-mini;
            profit=max(profit,diff);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};

int main()
{

    vector<int>p={7,1,5,3,6,4};
    Solution s;
    cout<<s.maxProfit(p);
    return 0;
}