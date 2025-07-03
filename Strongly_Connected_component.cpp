#include<iostream>
#include<vector>
#include<stack>


using namespace std;
// Kosaraju's Algorithm

class Solution {
  public:
  
    void Dfs(int u,vector<vector<int>>&adj,vector<bool>&vis,stack<int>&s)
    {
        vis[u]=true;
        for(auto v:adj[u])
        {
            if(!vis[v])
            {
                Dfs(v,adj,vis,s);
            }
        }
        s.push(u);
    }
    
    void dfs2(vector<int>adjR[],int node ,vector<bool>&vis)
    {
         vis[node]=true;
        for(auto v:adjR[node])
        {
            if(!vis[v])
            {
                dfs2(adjR,v,vis);
            }
        }
    }  
  
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int V=adj.size();
        
        // step 1 store dfs in sorted finishing time
        vector<bool>visited(V,false);
        stack<int>s;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                Dfs(i,adj,visited,s);
            }
        }
        
        // step 2
        vector<int>adjR[V];
        for(int i=0;i<adj.size();i++)
        {
            visited[i]=0;
            for(auto j:adj[i])
            {
                adjR[j].push_back(i);
            }
        }
        int scc=0;
        while(!s.empty())
        {
            int node=s.top();
            s.pop();
            if(!visited[node])
            {
                scc++;
                dfs2(adjR,node,visited);
            }
        }
        
        return scc;
        
        
    }
};


int main()
{
    return 0;
}

