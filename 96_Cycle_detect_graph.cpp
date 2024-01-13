// BFS
#include<unordered_map>
#include<list>
#include<queue>
#include<iostream>
using namespace std;


// LINEAR TIME COMPLEXITY


bool bfs(int node,unordered_map<int,list<int>>&adj,unordered_map<int ,bool>&v
)
{
    unordered_map<int ,int>parent;
    parent[node]=-1;
     v[node]=true;
  
    queue<int>q;
    q.push(node);
   
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        for(auto i:adj[f])
        {
            if(v[i]==true && i!=parent[f])
            {
                
                return true;
            }
             if(!v[i])
            {
                q.push(i);
                v[i]=true;
                parent[i]=f;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,list<int>>adj;
    for(int i=0;i<m;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
                adj[edges[i][1]].push_back(edges[i][0]);

    }
    unordered_map<int ,bool>v;
    
   string ans="NO";
    for(int i=1;i<=n;i++)
    {
        if(!v[i])
        {
            bool ans=bfs(i,adj,v);
            if(ans)
            return "Yes";
        }
    }
    return "No";


}


// dfs
bool dfs(int node,int parent,unordered_map<int,list<int>>&adj, unordered_map<int ,bool>&v)
{
    v[node]=1;
    for(auto i:adj[node])
    {
        if(!v[i])
        {
            bool cycle=dfs(i,node,adj,v);
            if(cycle)
            {
                return true;
            }
           
        }
         else if(i!=parent)
         {
             return true;
         }
       
    }
    return false;
}



int main()
{
    return 0;
}
