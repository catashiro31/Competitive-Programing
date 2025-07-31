#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
vector<vector<ll>> Nhan(vector<vector<ll>> a, vector<vector<ll>> b) {
	vector<vector<ll>> ans(a.size(),vector<ll>(b[0].size(),0));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < a[0].size(); k++) ans[i][j] = (ans[i][j] + a[i][k]*b[k][j]) % mod;
		}
	} 
	return ans;
}
vector<vector<ll>> Pow(vector<vector<ll>> base,ll exp) {
	vector<vector<ll>> ans(base.size(),vector<ll>(base.size(),0));
	for (int i = 0; i < base.size(); i++) ans[i][i] = 1;
	while (exp) {
		if (exp % 2) ans = Nhan(ans,base);
		base = Nhan(base,base);
		exp /= 2;
	}
	return ans;
}
ll Det(vector<vector<ll>> a) {
	int n = a.size();
	if (n == 1) return a[0][0];
	if (n == 2) return (mod + (a[0][0] * a[1][1] - a[0][1] * a[1][0]) % mod) % mod;
	ll kq = 0;
	for (int i = 0; i < n; i++) {
		vector<vector<ll>> adj;
		for (int j = 1; j < n; j++) {
			vector<ll> tmp;
			for (int k = 0; k < n; k++) {
				if (k == i) continue;
				tmp.pb(a[j][k]);
			}
			adj.pb(tmp);
		}
		if (i % 2) kq = ((kq - a[0][i] * Det(adj))%mod + mod)%mod;
		else kq = (kq + a[0][i] * Det(adj)) % mod;
	}
	return kq;
}
vector<vector<ll>> Adjugate(vector<vector<ll>> a) {
	int n = a.size();
	vector<vector<ll>> ans(n,vector<ll>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vector<vector<ll>> adj;
			for (int k = 0; k < n; k++) {
				if (k == i) continue;
				vector<ll> tmp;
				for (int g = 0; g < n; g++) {
					if (g == j) continue;
					tmp.pb(a[k][g]);
				}
				adj.pb(tmp);
			}
			if ((i+j) % 2) ans[i][j] = -Det(adj);
			else ans[i][j] = Det(adj);
		}
	}
	return ans;
}
ll ModExp(ll base, ll exp) {
	ll kq = 1;
	while (exp) {
		if (exp % 2) kq = (kq*base) % mod;
		base = (base * base) % mod;
		exp /= 2;
	}
	return kq;
}
void solve() {
	vector<vector<ll>> f(2,vector<ll>(2));
	f[0][0] = 0, f[0][1] = 1, f[1][0] = 1, f[1][1] = 1;
	ll n; cin >> n;
	vector<vector<ll>> Tu = Pow(f,n+1);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (i == j) Tu[i][j] = 1 - Tu[i][j];
			else Tu[i][j] = - Tu[i][j];
		}
	}
	vector<vector<ll>> Mau = f;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (i == j)  Mau[i][j] = 1 - Mau[i][j];
			else Mau[i][j] = - Mau[i][j];
		}
	}
	ll det = Det(Mau);
	det = ModExp(det,mod-2);
	Mau = Adjugate(Mau);
	vector<vector<ll>> kq = Nhan(Tu,Mau);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) kq[i][j] = (kq[i][j] * det) % mod;
	}
	cout << kq[0][1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
