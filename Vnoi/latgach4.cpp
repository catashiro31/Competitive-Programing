#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
const ll m = 111539786;
vector<vector<ll>> Multi (vector<vector<ll>> a, vector<vector<ll>> b) {
	vector<vector<ll>> kq(a.size(), vector<ll>(b[0].size()));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < a[0].size(); k++) kq[i][j] = (kq[i][j] + a[i][k] * b[k][j]) % m;
		}
	}
	return kq;
}
vector<vector<ll>> Pow (vector<vector<ll>> a, ll exp) {
	vector<vector<ll>> ans (a.size(), vector<ll>(a.size()));
	for (int i = 0; i < a.size(); i++) ans[i][i] = 1;
	vector<vector<ll>> base = a;
	while (exp) {
		if (exp & 1) ans = Multi(ans,base);
		base = Multi(base,base);
		exp >>= 1;
	}
	return ans;
}
void solve() {
	ll n; cin >> n;
	vector<vector<ll>> tmp = {{1,1},{1,0}};
	vector<vector<ll>> f = {{2},{1}};
	if (n == 1) cout << 1 << endl;
	else {
		tmp = Pow(tmp,n-2);
		vector<vector<ll>> kq = Multi(tmp,f);
		cout << kq[0][0] << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	int t; cin >> t;
	while (t--) solve();
}
