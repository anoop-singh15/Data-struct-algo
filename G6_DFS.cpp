#include<iostream>
#include<vector>


using namespace std;

// INPUT
// 8 8
// 1 2
// 1 3
// 3 4
// 3 7
// 4 8
// 7 8
// 2 5
// 2 6


void dfs(int node,vector<bool>&vis,vector<int>&ans,vector<vector<int>>&arr)
{
    vis[node]=1;
    ans.push_back(node);
    for(auto i:arr[node])
    {
        if(!vis[i])
        {
            dfs(i,vis,ans,arr);
        }
    }


}


int main()
{
       int n,m;
    cin>>n>>m;

    vector<vector<int>>arr(n+1);


    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);


    }

    for(int i=1;i<=n;i++)
    {
        cout<<i<<"->";
        for(int j:arr[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    vector<bool>vis(n+1,0);
    vector<int>ans;
    dfs(1,vis,ans,arr);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }



    return 0;
}

