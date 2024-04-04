#include <bits/stdc++.h>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <limits.h>
#include <iostream>
#include <vector>
using namespace std;


// current TC==> O(n^2)
// optimised TC==> O(n log n) with priority queue for searching min element


vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++)
    {
        adj[g[i].first.first].push_back(make_pair(g[i].first.second, g[i].second));
        adj[g[i].first.second].push_back(make_pair(g[i].first.first, g[i].second));
    }
    vector<int> parent(n + 1);
    vector<bool> mst(n + 1);
    vector<int> key(n + 1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = -1;
        key[i] = INT_MAX;
        mst[i] = 0;
    }
    // source here is 1
    parent[1] = -1;
    key[1] = 0;
    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;
        for (int j = 1; j <= n; j++)
        {
            if (mst[j] == 0 && key[j] < mini)
            {
                u = j;
                mini = key[j];
            }
        }
        mst[u] = 1;
        for (auto j : adj[u])
        {
            int v = j.first;
            int w = j.second;
            if (mst[v] == 0 && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector<pair<pair<int, int>, int>> res;
    for (int i = 2; i <= n; i++)
    {
        res.push_back({{parent[i], i}, key[i]});
    }
    return res;
}


int main()
{
    return 0;
}