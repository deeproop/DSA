#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    //declaring adjacencyList using n+1 as it is 1 based indexing
    vector<int>adj[n+1];
    int i,u,v;

    //taking edges input
    for(i=0; i<m; i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}
// Better than adjacency matrix in terms of efficiency
// Space C - N   Time C - O(N+1 + 2E), N -> no. of nodes, E -> no. of edges

// FOR Weighted Graph;
/* int i,u,v,wt;
  cin>>u>>v>>wt;
  vector<pair<int,int>> adj[n+1];
  adj[u],push_back({v,wt});
  adj[v],push_back({u,wt});
*/