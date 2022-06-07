#include<bits/stdc++.h>
using namespace std;
bool check(int s, int V, vector<int> adj[], vector<int> vis) {  
    queue<pair<int,int>> q; // pair of integers entering the queue to keep track of the parent of the child node

    vis[s] = true;  
    q.push({s,-1}); // if it is the staring node then its parent is assumed to be -1

    while(!q.empty()) {
        int node = q.front().first; // current node
        int par = q.front().second; // parent 
        q.pop();

        for(auto it : adj[node]) { //checking for the adjacent edges
            if(!vis[it]) {
                vis[it] = true;  
                q.push({it, node});
            }
            else if(par != it) { // if the adjacent node is not equal to the parent then we have found the cycle
                return false;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V+1); // making a visited vector
    //traversing the nodes
    for(int i=1; i<=V; i++) {
        if(!vis[i]) {
            if(check(i, V, adj, vis)) { //if this node is giving a cycle or not
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