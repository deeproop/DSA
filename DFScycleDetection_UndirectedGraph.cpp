#include<bits/stdc++.h>
using namespace std;

bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[]) {
    vis[node] =1;
    for(auto it: adj[node]) {
        if(vis[it] == 0) {
            if(checkForCycle(it, node, vis, adj)) return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V+1);
    for(int i=1; i<=V; i++) {
        if(!vis[i]){
            if(checkForCycle(i, -1, vis, adj)) return true;
        }
    }
    return false;
}
int main() {
    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];
    int i,v,u;
    for(i=1; i<=n; i++) {
        cin>>v>>u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = isCycle(n, adj);
}