#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
ll multiply_mod(ll a, ll b, ll m) {
    a %= m, b %= m;
    ll result = 0;
    while (b) {
        if (b % 2 == 1) result = (result + a) % m;
        a = (a * 2) % m;
        b = (b / 2) % m;
    }
    return result;
}
vector<vector<ll>> Nhan(vector<vector<ll>> a, vector<vector<ll>> b, ll m) {
	vector<vector<ll>> ans(a.size(),vector<ll>(b[0].size(),0));
	for (int i = 0; i < a.size(); i ++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < b.size(); k++) {
				ans[i][j] = (ans[i][j] + multiply_mod(a[i][k],b[k][j],m)) % m;
			}
		}
	}
	return ans;
}
vector<vector<ll>> Pow(vector<vector<ll>> base, ll exp, ll m) {
	vector<vector<ll>> ans(base.size(),vector<ll>(base.size(),0));
	for (int i = 0; i < base.size(); i++) ans[i][i] = 1;
	while (exp) {
		if (exp % 2) ans = Nhan(ans,base,m);
		base = Nhan(base,base,m);
		exp /= 2;
	}
	return ans;
}
void solve() {
    ll a, b, m; cin >> a >> b >> m;
    while (a != b) {
    	if (a > b) a -= b;
    	else if (a < b) b -= a;
	}
	ll n = a;
	
	vector<vector<ll>> f(2,vector<ll>(2));
	f[0][0] = 0, f[0][1] = 1, f[1][0] = 1, f[1][1] = 1;
	vector<vector<ll>> kq = Pow(f,n,m);
	cout << kq[0][1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}