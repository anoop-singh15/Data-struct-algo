#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
// #include<priority_queue>


using namespace std;


typedef pair<int,pair<int,int>> P;


void PrimsAlgorithm(int &sum,vector<P>&Mst, vector<bool>&isVisited,vector<vector<pair<int,int>>>&adj,int &V)
{
     // {weight,node,parent} min heap
     priority_queue<P,vector<P>,greater<P>>pq;
     pq.push({0,{0,-1}});

     while(!pq.empty())
     {
        int wt=pq.top().first;
        int node=pq.top().second.first;
        int parent=pq.top().second.second;

        pq.pop();

        if(isVisited[node])continue;

        isVisited[node]=true;
        if(parent!=-1)
        {
            Mst.push_back({parent,{node,wt}});
            sum+=wt;
        }
        for(auto i:adj[node])
        {
            int adjNode=i.first;
            int adjWt=i.second;
            if(!isVisited[adjNode])
            {
                pq.push({adjWt,{adjNode,node}});
            }

        }
     }
}


int main()
{
    int n=3;
    int v=3;

    // adj[0]= {node,weight}
    vector<vector<int>>mat(n,vector<int>(3));


    for(int i=0;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        mat[i][0]=x;
        mat[i][1]=y;
        mat[i][2]=z;
        
    }

    vector<vector<pair<int,int>>>adj(v,vector<pair<int,int>>());
    for(int i=0;i<n;i++)
    {
        int x=mat[i][0];
        int y=mat[i][1];
        int z=mat[i][2];
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }

    // for(int i=0;i<v;i++)
    // {
    //     cout<<i<<"->";
    //     for(auto j:adj[i])
    //     {
    //         cout<<"("<<j.first<<","<<j.second<<")";
    //     }
    //     cout<<endl;
    // }

   

    vector<bool>isVisited(v,0);

    // {src,dest,weight}
    vector<P>MST;

    int sum=0;
    
    PrimsAlgorithm(sum,MST,isVisited,adj,v);
    cout<<sum<<endl;


    for(auto i:MST)
    {
        cout<<"("<<i.first<<","<<i.second.first<<")"<<"->"<<i.second.second<<endl;
    }
    
    return 0;
}
