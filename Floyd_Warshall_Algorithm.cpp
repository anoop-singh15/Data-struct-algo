#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>

using namespace std;
// TC=O(N^3)
// SC=O(N^2)

class Solution{
    void Shortest_Distance(vector<vector<int>>&adj,bool &cycle)
    {
        int n=adj.size();
       
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(adj[i][k]!=INT_MAX && adj[k][j]!=INT_MAX)
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }

        // Detecting negative cycle
        for(int i=0;i<n;i++)
        {
            if(adj[i][i]<0)
            {
                cycle=true;
                return;
            }
        }

    }
};


int main()
{
    int n;
    cin>>n;
    vector<vector<int>>adj(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>adj[i][j];
        }
    }

    Solution s;
    bool cycle=false;
    s.Shortest_Distance(adj,cycle);

    if(cycle)
    {
        cout<<"Negative Cycle is present";
    }

    for(auto i:adj)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;

}