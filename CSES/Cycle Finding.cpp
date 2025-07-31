#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define INF INT_MAX
using ll = long long;
using namespace std;
int n, m;
vector<int> cycle;
bool spfa(vector<pair<int,long>> adjList[], int src, vector<bool> &visited) {
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
        visited[u] = true;
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
                        int str = v;
                        for (int i = 0; i < n; i++) str = parents[str];
                        for (int cur = str; ; cur = parents[cur]) {
                        	cycle.push_back(cur);
                        	if (cur == str && cycle.size() > 1) break;
						} 
						reverse(cycle.begin(),cycle.end());
                        return true;
                    }
                }
            }
        }
    }
	return false;
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
    vector<bool> visited(n,false);
    for (int i = 0; i < n; i++) {
    	if (!visited[i]) {
    		if (spfa(adjList,i,visited)) {
    			cout << "YES" << endl;
    			for (int node : cycle) cout << node+1 << " ";
    			return 0;
			}
		}
	}
	cout << "NO" ;
}