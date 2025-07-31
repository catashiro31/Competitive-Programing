#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
bool isCycle = false;
void DFS(int u, vector<int> adjList[], vector<int> &visited, vector<int> &topo_sort) {
    visited[u] = 0;
    for (int v : adjList[u]) {
        if (visited[v] == -1) DFS(v, adjList, visited, topo_sort);
        if (visited[v] == 0) isCycle = true;
    }
    topo_sort.push_back(u);
    visited[u] = 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; 
    cin >> n >> m;
    string xau;
    cin >> xau;
    vector<int> adjList[n];
    for (int i = 0; i < m; i++) {
        int u, v; 
        cin >> u >> v;
        adjList[u - 1].push_back(v - 1);
    }
    vector<int> topo_sort;
    vector<int> visited(n, -1);
    for (int i = 0; i < n; i++) {
        if (visited[i] == -1) DFS(i, adjList, visited, topo_sort);
    }
    if (isCycle) {
        cout << -1;
        return 0;
    }
    reverse(topo_sort.begin(), topo_sort.end());
    vector<vector<int>> char_count(n, vector<int>(26, 0));
    int result = 0;
    for (int u : topo_sort) {
        char_count[u][xau[u] - 'a']++;
        for (int v : adjList[u]) {
            for (int ch = 0; ch < 26; ch++) {
                char_count[v][ch] = max(char_count[v][ch], char_count[u][ch]);
            }
        }
        result = max(result, *max_element(char_count[u].begin(), char_count[u].end()));
    }
    cout << result;
    return 0;
}
