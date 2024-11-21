#include<iostream>
#include<vector>
#include<queue>

using namespace std;








class Solution {
  public:
   
    
    void bfs(int node,vector<vector<int>> &adj,vector<int>&ans,vector<bool>&vis)
    {
        queue<int>q;
        q.push(node);
        vis[node]=1;
        while(!q.empty())
        {
            int x=q.front();
           ans.push_back(x);
            q.pop();
            for(int neighbour:adj[x])
            {
                if(!vis[neighbour])
                {
                    vis[neighbour]=1;
                    q.push(neighbour);
                }
                
            }
            
            
        }
    }
    
    
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        int n=adj.size();
        vector<bool>vis(n,0);
        vector<int>ans;
       
                bfs(0,adj,ans,vis);
          
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}




// int main()
// {
//     int n,m;
//     cin>>n>>m;

//     vector<int>arr[n+1];


//     for(int i=0;i<m;i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         arr[u].push_back(v);
//         arr[v].push_back(u);


//     }

//     for(int i=1;i<=n;i++)
//     {
//         cout<<i<<"->";
//         for(int j:arr[i])
//         {
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }