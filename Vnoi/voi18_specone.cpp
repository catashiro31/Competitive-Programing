#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void solve() {
    int n, k, s, m; cin >> n >> k >> s >> m;
    vector<string> arr, special;
    for (int i = 0; i < s; i++) {
        string x; cin >> x;
        arr.psb(x);
        special.psb(x);
    }
    vector<pair<string,string>> edge;
    for (int i = 0; i < m; i++) {
        string a, b; cin >> a >> b;
        arr.psb(a), arr.psb(b);
        edge.psb({a,b});
    }
    sort(all(arr));
    arr.erase(unique(all(arr)),arr.end());
    
    map<string,int> ax;
    for (int i = 0; i < sz(arr); i++) ax[arr[i]] = i;
    
    int num_nodes = sz(arr); 
    vector<vector<int>> adj(num_nodes + 5);
    vector<int> degree(num_nodes + 5, 0);
    
    for (int i = 0; i < m; i++) {
        int ax_a = ax[edge[i].fi], ax_b = ax[edge[i].se];
        if (ax_a == ax_b) continue;
        adj[ax_a].psb(ax_b);
        adj[ax_b].psb(ax_a);
    }
    
    for(int i = 0; i < num_nodes; i++) {
        sort(all(adj[i]));
        adj[i].erase(unique(all(adj[i])), adj[i].end());
    }
    
    vector<int> kq;
    vector<bool> used(num_nodes + 5, false);
    queue<int> q;

    for (int i = 0; i < s; i++) {
        int u = ax[special[i]];
        if (!used[u]) {
            used[u] = true;
            q.push(u);
            kq.psb(u);
        }
    }

    while(!q.empty()) {
        int u = q.front(); q.pop();
        
        for (int v : adj[u]) {
            if (used[v]) continue; 
            
            degree[v]++;
            if (degree[v] == k) {
                used[v] = true;
                kq.psb(v);
                q.push(v);
            }
        }
    }

    sort(all(kq));
    cout << sz(kq) << endl;
    for (int x : kq) cout << arr[x] << " ";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--) solve();
}