#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    public:
        static bool sortcol(const vector<int> &v1, const vector<int> &v2)
        {
            return v1[0] < v2[0];
        }

        bool check(vector<int>base ,vector<int>newBox)
        {
            if(newBox[0]<=base[0] && newBox[1]<=base[1] && newBox[2]<=base[2])
            return true;
            return false;
        }

        int LIS_BottomUp(vector<vector<int>>&cuboids)
        {
            int n=cuboids.size();
            vector<int>curr(n+1,0);
            vector<int>next(n+1,0);
            for(int index=n-1;index>=0;index--)
            {
                for(int prev=index-1;prev>=-1;prev--)
                {
                    int include=0;
                    if(prev==-1 || check(cuboids[index],cuboids[prev]))
                    {
                        include=cuboids[index][2]+next[index+1];
                    }
                    int exclude=0+next[prev+1];
                    curr[prev+1]=max(include,exclude);
                }
                next=curr;

            }
            return next[0];
        }


        int maxHeight(vector<vector<int>> &cuboids)
        {
            // step -1
            for (int i = 0; i < cuboids.size(); i++)
            {
                sort(cuboids[i].begin(), cuboids[i].end());
            }
            
            // step-2
            sort(cuboids.begin(), cuboids.end());
            
            // Longest increasing Subsequence Bottom up approach logic
            return  LIS_BottomUp(cuboids);


            
        }
};

int main()
{
    vector<vector<int>>v={{50,45,20},{95,37,53},{45,23,12}};
    Solution s;
    cout<<s.maxHeight(v);
}