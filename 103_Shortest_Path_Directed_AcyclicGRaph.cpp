// USE TOPOLOGICAL SORT
// then update distance array

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<utility>
#include<algorithm>
#include<stack>
#include<limits.h>
using namespace std;


class Graph
{
    public:
        unordered_map<int,list<pair<int,int>>>wadj;
        void addEdge(int u,int v,int w)
        {
            pair<int,int>p=make_pair(v,w);
            wadj[u].push_back(p);
        }
        


        void print()
        {
            for(auto i:wadj)
            {
                cout<<i.first<<"->";
                for(auto j:i.second)
                {
                    cout<<j.first<<","<<j.second<<endl;
                }
                cout<<endl;
            }
        }

        // vector<int>TopologicalSort()
        void dfs(int node,unordered_map<int,bool>&visit,stack<int>&s)
        {
            visit[node]=1;
            for(auto i:wadj[node])
            {
                if(!visit[i.first])
                {
                    dfs(i.first,visit,s);
                }
            }
            s.push(node);
        }

        void ShortestPath(int src,vector<int>&dist,stack<int>&s)
        {
            dist[src]=0;
             while(!s.empty())
            {
                int top=s.top();
                s.pop();
                if(dist[top]!=INT_MAX)
                {
                    for(auto i:wadj[top])
                    {
                       
                        if(dist[top]+i.second<dist[i.first])
                        {
                            dist[i.first]=dist[top]+i.second;
                        }
                    }
                }
            } 
                    

        }


};

int main()
{
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.print();

    //Topological sort
    int n=6;
    unordered_map<int,bool>visit;
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        if(!visit[i])
        {
           g.dfs(i,visit,s);
        }
    }
    // while(!s.empty())
    // {
    //     cout<<s.top()<<endl;
    //     s.pop();
    // }
    int src=1;
    vector<int>distance(n);
    for(int i=0;i<n;i++)
    {
        distance[i]=INT_MAX;
    }
    g.ShortestPath(src,distance,s);
    for(int i=0;i<n;i++)
    {
        cout<<distance[i]<<" ";
    }

    return 0;
}