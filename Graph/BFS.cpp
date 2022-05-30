#include<bits/stdc++.h>
using namespace std;
vector<int> bfsOfGraph(int V, vector<int> adj[]);

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

    vector<int> bfs = bfsOfGraph(n, adj);
    for(i=0; i<n; i++) {
        cout<<bfs[i]<<" ";
    }
    cout<<endl;

    return 0;
}

//bfs traveral
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> bfs;
    vector<int> vis(V+1);
    
    int i;
    for(i=1; i<=V; i++) {
        if(!vis[i]) {
            queue<int> q;
            q.push(1);
            vis[1] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                
                for(auto it : adj[node]) {
                    if(!vis[it]) {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
            
        }
    }
    return bfs;
}