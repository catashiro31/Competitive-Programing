// ------ SEgmet Tree -----
// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;
// using ll = long long;
// template <typename T>
// using OST = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define sz(x) (int)(x).size()
// #define all(x) x.begin(), x.end()
// #define psb push_back
// #define ppb pop_back
// #define endl '\n'
// #define fi first
// #define se second
// #define lb lower_bound
// #define ub upper_bound
// const int MOD = 1e9 + 7;
// const int MAXN = 2e5 + 1;
// const string NoF = "Name_of_File";
// int a[MAXN];
// ll segtree[4*MAXN], lazy[4*MAXN];

// void build (int id, int l, int r) {
//     if (l == r) { segtree[id] = a[l]; return; }
//     int m = (l+r)>>1;
//     build(id<<1,l,m);
//     build(id<<1|1,m+1,r);
//     segtree[id] = max(segtree[id<<1], segtree[id<<1|1]);
// }

// inline void push(int id) {
//     if (!lazy[id]) return;
//     segtree[id<<1] += lazy[id];
//     segtree[id<<1|1] += lazy[id];
//     lazy[id<<1] += lazy[id];
//     lazy[id<<1|1] += lazy[id];
//     lazy[id] = 0;
// }

// void update(int id, int l, int r, int u, int v, long long val) {
//     if (r < u || v < l) return;
//     if (u <= l && r <= v) {
//         segtree[id] += val;
//         lazy[id] += val;
//         return;
//     }
//     int m = (l+r) >> 1;
//     push(id);
//     update(id<<1,l,m,u,v,val);
//     update(id<<1|1,m+1,r,u,v,val);
//     segtree[id] = max(segtree[id<<1], segtree[id<<1|1]);
// }

// int getp(int id, int l, int r, ll val) {
//     if (segtree[id] < val) return -1;
//     if (l == r) return l;
//     push(id);
//     int m = (l + r) >> 1;
//     if (segtree[id<<1] >= val) return getp(id<<1, l, m, val);
//     else return getp(id<<1|1, m+1, r, val);
// }

// void solve() {
//     int n; cin >> n;
//     for (int i = 1; i <= n; i++) cin >> a[i];
//     sort(a + 1, a + n + 1);

//     memset(segtree, 0, sizeof(segtree));
//     memset(lazy, 0, sizeof(lazy));
//     build(1, 1, n);

//     int m; cin >> m;
//     while (m--) {
//         long long t; cin >> t;
//         int p = getp(1, 1, n, t);
//         if (p == -1) {
//             cout << 0 << '\n';
//         } else {
//             cout << (n - p + 1) << '\n';
//             update(1, 1, n, p, n, -1);
//         }
//     }
// }

// int main() {
//     // freopen((NoF + ".in").c_str(), "r", stdin);
//     // freopen((NoF + ".out").c_str(), "w", stdout);
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int t = 1;
//     while(t--) {
//         solve();
//     }
// }
// ------------ BInary SEarch + BIT -----------

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define psb push_back
#define ppb pop_back
#define endl '\n'
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 1;
const string NoF = "Name_of_File";

void update(vector<int> &BIT, int x, int val) {
    for (; x < sz(BIT); x += x&(-x)) BIT[x] += val;
} 

int get(const vector<int> &BIT, int x) {
    int res = 0;
    for (; x > 0; x -= x&(-x)) res += BIT[x];
    return res;
}

int tknp(vector<int> &BIT, vector<int> &a, int val) {
    int l = 1, r = sz(a)-1;
    int res = -1;
    while (l < r) {
        int m = (r+l) >> 1;
        if (a[m]+get(BIT,m) >= val) {
            res = m;
            r = m-1;
        } else l = m+1;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin()+1, a.end());
    vector<int> BIT(n+5,0);
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        int p = tknp(BIT,a,x);
        cout << (n-p+1) << endl;
        update(BIT,p,-1);
    }
}
    
int main() {
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}