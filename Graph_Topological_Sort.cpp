#include<iostream>
#include<vector>
#include<stack>
using namespace std;


// Directed Acyclic graph input




//INPUT
// 6 8
// 0 3
// 0 2
// 2 1
// 2 3
// 3 1
// 1 4
// 5 1
// 5 4
// 4


// for weighted use vector<pair<int,int>>arr[n+1]
//  <node,weight>



void dfs(int u,stack<int>&s,vector<bool>&visit,vector<int>adj[])
{
    visit[u]=1;
    for(auto v:adj[u])
    {
        if(!visit[v])
        {
            visit[v]=1;
            dfs(v,s,visit,adj);
            // s.push(v);
        }

    }
    
    s.push(u);
}



void topological_Sort(vector<int>arr[],int V)
{
    stack<int>s;
    vector<bool>visited(V,0);
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            //  visited[i]=1;
            dfs(i,s,visited,arr);

        }

    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}




int main()
{
    int n,m;
    cin>>n>>m;

    vector<int>arr[n+1];


    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
      


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

    topological_Sort(arr,n);

    return 0;
}