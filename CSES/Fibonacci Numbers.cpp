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
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < a[0].size(); k++) kq[i][j] = (kq[i][j] + a[i][k] * b[k][j]) % mod;
		}
	}
	return kq;
}
vector<vector<ll>> Pow(vector<vector<ll>> base, ll exp) {
	vector<vector<ll>> ans(base.size(), vector<ll>(base.size(),0));
	for (int i = 0; i < base.size(); i++) ans[i][i] = 1;
	while (exp) {
		if (exp & 1) ans = Multi(ans,base);
		base = Multi(base,base);
		exp >>= 1;
	}
	return ans;
}
void solve() {
	ll n; cin >> n;
	if (n == 0) cout << 0;
	else { 
		vector<vector<ll>> tmp = {{1,1},{1,0}};
		vector<vector<ll>> f = {{1},{0}};
		tmp = Pow(tmp,n-1);
		vector<vector<ll>> kq = Multi(tmp,f);
		cout << kq[0][0];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
