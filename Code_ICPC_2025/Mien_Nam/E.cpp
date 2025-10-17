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
int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y,x%y);
}
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	if (n == 1) {
		cout << 2 << endl;
		return;
	}
	for (int &x : a) cin >> x;
	int i = 0, cnt = 0, kq = 0;
	while (i < n-1) {
		int val = gcd(a[i],a[i+1]);
		if (val == 1 || val == min(a[i],a[i+1])) {
			i += 2;
			kq++;
			continue;
		}
		i++;
		cnt++;
		kq++;
	}
	if (i < n) cnt++;
	if (cnt&1) cout << kq + cnt/2 + 1 << endl;
	else cout << kq + cnt/2 << endl;
}

int main() {
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    while(t--) {
        solve();
    }
}
