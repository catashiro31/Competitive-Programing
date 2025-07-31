#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
vector<vector<ll>> Nhan(vector<vector<ll>> A, vector<vector<ll>> B) {
	vector<vector<ll>> ans(A.size(), vector<ll>(B[0].size(),0));
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B[0].size(); j++) {
			for (int k = 0; k < A.size(); k++) ans[i][j] = (ans[i][j] + A[i][k] * B[k][j]) % mod; 
		}
	}
	return ans;
}
vector<vector<ll>> Pow(vector<vector<ll>> A, ll exp) {
	vector<vector<ll>> kq(A.size(),vector<ll>(A.size()));
	for (int i = 0; i < A.size(); i++) kq[i][i] = 1;
	while (exp) {
		if (exp % 2) kq = Nhan(kq,A);
		A = Nhan(A,A);
		exp /= 2;
	}
	return kq;
}
void solve() {
	vector<vector<ll>> tmp(6,vector<ll>(6));
	for (int i = 0; i < 6; i++) {
		if (i < 5) tmp[i][i+1] = 1;
		else {
			for (int j = 0; j < 6; j++) tmp[i][j] = 1;
		}
	}
	vector<vector<ll>> f(6,vector<ll>(1));
	f[0][0] = 1, f[1][0] = 2, f[2][0] = 4, f[3][0] = 8, f[4][0] = 16, f[5][0] = 32;
	
	ll n; cin >> n;
	
	if (n <= 6) cout << f[n-1][0];
	else {
		tmp = Pow(tmp,n-6);
		f = Nhan(tmp,f);
		cout << f[5][0];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
