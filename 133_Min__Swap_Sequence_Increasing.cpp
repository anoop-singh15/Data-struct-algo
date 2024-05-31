#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution
{
public:
    // Recursive code
    int solveRecursion(vector<int> &nums1, vector<int> &nums2, int index, bool swapped)
    {

        if (index == nums1.size())
            return 0;

        int ans = INT_MAX;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if (swapped)
        {
            swap(prev1, prev2);
        }

        // no swap
        if (nums1[index] > prev1 && nums2[index] > prev2)
            ans = solveRecursion(nums1, nums2, index + 1, 0);

        //  swap
        if (nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solveRecursion(nums1, nums2, index + 1, 1));

        return ans;
    }

    // Recursive + memoization code
    int solveMemo(vector<int> &nums1, vector<int> &nums2, int index, bool swapped, vector<vector<int>> &dp)
    {

        if (index == nums1.size())
            return 0;
        if (dp[index][swapped] != -1)
            return dp[index][swapped];

        int ans = INT_MAX;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if (swapped)
        {
            swap(prev1, prev2);
        }

        // no swap
        if (nums1[index] > prev1 && nums2[index] > prev2)
            ans = solveMemo(nums1, nums2, index + 1, 0, dp);

        //  swap
        if (nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solveMemo(nums1, nums2, index + 1, 1, dp));

        dp[index][swapped] = ans;
        return dp[index][swapped];
    }

    // Tabulation
    // TC=O(N)
    // SC=O(N)
    int solveTab(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, 0));
        for (int index = nums1.size() - 1; index >= 1; index--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                if (index == nums1.size())
                    return 0;

                int ans = INT_MAX;
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                if (swapped)
                {
                    swap(prev1, prev2);
                }

                // no swap
                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = dp[index + 1][0];

                //  swap
                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + dp[index + 1][1]);

                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }


    // Space Optimisation
    // Tc=O(N)
    // SC=O(1)
    int solveSpace(vector<int> &nums1, vector<int> &nums2)
    {

        int swapval=0;
        int noswap=0;
        int currswap=0;
        int curr_noswap=0;

        for (int index = nums1.size() - 1; index >= 1; index--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                if (index == nums1.size())
                    return 0;

                int ans = INT_MAX;
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                if (swapped)
                {
                    swap(prev1, prev2);
                }

                // no swap
                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = noswap;

                //  swap
                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + swapval);

              if(swapped) currswap=ans;
              else  curr_noswap=ans;

            }
            swapval=currswap;
            noswap=curr_noswap;
        }
        return min(swapval,noswap);
    }

    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        bool swaped = 0;
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // Recursive solution

        //  int ans=solveRecursion(nums1,nums2,1,swaped);
        //  return ans;

        // Memoization
        // vector<vector<int>>dp(nums1.size(),vector<int>(2,-1));
        // int ans=solveMemo(nums1,nums2,1,swaped,dp);
        //  return ans;

        // Bottom up approach
        // int ans = solveTab(nums1, nums2);
        // return ans;

        // Space optimisation
        int ans = solveSpace(nums1, nums2);
        return ans;
    }
};

int main()
{
    vector<int> n1 = {1, 3, 5, 4};
    vector<int> n2 = {1, 2, 3, 7};
    Solution s;
    cout << s.minSwap(n1, n2);
    return 0;
}