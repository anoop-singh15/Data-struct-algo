// TOPOLOGICAL _SORT
#include <bits/stdc++.h> 
#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<utility>

using namespace std;

// TC--> O(N+E)
// SC--> O(N+E)


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>>adj;
    // Adjacenecy list
  for(int i=0;i<edges.size();i++)
  {
   
    adj[edges[i][0]].push_back(edges[i][1]);
  }
  
//   Indegree
  vector<int>indegree(v);
  for(auto i:adj)
  {
    for(auto j:i.second)
    {
      indegree[j]++;
    }
  }
//   Queue
  queue<int>q;
  for(int i=0;i<v;i++)
  {
    if(indegree[i]==0)

    {
      q.push(i);
    }
  }
  vector<int>ans;
//   Logic
  while(!q.empty())
  {
    int front=q.front();
    q.pop();
    ans.push_back(front);
    for(auto i:adj[front])
    {
      indegree[i]--;
      if(indegree[i]==0) q.push(i);
    }
  }
  
  
  return ans;

}
int main()
{
    return 0;
}
