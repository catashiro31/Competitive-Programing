#include <bits/stdc++.h>
#define endl '\n'
#define INF LLONG_MAX
using namespace std;
using ll = long long;

void dijkstra(vector<vector<pair<int, pair<int, int>>>>& adjList, int n, int k) {
    priority_queue<pair<ll, pair<ll, int>>, vector<pair<ll, pair<ll, int>>>, greater<>> pq;
    pq.push({0, {0, 0}});
    ll kq = INF;
    while (!pq.empty()) {
        ll d = pq.top().first;         // Tổng khoảng cách hiện tại
        ll exp = pq.top().second.first; // Tổng chi phí thời gian hiện tại
        int u = pq.top().second.second; // Đỉnh hiện tại
        pq.pop();
        
        if (d > kq) continue;
        else if (u == n-1) {
			kq = min(d,kq);
			continue;
		}
        for (auto& edge : adjList[u]) {
            int v = edge.first;       // Đỉnh kế tiếp
            int l = edge.second.first; // Chiều dài cạnh
            int t = edge.second.second; // Thời gian đi qua cạnh
            if (exp + t <= k) pq.push({d+l,{exp+t,v}});
        }
    }
    if (kq == INF) cout << -1 << endl;
    else cout << kq << endl;
}

void solve() {
    int k, n, r;
    cin >> k >> n >> r;
    vector<vector<pair<int, pair<int, int>>>> adjList(n);
    
    for (int i = 0; i < r; i++) {
        int s, d, l, t;
        cin >> s >> d >> l >> t;
        --s, --d;
        adjList[s].emplace_back(d, make_pair(l, t));
    }
    
    dijkstra(adjList, n, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}
