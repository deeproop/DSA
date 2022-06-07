#include<bits/stdc++.h>
using namespace std;

bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V+1);
    for(int i=1; i<=V; i++);
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