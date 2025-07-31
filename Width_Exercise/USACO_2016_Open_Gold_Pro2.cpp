#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "closing";
int p[200001];
bool c[200001];

int Find(int u) {
    if (p[u] == u) return u;
    return p[u] = Find(p[u]); 
}

bool Union(int u, int v) {
    int pu = Find(u), pv = Find(v);
    if (pu == pv) return false;  
    if (pu > pv) swap(pu, pv);   
    p[pv] = pu;                 
    return true;
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) p[i] = i, c[i] = false; 

    vector<vector<int>> adjList(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u, --v;  
        adjList[u].pb(v); 
        adjList[v].pb(u);  
    }

    vector<int> col(n);
    for (int &x : col) cin >> x;  
    reverse(col.begin(), col.end());  

    vector<string> ans;
    int sl = 0; 
    
    for (int u : col) {
        --u;  
        sl++;  
        c[u] = true;  

        for (int v : adjList[u]) {
            if (c[v]) {  
                if (Union(u, v)) sl--;  
            }
        }

        if (sl == 1) ans.pb("YES");
        else ans.pb("NO");
    }

    reverse(ans.begin(), ans.end()); 
    for (string x : ans) cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
     freopen((NoF + ".in").c_str(),"r",stdin);
     freopen((NoF + ".out").c_str(),"w",stdout);
    solve();
}