#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n);
    vector<int> in(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u - 1].push_back(v - 1);
        in[v - 1]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) q.push(i);
    }
    vector<int> topo_sort;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_sort.push_back(u);
        for (int v : adjList[u]) {
            in[v]--;
            if (in[v] == 0) q.push(v);
        }
    }
    vector<int> path(n, 0);
    path[0] = 1;
    for (int u : topo_sort) {
    	if (!path[u]) continue;
        for (int v : adjList[u]) {
            path[v] = max(path[v], path[u] + 1);
        }
    }
    if (path[n - 1] == 0) 
        cout << "Hello World!";
    else 
        cout << path[n - 1];
    return 0;
}