#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int n, m;
struct Edge {
	int u, v, w;
};
void BellmanFord(vector<Edge> adjEdge, int src, int fn) {
	vector<int> dist(n,INT_MAX);
	vector<int> tracer(n,-1);
	dist[src] = 0;
	for (int i = 1; i < n; ++i) {
		for (auto x : adjEdge) {
			int u = x.u;
			int v = x.v;
			int w = x.w;
			if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				tracer[v] = u;
			}
		}
	}
	for (auto x : adjEdge) {
		int u = x.u;
		int v = x.v;
		int w = x.w;
		if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
			cout << "Do thi co chu trinh am" << endl;
			return;
		}
	}
	if (dist[fn] != INT_MAX) {
		cout << "Shortest Distance: " << src+1 << " to " << fn+1 << ": " << dist[fn] << endl;
		cout << "Paths: ";
		int x = fn;
		vector<int> paths;
		while (tracer[x] != -1) {
			paths.push_back(x);
			x = tracer[x];
		}
		for (int j = paths.size(); j >= 0; j--) {
			cout << paths[j]+1 << (j == 0 ? "\n" : " --> ");
		}
	} else cout << "Haven't Paths";
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	int src, fn; cin >> src >> fn;
	vector<Edge> adjEdge;
	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		adjEdge.push_back({x-1,y-1,z});
	}
	BellmanFord(adjEdge,src-1,fn-1);
}
