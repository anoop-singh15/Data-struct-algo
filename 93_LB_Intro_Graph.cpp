// Type of graph
// 1> Undirected graph  - bidirectional (-----) from u to v
// 2> Directed graph - directional(--->) from u to v

// Node - entity to store data;
// edge -connected node;

// Degree (in and out inside directed graph)

// Weighted Graph edges have weight(numbers)
// If no weight is given in weighted graph assume it to be 1
// Weighted directed graph

// PATH
// Sequence of node

// CYCLIC GRAPGH
// Cyclic directed Graph
// Weighted Cyclic directed Graph  

// Acyclic Graph
// Weighted Acyclic directed Graph  

// REPRESENT GRAPH BY CODING
// ADJACENCY MATRIX
// ADJACENCY LIST

// IMPLENTATION
// map<int,list<int>>




// For AdjList:-
// Add Edge T.C: O(m) and S.C: O(n+m)
// Print Edge T.C: O(n*m) and S.C: O(1)

#include<iostream>
#include<map>
#include<list>
#include<unordered_map>

using namespace std;

// IMPORTANT
// TO  make graph generic
template <typename T>

// direction == 0->(undirected) ,1->(directed)

class graph{
    public:
    unordered_map<T,list<T>>adjacency;
    void addEdge(T u,T v,bool direction)
    {
        adjacency[u].push_back(v);
        if(direction==0)
        {
            adjacency[v].push_back(u);
        }

    }
    void printAdjList()
    {
        for(auto i:adjacency)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    graph<int> g;
    // g.addEdge(4,5,0);
    // g.addEdge(5,5,1);
    // g.addEdge(5,4,0);
    // g.addEdge(4,8,0);
    // g.addEdge(4,8,1);
    // CREATE GRAPH
    // g.addEdge(4,8,1);
    // g.addEdge(4,6,1);
    // g.addEdge(4,8,1);
    // g.addEdge(4,8,1);
    // g.addEdge(4,6,1);
    // g.addEdge(4,8,1);

    // Example
    g.addEdge(0,1,0);
    g.addEdge(0,4,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(3,2,0);
    g.addEdge(3,4,0);


// printing graph
    g.printAdjList();
 
}


// CODING NINJAS QUESTION 
// You are given an undirected graph of 'N' nodes and 'M' edges. Your task is to create the graph and print the adjacency list of the graph. It is guaranteed that all the edges are unique, i.e., if there is an edge from 'X' to 'Y', then there is no edge present from 'Y' to 'X' and vice versa. Also, there are no self-loops present in the graph.

// In graph theory, an adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a vertex in the graph.

// solution

// vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
//     // Write your code here.
//     vector<vector<int>>ans(n);
//     vector<int>adj[n];
//     for(int i=0;i<m;i++)
//     {
//         int u=edges[i][0];
//         int v=edges[i][1];
//         adj[u].push_back(v);
//         adj[v].push_back(u);


//     }
//     for(int i=0;i<n;i++)
//     {
//         ans[i].push_back(i);
//         for(int j=0;j<adj[i].size();j++)
//         {
//             ans[i].push_back(adj[i][j]);
//         }
//     }
//     return ans;
// }