#include<iostream>
#include<vector>



using namespace std;


// int solve(vector<int>&num,int tar,int ind)
// {
//     if(tar<0) return 0;
//     if(tar==0)return 1;
//     if(ind==num.size())return 0;
//     int incl=solve(num,tar-num[ind],ind+1);
//     int excl=solve(num,tar,ind+1);
//     int ans=incl+excl;
//     return ans;
// }


// Recursion solution
int solve(vector<int>&num,int tar)
{
    if(tar<0) return 0;
    if(tar==0) return 1;
  int ans=0;
    for(int i=0;i<num.size();i++)
   {
       ans+=solve(num,tar-num[i]);
   }
   return ans;
}

// Recursion + Memoization
// TC==> O(target)

int solveMemo(vector<int>&num,int tar,vector<int>&dp)
{
    if(tar<0) return 0;
    if(tar==0) return 1;
    if(dp[tar]!=-1)return dp[tar];
 int ans=0;
    for(int i=0;i<num.size();i++)
   {
       ans+=solveMemo(num,tar-num[i],dp);
   }
   dp[tar]=ans;
   return dp[tar];
}


// Tabulation
// TC==> O(n*m)

int solveTab(vector<int>&num,int tar)
{
    vector<int>dp(tar+1,0);
    dp[0]=1;
    for(int i=1;i<=tar;i++)
   {
     for(int j=0;j<num.size();j++)
    {
        if(i-num[j]>=0)
        dp[i]+=dp[i-num[j]];
    }

      
   }
   return dp[tar];
}





int findWays(vector<int> &num, int tar)
{
//    Recursion
    //   int ans=solve(num,tar);


    // Recursion +Memo
    // vector<int>dp(tar+1,-1);
    // int ans=solveMemo(num,tar,dp)


    // Tabulation Method
    int ans=solveTab(num,tar);

   return ans;
}




int main()
{
    vector<int>arr={1,2,5};
    int tar=5;
    cout<<findWays(arr,tar);
    return 0;
}