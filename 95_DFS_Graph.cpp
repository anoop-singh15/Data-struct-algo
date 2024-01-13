#include<unordered_map>
#include<list>
#include<set>
#include<vector>
#include<iostream>

using namespace std;


// TC =O(n)
// SC =O(n)


void dfs(int node,unordered_map<int,list<int>>&adj, unordered_map<int,bool>&v, vector<int>&comp)
{
    comp.push_back(node);
    v[node]=1;
    for(auto i:adj[node])
    {
        if(!v[i])
        {
            dfs(i,adj,v,comp);
        }
    }
    
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);

    }
    vector<vector<int>>ans;
    unordered_map<int,bool>v;
    for(int i=0;i<V;i++)
    {
        vector<int>comp;
        if(!v[i])
        {
            dfs(i,adj,v,comp);
            ans.push_back(comp);
        }
    }
    return ans;
}

int main()
{

}