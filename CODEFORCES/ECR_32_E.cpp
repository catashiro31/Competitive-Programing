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
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MAXN = 2e5+1;
const int MOD = 1e9+7;
const string NoF = "Name_of_File";

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	vector<int> sub;
	int mid = (n-1)/2;
	for (int mask = 0; mask < (1 << mid+1); mask++) {
		int tmp = 0;
		for (int i = 0; i < mid+1; i++) {
			if (mask & (1 << i)) tmp = (tmp + a[i]) % m;
		}
		sub.psb(tmp);
	}
	sort(sub.begin(),sub.end());
	int kq = INT_MIN;
	for (int mask = 0; mask < (1 << n-mid-1); mask++) {
		int tmp = 0;
		for (int i = 0; i < n-mid-1; i++) {
			if (mask & (1 << i)) tmp = (tmp + a[mid+1+i]) % m;
		}
		kq = max(kq,(tmp+sub[sz(sub)-1])%m);
		auto it = ub(sub.begin(),sub.end(),m-1-tmp);
		if (it != sub.begin()) kq = max(kq,tmp+*(it-1));
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
