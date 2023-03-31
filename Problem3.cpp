#include<bits/stdc++.h>
using namespace std;

bool DFS(vector<int> adj[], int u, bool visited[], int parent)
{
    visited[u] = true;
    for(int v:adj[u])
    {
        if(!visited[v])
        {
            if(DFS(adj, v, visited, u))
                return true;
        }
        else if(v != parent)
            return true;
    }
    return false;
}

bool isCycle(vector<int> adj[], int V)
{
    bool visited[V];
    memset(visited, false, sizeof(visited));

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            if(DFS(adj, i, visited, -1))
                return true;
        }
    }
    return false;
}

int main()
{
    int V, E;
    cin>>V>>E;
    vector<int> adj[V];

    for(int i=0;i<E;i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    if(isCycle(adj, V))
        cout<<"Cycle Exist"<<endl;
    else
        cout<<"No Cycle"<<endl;

    return 0;
}
