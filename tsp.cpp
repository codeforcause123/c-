
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void printGraph(vector<pair<int, int>> adj[], int V)
{
    int v, w;
    for (int u = 0; u < V; u++)
    {
        cout << "Node " << u << " makes an edge with \n";
        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}
vector<vector<int>> makeweights(vector<pair<int, int>> adj[], int V)
{
    vector<vector<int>> weights;
    int v, w;
    for (int u = 0; u < V; u++)
    {
        vector<int> temp(V, 0);
        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            temp[v] = w;
        }
        // for (auto i : temp)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        weights.push_back(temp);
    }
    return weights;
}

void printweights(vector<vector<int>> adj)
{
    for (auto i : adj)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
int main()
{
    int V = 5;
    vector<pair<int, int>> adj[V+1];
    addEdge(adj, 1, 2, 10);
    addEdge(adj, 1, 3, 15);
    addEdge(adj, 1, 4, 20);
    addEdge(adj, 2, 3, 35);
    addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 4, 25);
    addEdge(adj, 3, 4, 70);
    printGraph(adj, V);
    vector<vector<int>> weights = makeweights(adj, V);
    printweights(weights);
    // for (auto i : weights)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}
