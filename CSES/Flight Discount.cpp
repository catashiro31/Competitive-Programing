#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int n, m;
void dijkstra(vector<pair<int,long>> adjList[]) {
	vector<long long> dstwithhalf(n,LLONG_MAX);
	vector<long long> dstwithouthalf(n,LLONG_MAX);
	dstwithhalf[0] = 0;
	dstwithouthalf[0] = 0;
	priority_queue<pair<pair<long long ,int>,bool>, vector<pair<pair<long long ,int>,bool>>, greater<pair<pair<long long,int>,bool>>> pq;
	pq.push({{0,0},false});
	while (!pq.empty()) {
		int u = pq.top().first.second;
		long long d = pq.top().first.first;
		bool check = pq.top().second;
		pq.pop();
		if ((check && d > dstwithhalf[u]) || (!check && d > dstwithouthalf[u])) continue;
		for (auto x : adjList[u]) {
			int v = x.first;
			long w = x.second;
			if (dstwithouthalf[v] > dstwithouthalf[u]+w) {
				dstwithouthalf[v] = dstwithouthalf[u]+w;
				pq.push({{dstwithouthalf[v],v},false});
			}
			if (!check && dstwithhalf[v] > dstwithouthalf[u]+w/2) {
				dstwithhalf[v] = dstwithouthalf[u]+w/2;
				pq.push({{dstwithhalf[v],v},true});
			}
			if (check && dstwithhalf[v] > dstwithhalf[u]+w) {
				dstwithhalf[v] = dstwithhalf[u]+w;
				pq.push({{dstwithhalf[v],v},true});
			}
		}
	}
	cout << min(dstwithouthalf[n-1],dstwithhalf[n-1]);
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	vector<pair<int,long>> adjList[n];
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		long w; cin >> w;
		adjList[u-1].push_back({v-1,w});
	}
	dijkstra(adjList);
}
