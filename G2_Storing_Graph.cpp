#include<iostream>
#include<vector>

using namespace std;

//INPUT
// 5 6
// 1 2
// 1 3 
// 3 4 
// 2 4
// 2 5
// 4 5

// for weighted use vector<pair<int,int>>arr[n+1]
//  <node,weight>


int main()
{
    int n,m;
    cin>>n>>m;

    vector<int>arr[n+1];


    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);


    }

    for(int i=1;i<=n;i++)
    {
        cout<<i<<"->";
        for(int j:arr[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}