#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
void solve() {
	int k, n, i, j; cin >> k >> n >> i >> j;
	ll S; cin >> S;
	vector<vector<ll>> matrix[k];
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			vector<ll> tmp(n);
			for (int g = 0; g < n; g++) cin >> tmp[g];
			matrix[i].pb(tmp); 
		}
	}
	vector<vector<ll>> kq(n,vector<ll>(n,0));
	for (int i = 0; i < n; i++) kq[i][i] = 1;
	for (int i = 0; i < k; i++) {
		vector<vector<ll>> tmp(n,vector<ll>(n,0));
		for (int j = 0; j < n; j++) {
			for (int g = 0; g < n; g++) {
				for (int h = 0; h < n; h++) tmp[j][g] = (tmp[j][g] + kq[j][h]*matrix[i][h][g]) % S;
			}
		}
		kq = tmp;
	}
	cout << kq[i-1][j-1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
