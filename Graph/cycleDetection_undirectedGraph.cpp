#include<bits/stdc++.h>
using namespace std;
bool check(int s, int V, vector<int> adj[], vector<int> vis) {
    queue<pair<int,int>> q;

    vis[s] = true;
    q.push({s,-1});

    while(!q.empty()) {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();

        for(auto it : adj[node]) {
            if(!vis[it]) {
                vis[it] = true;
                q.push({it, node});
            }
            else if(par != it) {
                return false;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V+1);
    for(int i=1; i<=V; i++) {
        if(!vis[i]) {
            if(check(i, V, adj, vis)) {
                return true;
            }
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