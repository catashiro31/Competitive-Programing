#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define psb push_back
#define ppb pop_back
#define psf push_front
#define ppf pop_front
#define endl '\n'
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
const int MAXN = 2e5+1;
const int MOD = 1e9+7;
const string NoF = "Name_of_File";
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	if (n == 1) {
		cout << 1000000000;
		return;
	}
	vector<int> l(n), r(n);
	l[0] = a[0], r[n-1] = a[n-1];
	for (int i = 1; i < n; i++) l[i] = gcd(l[i-1],a[i]);
	for (int i = n-2; i >= 0; i--) r[i] = gcd(r[i+1],a[i]);
	int kq = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) kq = max(kq,r[i+1]);
		else if (i == n-1) kq = max(kq,l[i-1]);
		else kq = max(kq,gcd(l[i-1],r[i+1]));
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
