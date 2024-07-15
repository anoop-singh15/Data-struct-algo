#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    int solveRecursion(string a ,string b,int i,int j)
    {
        if(i==a.size())return 0;
        if(j==b.size())return 0;

        int ans=0;
        if(a[i]==b[j])
        {
            ans=1+solveRecursion(a,b,i+1,j+1);
        }
        else
        {
            ans=max(solveRecursion(a,b,i+1,j),solveRecursion(a,b,i,j+1));
        }
        return ans;
    }

    int solveMemo(string a ,string b,int i,int j,vector<vector<int>>&dp)
    {
        if(i==a.length())return 0;
        if(j==b.length())return 0;


        if(dp[i][j]!=-1)return dp[i][j];

        int ans=0;

        if(a[i]==b[j])
        {
            ans=1+solveMemo(a,b,i+1,j+1,dp);
        }
        else
        {
            ans=max(solveMemo(a,b,i+1,j,dp),solveMemo(a,b,i,j+1,dp));
        }

        return dp[i][j]=ans;
    }


        // Space Optimisation
    // TC=>O(N*M)
    // SC=>O(M)
    int solveSpace(string a, string b)
    {
        vector<int>curr(b.size()+1,0);
        vector<int>next(b.size()+1,0);
        for (int i = a.size() - 1; i >= 0; i--)
        {
            for (int j = b.size() - 1; j >= 0; j--)
            {
                int ans = 0;
             
                if (a[i] == b[j])
                {
                    ans = 1 +next[ j + 1];
                }
                else
                {
                    ans = max(next[ j], curr[ j + 1]);
                }
               curr[j]=ans;
            }
            next=curr;
        }
        return curr[0];
    }


    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
       
        // int ans=solveRecursion(s,s2,0,0);
        // vector<vector<int>>dp(s.size()+1,vector<int>(s2.size()+1,-1));
        // int ans=solveMemo(s,s2,0,0,dp);
       v
    }
};


int main()
{
    string str="bbbab";
    Solution s;
    cout<<s.longestPalindromeSubseq(str);
    return 0;

}