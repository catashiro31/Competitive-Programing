#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 998244353
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
vector<vector<ll>> multi(vector<vector<ll>> a, vector<vector<ll>> b) {
	vector<vector<ll>> ans(a.size(),vector<ll>(b[0].size(),0));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < a[0].size(); k++) ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % mod;  
		}
	}
	return ans;
}
vector<vector<ll>> P(vector<vector<ll>> base, ll exp) {
	vector<vector<ll>> ans(base.size(),vector<ll>(base.size(),0));
	for (int i = 0; i < base.size(); i++) ans[i][i] = 1;
	while (exp) {
		if (exp % 2) ans = multi(ans,base);
		base = multi(base,base);
		exp /= 2;
	}
	return ans;
}
void solve() {
	vector<vector<ll>> tmp(2,vector<ll>(2,0));
	tmp[0][1] = 1, tmp[1][0] = 1, tmp[1][1] = 1;
	vector<vector<ll>> f(1,vector<ll>(2));
	f[0][0] = 1, f[0][1] = 1;
	ll n; cin >> n;
	tmp = P(tmp,n);
	f = multi(f,tmp);
	cout << (f[0][0] * f[0][1]) % mod;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
