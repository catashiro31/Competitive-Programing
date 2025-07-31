#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
vector<vector<ll>> Multi(vector<vector<ll>> a, vector<vector<ll>> b) {
	vector<vector<ll>> kq(a.size(), vector<ll>(b[0].size()));
	for (int i = 0; i < a.size(); i++ ) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < a[0].size(); k++) kq[i][j] = (kq[i][j] + a[i][k] * b[k][j]) % mod;
		}
	}
	return kq;
}
vector<vector<ll>> Pow(vector<vector<ll>> base, long exp) {
	vector<vector<ll>> ans(base.size(),vector<ll>(base.size(),0));
	for (int i = 0; i < base.size(); i++) ans[i][i] = 1;
	while(exp) {
		if (exp & 1) ans = Multi(ans,base);
		base = Multi(base,base);
		exp >>= 1;
	}
	return ans;
}
void solve() {
	int n,m; cin >> n >> m;
	long k; cin >> k;
	vector<vector<ll>> Matrix(n,vector<ll>(n,0));
	for (int i = 0; i < m; i++) {
		int u,v; cin >> u >> v;
		u--, v--;
		Matrix[u][v] ++;
	}
	Matrix = Pow(Matrix,k);
	cout << Matrix[0][n-1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
