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
const string NoF = "haircut";

// Way 1: Ordered Statistic Tree
void solve1() {
	int n; cin >> n;
	vector<int> p[n+1];
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		p[x].psb(i);
	}
	OST<int> ost;
	vector<ll> kq(MAXN,0);
	for (int i = n; i >= 0; i--) {
		for (int x : p[i]) kq[i+1] += ost.order_of_key(x);
		for (int x : p[i]) ost.insert(x); 
	}
	for (int i = 1; i <= n; i++) kq[i] += kq[i-1];
	for (int i = 0; i < n; i++) cout << kq[i] << endl;
}

// Binary Indexed Tree 
int n;
vector<int> BIT(MAXN,0);
void Update(int i) {
	while (i < n) {
		BIT[i]++;
		i += (i & (-i));
	}
}
int Get(int i) {
	int ans = 0;
	while (i) {
		ans += BIT[i];
		i -= (i & (-i));
	}
	return ans;
}
void solve2() {
	cin >> n;
	vector<ll> kq(MAXN,0);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		x++;
		kq[x+1] += i - Get(x);
		Update(x);
	}
	for (int i = 2; i <= n; i++) kq[i] += kq[i-1];
	for (int i = 1; i <= n; i++) cout << kq[i] << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen((NoF + ".in").c_str(),"r",stdin);
	freopen((NoF + ".out").c_str(),"w",stdout);
	solve2();
}
