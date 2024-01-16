#include<list>
#include<unordered_map>
#include<iostream>
#include<vector>

#include<utility>

using namespace std;

// TC==O(N+E)
// SC==O(N)

bool CheckCycledfs(int node,unordered_map<int,list<int>>&adj,unordered_map<int,bool> &visit,unordered_map<int,bool>&dfsVisit)
{
  visit[node]=1;
  dfsVisit[node]=1;
  for(auto i:adj[node])
  {
    if(!visit[i])
    {
        bool cycledfs=CheckCycledfs(i,adj,visit,dfsVisit);
       if(cycledfs)
         return true;
    }
    
    else if(dfsVisit[i]){
      return 1;

    }
  }
  dfsVisit[node]=0;
  return 0;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,list<int>>adj;
  for(int i=0;i<edges.size();i++)
  {
    int u=edges[i].first;
    int v=edges[i].second;
    adj[u].push_back(v);
  }
  unordered_map<int,bool>visit;unordered_map<int,bool>dfsVisit;
  for(int i=1;i<=n;i++)
  {
    if(!visit[i])
    {
      bool cycle=CheckCycledfs(i,adj,visit,dfsVisit);
      if(cycle)
      return true;
    }
  }
  return false;
}

int main()
{
    return 0;
}