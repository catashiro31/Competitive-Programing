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
	int n, x; cin >> n >> x;
	ll k; cin >> k;
	vector<vector<ll>> grid(3*n,vector<ll> (3*n,0));
	for (int i = 0; i < 3*n; i++) {
		int r = i + 1;
		r = r%n ? r:r-n;
		grid[i][r] ++;
		
		int l = i - 1;
		l = ((n+l)%n == n-1) ? l+n:l;
		grid[i][l] ++;
		
		int u = i + n;
		int d = i - n;
		if (d >= 0) grid[i][d] ++;
		if (u < 3*n) grid[i][u] ++;
	}
	grid = Pow(grid,k);
	for (int i = 0; i < 3*n; i++) {
		for (int j = 0; j < 3*n; j++) cout << grid[i][j] << " ";
		cout << endl;
	}
	cout << grid[0][x-1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}