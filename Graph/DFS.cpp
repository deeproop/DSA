#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs);
vector<int> dfsOfGraph(int V, vector<int> adj[]);

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

    vector<int> dfs = dfsOfGraph(n, adj);
    for(i=0; i<n; i++) {
        cout<<dfs[i]<<" ";
    }
    cout<<endl;

    return 0;
}

vector<int> dfsOfGraph(int V, vector<int> adj[]){
    vector<int> storeDfs;
    vector<int> vis(V+1);

    for(int i=1; i<=V; i++) {
        if(!vis[i]) {
            dfs(i, vis, adj, storeDfs);
        }
    }

    return storeDfs;
}

void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
    storeDfs.push_back(node);
    vis[node] = 1;

    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, vis, adj, storeDfs);
        }
    }
}