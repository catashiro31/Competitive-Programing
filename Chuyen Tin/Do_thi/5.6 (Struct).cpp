#include <bits/stdc++.h>
using namespace std;
struct Graph {
    int n;
    vector<unordered_set<int>> adjList;
    vector<vector<bool>> adjMatrix;   
    Graph(int n) : n(n), adjList(n), adjMatrix(n, vector<bool>(n, false)) {}
    void addEdge(int u, int v) {
        if (!adjMatrix[u][v]) { 
            adjList[u].insert(v);
            adjList[v].insert(u); 
            adjMatrix[u][v] = adjMatrix[v][u] = true;
        }
    }
    void listAdjacent(int u) {
        cout << "Cac dinh ke voi dinh " << u << ": ";
        for (int v : adjList[u]) {
            cout << v << " ";
        }
        cout << endl;
    }
    bool areAdjacent(int u, int v) {
        return adjMatrix[u][v];
    }
    void removeEdge(int u, int v) {
        if (adjMatrix[u][v]) { 
            adjList[u].erase(v);
            adjList[v].erase(u);
            adjMatrix[u][v] = adjMatrix[v][u] = false;
        }
    }
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	int n, m; inFile >> n >> m;
	Graph Do_thi(n);
	for (int i = 0; i < m; i++) {
		int u, v; inFile >> u >> v;
		Do_thi.addEdge(u,v);
	}
	inFile.close();
	Do_thi.listAdjacent(0);
	cout << (Do_thi.areAdjacent(0,1) ? "Yes" : "No") << '\n';
	cout << (Do_thi.areAdjacent(0,4) ? "Yes" : "No") << '\n';
	Do_thi.removeEdge(0,1);
	cout << (Do_thi.areAdjacent(0,1) ? "Yes" : "No") << '\n';
}
