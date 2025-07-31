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
vector<int> BIT(MAXN,0);
int n;
void Update(int i, int val) {
	while (i <= n) {
		BIT[i] = (BIT[i] + val) % MOD;
		i += (i & (-i));
	}
}
int Get(int i) {
	int ans = 0;
	while (i) {
		ans = (ans + BIT[i]) % MOD;
		i -= (i & (-i));
	}
	return ans;
}
void solve() {
	cin >> n;
	map<int,int> m;
	vector<int> arr(n);
	for (int &x : arr) {
		cin >> x;
		m[x]++;
	}
	int tmp = 0;
	for (auto &cur : m) cur.sc = ++tmp;
	for (int &x : arr) x = m[x];
	int kq = 0;
	for (int x : arr) {
		int sub = 1 + Get(x-1);
		kq = (kq + sub) % MOD;
		Update(x,sub);
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
