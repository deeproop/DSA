#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    //declaring adjacency matrix using n+1 as it is 1 based indexing
    int adj[n+1][n+1];
    int i,u,v;
    //taking edges input
    for(i=0; i<m; i++) {
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;

    }

    return 0;

}

//this can be used for small values
//Space C - n*n    Time C - O(n^2)