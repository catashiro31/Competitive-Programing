#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
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
vector<vector<ll>> Multi(vector<vector<ll>> A, vector<vector<ll>> B) {
	vector<vector<ll>> ans(A.size(),vector<ll>(B[0].size(),0));
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B[0].size(); j++) {
			for (int k = 0; k < A[0].size(); k++) ans[i][j] = (ans[i][j]+A[i][k]*B[k][j])%MOD;
		}
	}
	return ans;
}
vector<vector<ll>> Pow(vector<vector<ll>> base, ll exp) {
	int n = base.size();
	vector<vector<ll>> ans(n,vector<ll>(n,0));
	for (int i = 0; i < n; i++) ans[i][i] = 1;
	while (exp) {
		if (exp & 1) ans = Multi(ans,base);
		base = Multi(base,base);
		exp /= 2;
	}
	return ans;
}
void solve() {
	int n; cin >> n;
	ll k; cin >> k;
	vector<vector<ll>> adjMatrix(n,vector<ll>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> adjMatrix[i][j];
	}
	vector<vector<ll>> dp = Pow(adjMatrix,k);
	ll kq = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) kq = (kq + dp[i][j])%MOD;
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
