#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define INF INT_MAX
using ll = long long;
using namespace std;
int n, m;
void spfa(vector<pair<int,long>> adjList[], int src, int fn) {
    vector<long long> dst(n, LLONG_MAX);
    vector<int> cnt(n, 0);
    vector<bool> indeque(n, false);
    vector<int> parents(n,-1);
    deque<int> dq;
    dst[src] = 0;
    dq.push_back(src);
    indeque[src] = true;
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        indeque[u] = false;
        for (auto x : adjList[u]) {
            int v = x.first;
            long w = x.second;
            if (dst[u] + w < dst[v]) {
                dst[v] = dst[u] + w;
                parents[v] = u;
                if (!indeque[v]) {
                    if (dq.empty() || dst[v] < dst[dq.front()])
                        dq.push_front(v);
                    else
                        dq.push_back(v);
                    indeque[v] = true;
                    cnt[v]++;
                    if (cnt[v] > n) {
                        cout << "YES" << endl;
                        int str = v;
                        for (int i = 0; i < n; i++) str = parents[str];
                        vector<int> cycle;
                        for (int cur = str; ; cur = parents[cur]) {
                        	cycle.push_back(cur);
                        	if (cur == str && cycle.size() > 1) break;
						} 
						reverse(cycle.begin(),cycle.end());
						for (int node : cycle) cout << node+1 << " ";
                        return;
                    }
                }
            }
        }
    }
	cout << "NO";
	return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    vector<pair<int, long>> adjList[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        long w;
        cin >> u >> v >> w;
        adjList[u - 1].push_back({v - 1, w});
    }
    spfa(adjList, 0, n - 1);
}
