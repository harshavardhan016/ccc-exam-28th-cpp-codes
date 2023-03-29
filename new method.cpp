#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, int node, vector<int>& visited) {
    visited[node] = 1;
    for (int i = 0; i < graph.size(); i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

int coolGraph(int g_nodes, vector<int> g_from, vector<int> g_to) {
    int ans = 0;
    int n = g_nodes;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < g_from.size(); i++) {
        graph[g_from[i]-1][g_to[i]-1] = 1;
        graph[g_to[i]-1][g_from[i]-1] = 1;
    }
    
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited);
            ans++;
        }
    }
    return ans;
}

int main() {
    int g_nodes, g_edges;
    cin >> g_nodes >> g_edges;

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);

    for (int i = 0; i < g_edges; i++) {
        cin >> g_from[i] >> g_to[i];
    }

    int result = coolGraph(g_nodes, g_from, g_to);

    cout << result << endl;

    return 0;
}