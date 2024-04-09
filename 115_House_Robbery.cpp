#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

// TC => O(N)
// SC => O(N)


// Based on max sum of non adjacent element
long long int solve(vector<int>& value) {
    int n=value.size();
  long long int prev1=0;
    long long int prev2=value[0];
    for(int i=1;i<n;i++)
    {
        long long int incl=prev1+value[i];
        long long int excl=prev2;
        long long int ans=max(incl,excl);
        prev1=prev2;
        prev2=ans;
    }
    return prev2;

}

long long int houseRobber(vector<int>& value) {
   int n=value.size();
   if(n==1)return value[0];
   vector<int>first,second;
   for(int i=0;i<n;i++)
   {
       if(i!=n-1)
       {
           first.push_back(value[i]);
       }
       if(i!=0)
       {
           second.push_back(value[i]);
       }
   }
   long long int ans=max(solve(first),solve(second));
   return ans;
}

int main()
{
  
   
    return 0;
}