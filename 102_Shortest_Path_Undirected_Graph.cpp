#include<list>
#include<unordered_map>
#include<queue>
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

// TC and SC===> O(N+E)

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	unordered_map<int,list<int>>adj;
	for(int i=0;i<edges.size();i++)
	{
		adj[edges[i].first].push_back(edges[i].second);
				adj[edges[i].second].push_back(edges[i].first);

	}

unordered_map<int,bool>visit;
	unordered_map<int,int>parent(n);
	parent[s]=-1;
	visit[s]=1;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int f=q.front();
		q.pop();
		for(auto i:adj[f])
		{
			if(!visit[i])
			{
				q.push(i);
				visit[i]=1;
				parent[i]=f;
			}
		}
	}
	

	vector<int>ans;
	int curr=t;
	ans.push_back(t);
	while(curr!=s)
	{
		curr=parent[curr];
		ans.push_back(curr);
	}
	reverse(ans.begin(),ans.end());
	return ans;
}


int main()
{
    return 0;
}