// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    int solveRecursion(string a, string b, int i, int j)
    {

        // base case
        // if length of a is less than b than count will be length of b - j
        if (i == a.size())
            return b.size() - j;

        // if length of a is less than b than count will be length of b - j
        if (j == b.size())
            return a.size() - i;

        int ans = 0;
        if (a[i] == b[j])
        {
            return solveRecursion(a, b, i + 1, j + 1);
        }
        else
        {
            // insert
            int insertAns = 1 + solveRecursion(a, b, i, j + 1);
            // delete
            int deleteAns = 1 + solveRecursion(a, b, i + 1, j);
            // replace
            int replaceAns = 1 + solveRecursion(a, b, i + 1, j + 1);
            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return ans;
    }

    // Top down dp

    int solveMemo(string a, string b, int i, int j, vector<vector<int>> &dp)
    {

        // base case
        // if length of a is less than b than count will be length of b - j
        if (i == a.size())
            return b.size() - j;

        // if length of a is less than b than count will be length of b - j
        if (j == b.size())
            return a.size() - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if (a[i] == b[j])
        {
            return solveMemo(a, b, i + 1, j + 1, dp);
        }
        else
        {
            // insert
            int insertAns = 1 + solveMemo(a, b, i, j + 1, dp);
            // delete
            int deleteAns = 1 + solveMemo(a, b, i + 1, j, dp);
            // replace
            int replaceAns = 1 + solveMemo(a, b, i + 1, j + 1, dp);
            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return dp[i][j] = ans;
    }

    // Bottom up dp
    int solveTab(string &a, string &b)
    {
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
        for (int j = 0; j < b.length(); j++)
        {
            dp[a.size()][j] = b.size() - j;
        }
        for (int i = 0; i < a.length(); i++)
        {
            dp[i][b.size()] = a.size() - i;
        }

        for (int i = a.size() - 1; i >= 0; i--)
        {
            for (int j = b.size() - 1; j >= 0; j--)
            {
                int ans = 0;
                if (a[i] == b[j])
                {
                    ans= dp[i + 1][j + 1];
                }
                else
                {
                    // insert
                    int insertAns = 1 + dp[i][ j + 1];
                    // delete
                    int deleteAns = 1 + dp[i + 1][ j];
                    // replace
                    int replaceAns = 1 + dp[i + 1][ j + 1];
                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    // Space Optimisation
    // TC= O(N*M)
    // SC=O(min(N,M))
    int solveSpace(string &a, string &b)
    {
        // vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
        vector<int>curr(b.size()+1,0);
        vector<int>next(b.size()+1,0);


        for (int j = 0; j < b.length(); j++)
        {
            next[j] = b.size() - j;
        }
       

        for (int i = a.size() - 1; i >= 0; i--)
        {
            for (int j = b.size() - 1; j >= 0; j--)
            {
                curr[b.size()]=a.size()-i;
                int ans = 0;
                if (a[i] == b[j])
                {
                    ans= next[j + 1];
                }
                else
                {
                    // insert
                    int insertAns = 1 + curr[ j + 1];
                    // delete
                    int deleteAns = 1 + next[ j];
                    // replace
                    int replaceAns = 1 + next[ j + 1];
                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
               curr[j] = ans;
            }
            next=curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2)
    {

        // Recursive solution
        // return solveRecursion(word1,word2,0,0);

        // Memoization
        // vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        // return solveMemo(word1,word2,0,0,dp);

        // Tabulation
        // return solveTab(word1, word2);


        // solve Space
         if(word1.size()==0)return word2.size();
        if(word2.size()==0)return word1.size(); 
        return solveSpace(word1, word2);
       
    }
};

int main()
{
    string s1 = "horse";
    string s2 = "ros";

    Solution s;
    cout << s.minDistance(s1, s2);
    return 0;
}

/**
 * Pseudocode

if(char match)
{
    call function for remainig string
}
else
{
    insertAns
    deleteAns
    replaceAns
    find ans=min(insertAns,deleteAns,replaceAns)
}

 *
 *
 */
