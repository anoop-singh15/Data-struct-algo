#include <bits/stdc++.h> 
#include<list>
#include<set>
#include<stack>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<iostream>
#include<utility>


using namespace std;

// TC ==> O(E logV)
// SC ==> O(N+E)


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<edges;i++)
    {
        adj[vec[i][0]].push_back(make_pair(vec[i][1],vec[i][2]));
            adj[vec[i][1]].push_back(make_pair(vec[i][0],vec[i][2]));

    }



    vector<int>dist(vertices,INT_MAX);
    // for(int i=0;i<vertices;i++)
    // {
    //     dist[i]=INT_MAX;
    // }
    set<pair<int,int>>s;
    dist[source]=0;

    s.insert(make_pair(0,source));
    while(!s.empty())
    {
        auto top= *(s.begin());
        int topnode=top.second;
        int topdist=top.first;
                
        s.erase(s.begin());


        for(auto i:adj[topnode])
        {
            if(topdist+i.second<dist[i.first])
            {
                auto record=s.find(make_pair(dist[i.first],i.first));
                if(record!=s.end())
                {
                    s.erase(record);
                }
                dist[i.first]=topdist+i.second;
                s.insert(make_pair(dist[i.first],i.first));
            }
        }


    }
        return dist;
}


int main(){
    return 0;
}