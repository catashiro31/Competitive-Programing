#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
const long long INF = LLONG_MAX;
using ll = long long;
using namespace std;
int n, m; 
struct edge {
	int u,v;
	long w;
};
void DFS(vector<pair<int,long>> adjList[], int u, vector<bool> &visited) {
	visited[u] = true;
	for (auto x : adjList[u]) {
		if (!visited[x.first]) DFS(adjList,x.first,visited);
	}
}
void BellmanFord(vector<edge> Edge, int src, int fn) {
	vector<long long> dst(n,LLONG_MIN);
	dst[src] = 0;
	for (int i = 0; i < n-1; i++) {
		for (auto x : Edge) {
			int u = x.u;
			int v = x.v;
			long w = x.w;
			if (dst[u] != LLONG_MIN && dst[u]+w > dst[v]) dst[v] = dst[u]+w;
		}
	}
	for (auto x : Edge) {
		int u = x.u;
		int v = x.v;
		long w = x.w;
		if (dst[u] != LLONG_MIN && dst[u]+w > dst[v]) {
			cout << -1;
			return;
		}
	}
	cout << dst[fn];
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	vector<pair<int,long>> adjList[n];
	vector<pair<int,long>> TadjList[n];
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		long w; cin >> w;
		adjList[u-1].push_back({v-1,w});
		TadjList[v-1].push_back({u-1,w});
	}
	vector<bool> visited1(n,false);
	DFS(adjList,0,visited1);
	vector<bool> visited2(n,false);
	DFS(TadjList,n-1,visited2);
	vector<bool> visited(n,false);
	for (int i = 0; i < n; i++) {
		visited[i] = visited1[i] && visited2[i];
	}
	vector<edge> Edge;
	for (int u = 0; u < n; u++) {
		for (auto x : adjList[u]) {
			if (visited[x.first] && visited[u]) Edge.push_back({u,x.first,x.second});
		}
	}
	BellmanFord(Edge,0,n-1);
}