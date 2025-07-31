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
	int n, k; cin >> n >> k;
	long d; cin >> d;
	vector<vector<int>> mv(n,vector<int>(31));
	for (int i = 0; i < n; i++) mv[i][0] = i;
	for (int i = 0; i < k; i++) {
		int l, r; cin >> l >> r;
		--l, --r;
		for (int j = l; 2*j <= l+r; j++) swap(mv[j][0],mv[l+r-j][0]);
	}
	
	for (int i = 1; i <= 30; i++) {
		for (int j = 0; j < n; j++) mv[j][i] = mv[mv[j][i-1]][i-1];
	}
	
	vector<int> kq(n);
	for (int i = 0; i < n; i++) kq[i] = i;
	while (d) {
		long tmp = log2(d);
		vector<int> p = kq;
		for (int i = 0; i < n; i++) kq[i] = p[mv[i][tmp]];
		d -= pow(2,tmp);
	}
	for (int i = 0; i < n; i++) cout << kq[i]+1 << " ";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
