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
	vector<vector<ll>> ans (a.size(),vector<ll>(b[0].size(),0));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < a[0].size(); k++) ans[i][j] = (ans[i][j] + a[i][k]*b[k][j]) % mod;
		}
	}
	return ans;
}
vector<vector<ll>> Pow(vector<vector<ll>> base, ll exp) {
	vector<vector<ll>> ans(base.size(),vector<ll>(base.size(),0));
	for (int i = 0; i < base.size(); i++) ans[i][i] = 1;
	while (exp) {
		if (exp%2) ans = Nhan(ans,base);
		base = Nhan(base,base);
		exp /= 2;
	}
	return ans;
}
void solve() {
	int n; cin >> n;
	ll m; cin >> m;
	vector<vector<ll>> A(n,vector<ll>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
			A[i][j] = (mod + A[i][j]) % mod;
		}
	}
	vector<vector<ll>> B(2*n,vector<ll>(2*n,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			B[i][j] = A[i][j];
			B[i][j+n] = A[i][j];
		}
		B[i+n][i+n] = 1;
	}
	B = Pow(B,m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) B[i][j+n] = (B[i][j+n] + 1) % mod;
			cout << B[i][j+n] << " ";	
		}
		cout << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}