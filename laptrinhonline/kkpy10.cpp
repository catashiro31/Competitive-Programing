#include <bits/stdc++.h>
#define endl '\n'
#define mod 10000000007
using namespace std;
void DFS(vector<int> adjList[], int u, vector<bool> &visited) {
	visited[u] = true;
	for (int v : adjList[u]) {
		if (!visited[v]) DFS(adjList,v,visited);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<pair<int,int>> t(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i].first;
		t[i].second = i;
	}
	vector<int> adjList[n];
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adjList[u-1].push_back(v-1);
		adjList[v-1].push_back(u-1);
	}
	 sort(t.begin(), t.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a > b; 
    });
	vector<bool> visited(n,false);
	vector<int> kq;
	for (auto x : t) {
		if (!visited[x.second]) {
			DFS(adjList,x.second,visited);
			kq.push_back(x.second+1);
		}
	}
	cout << kq.size() << endl;
	sort(kq.begin(),kq.end());
	for (int vl : kq) cout << vl << " ";
}
