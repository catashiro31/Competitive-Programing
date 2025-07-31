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
int n, c[20];
int tmp = 0, sum = 0;
int kq = INT_MIN;
void Try(int i) {
	if (i == n) {
		int ans = abs(sum-2*tmp);
		bool check = true;
		for (int j = 2; j*j <= ans; j++) {
			if (ans % j == 0) {
				check = false;
				break;
			}
		}
		if (check) kq = max(kq,ans); 
		return;
	}
	tmp += c[i];
	Try(i+1);
	tmp -= c[i];
	Try(i+1);
}
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		sum += c[i];
	}
	Try(0);
	if (kq < 2) cout << -1;
	else cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
