#include <bits/stdc++.h> 
#include<iostream>
#include<list>
#include<unordered_map>

#include<utility>

using namespace std;

// TC->O(N+E)
// SC->O(N)

void dfsSort(int node,unordered_map<int,list<int>>&adj,vector<bool> &visit,stack<int>&s)
{
  visit[node]=1;
 
  for(auto i:adj[node])
  {
    if(!visit[i])
    {
       dfsSort(i,adj,visit,s);
      
    }
    
    
  }
  s.push(node);
 
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
  
    unordered_map<int,list<int>>adj;
  for(int i=0;i<edges.size();i++)
  {
   
    adj[edges[i][0]].push_back(edges[i][1]);
  }
  vector<bool>visit(v);
  stack<int>s;
  for(int i=0;i<v;i++)
  {
    if(!visit[i])
    {
        dfsSort(i,adj,visit,s);
     
    }
  }
  vector<int>ans;
  while(!s.empty())
  {
      ans.push_back(s.top());
      s.pop();
  }
  
  return ans;

}
int main()
{
    return 0;
}