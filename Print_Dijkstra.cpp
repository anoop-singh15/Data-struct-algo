#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
#include<limits.h>

using namespace std;

// TC=O(E*logV)
// SC=O(E+V)

typedef pair<int,int> P;

vector<int>shortestPath(int n,int m,vector<vector<int>>&edges)
{
    vector<int>parent(n+1);
    for(int i=0;i<=n;i++)
    {
        parent[i]=i;
    }
    vector<int>result(n+1,INT_MAX);

    // pair<int,int> {node,weight}
    vector<vector<P>>adj(n+1,vector<P>());

    for(int i=0;i<m;i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];
        int w=edges[i][2];
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    // pair<int,int> dist,node
    priority_queue<P,vector<P>,greater<P>>pq;
    result[1]=0;
    pq.push({0,1});
    while(!pq.empty())
    {
        int node=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        for(auto i:adj[node])
        {
            int adjNode=i.first;
            int weight=i.second;
            if(weight+d<result[adjNode])
            {
                parent[adjNode]=node;
                result[adjNode]=d+weight;
                pq.push({d+weight,adjNode});
            }
        }
    }

    if(result[n]==INT_MAX)return {-1};  

    vector<int>ans;
    int node=n;
    while(parent[node]!=node)
    {
        ans.push_back(node);
        node=parent[node];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    return ans;
}


int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>>edges(e,vector<int>(3));
    for(int i=0;i<e;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        edges[i][0]=x;
        edges[i][1]=y;
        edges[i][2]=z;

    }

    vector<int>ans=shortestPath(v,e,edges);

    for(auto i:ans)
    {
        cout<<i<<" ";
    }




    return 0;
}