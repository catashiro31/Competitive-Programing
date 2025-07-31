#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
    int n; cin >> n;
    vector<long> a(n);
    for (long &x : a) cin >> x;

    stack<int> mst;
    vector<int> l(n, -1);
    for (int i = 0; i < n; i++) {
        while (!mst.empty() && a[mst.top()] >= a[i]) mst.pop();
        if (!mst.empty()) l[i] = mst.top();
        mst.push(i);
    }

    while (!mst.empty()) mst.pop();
    vector<int> r(n, n);
    for (int i = n - 1; i >= 0; i--) {
        while (!mst.empty() && a[mst.top()] >= a[i]) mst.pop();
        if (!mst.empty()) r[i] = mst.top();
        mst.push(i);
    }

    vector<pair<long, int>> sl;
    for (int i = 0; i < n; i++) {
        sl.pb({a[i], r[i] - l[i] - 2});
    }

    sort(sl.begin(), sl.end());
    vector<long> kq(n, 0);
    int p = 0;
    for (int i = n-1; i >= 0; i--) {
        while (p <= sl[i].se) {
            kq[p] = max(kq[p], sl[i].fi);
            p++;
        }
    }
    
    for (long x : kq) cout << x << " ";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
