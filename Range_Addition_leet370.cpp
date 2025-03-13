#include<iostream>
#include<vector>

using namespace std;


// LEETCODE 370 Premium question

// Time complexity O(N)
// Space complexity O(1)


// LOGIC

/* 
    arr[l]+=x;
    arr[r+1]-=x;
    x+1<n
*/


vector<int>RangeAddition(int n,vector<vector<int>>&queries)
{
    vector<int>ans(n,0);
    
    for(int i=0;i<queries.size();i++)
    {
        int l=queries[i][0];
        int r=queries[i][1];
        int val=queries[i][2];
        ans[l]+=val;
        if(r+1<n)
        ans[r+1]-=val;

    }
    for(int i=1;i<n;i++)
    {
        ans[i]+=ans[i-1];
    }
    return ans;
}


int main()
{
    int n;
    cin>>n;

    // [L(i),R(i),VALUE(i)]
    // vector<vector<int>>queries={{1,3,2},{2,4,3},{0,2,-2}};
    vector<vector<int>>queries={{0,2,100},{1,5,100},{2,3,100}};
    vector<int>ans=RangeAddition(n,queries);

    for(auto i:ans)
    {
        cout<<i<<" ";
    }


    return 0;
}