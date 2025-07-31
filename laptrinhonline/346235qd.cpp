#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<pair<ll, pair<ll, ll>>>> adjList(n);
    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        ll w; cin >> w;
        ll p; cin >> p;
        if (u > n || v > n) continue;
        --u, --v;
        adjList[u].pb({v, {w, p}});
        adjList[v].pb({u, {w, p}});
    }

    vector<vector<ll>> kq(n, vector<ll>(3, LLONG_MAX));
    kq[0][0] = 0; 
    kq[0][1] = 0; 
    kq[0][2] = 0; 

    priority_queue<pair<pair<ll, ll>, pair<ll, ll>>, vector<pair<pair<ll, ll>, pair<ll, ll>>>, greater<>> pq;
    pq.push({{0, 0}, {0, 0}}); 

    while (!pq.empty()) {
        ll tmp = pq.top().fi.fi;  
        ll dmax = pq.top().fi.se;  
        ll d = pq.top().se.fi;    
        ll u = pq.top().se.se;    
        pq.pop();

        if (tmp > kq[u][0]) continue;
        if (tmp == kq[u][0] && dmax > kq[u][1]) continue;
        if (tmp == kq[u][0] && dmax == kq[u][1] && d > kq[u][2]) continue;

        for (auto x : adjList[u]) {
            ll v = x.fi;
            ll w = x.se.fi;
            ll p = x.se.se;

            if (tmp + p < kq[v][0] || 
                (tmp + p == kq[v][0] && (max(w, dmax) < kq[v][1] || 
                (max(w, dmax) == kq[v][1] && d + w < kq[v][2])))) {
                kq[v][0] = tmp + p;
                kq[v][1] = max(w, dmax);
                kq[v][2] = d + w;
                pq.push({{tmp + p, max(w, dmax)}, {d + w, v}});
            }
        }
    }

    if (kq[n - 1][0] == LLONG_MAX) cout << -1;
    else cout << kq[n - 1][2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}