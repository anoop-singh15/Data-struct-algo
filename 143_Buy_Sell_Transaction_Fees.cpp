 #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 
 class Solution
{
public:
  
 
    // Space OPtimisation
     // TC=O(N)
    // SC=O(1)
    int solveSpace(vector<int>&prices,int fees)
    {
        int n = prices.size();
      vector<int>curr(2,0);
      vector<int>next(2,0);
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    int by = -prices[index] + next[ 0];
                    int skip = 0 + next[ 1];
                    profit = max((by), (skip));
                }
                else
                {
                    int sell = prices[index] + next[1]-fees;
                    int skip = 0 + next[ 0];
                    profit = max((sell), (skip));
                }
                curr[buy]=profit;
            }
               next=curr;
        }
        return next[1];
    }

    // function calling
    int maxProfit(vector<int> &prices,int fee)
    {

      
        return solveSpace(prices,fee);
    }
};

int main()
{

    vector<int> p = {1,3,2,8,4,9};
    Solution s;
    cout << s.maxProfit(p,2);
    return 0;
}