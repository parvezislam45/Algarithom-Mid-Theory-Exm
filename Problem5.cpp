#include<bits/stdc++.h>
using namespace std;

void DFS(vector<int> adj[], bool visited[], int u)
{
    visited[u] = true;
    for(int v:adj[u])
    {
        if(!visited[v])
            DFS(adj, visited, v);
    }
}

bool isConnected(vector<int> adj[], int n)
{
    bool visited[n+1];
    memset(visited, false, sizeof(visited));

    DFS(adj, visited, 1);

    return visited[n];
}

int main()
{
    int n, m;
    cin>>n>>m;

    vector<int> adj[n+1];

    for(int i=0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(isConnected(adj, n))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
