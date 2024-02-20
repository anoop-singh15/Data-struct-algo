#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

// Cycle detection using BFS/Kahns algorithm in Directed Graph
// TC--->O(N+E)
// SC--->O(N+E)

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i].first - 1].push_back(edges[i].second - 1);
    }
    int count = 0;
    vector<int> indegree(n);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        count++;
        for (auto i : adj[f])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
    if (count == n)
        return false;
    else
        return true;
}

int main()
{
    return 0;
}