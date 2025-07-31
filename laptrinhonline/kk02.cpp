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
	int n; cin >> n;
	vector<long> a(n);
	for (long &x : a) cin >> x;
	vector<long> ij(n);
	long imax = LONG_MIN;
	for (int i = 0; i < n; i++) {
		if (i > 0) ij[i] = imax - a[i];
		imax = max(imax,a[i]);
	}
	long ijmax = LONG_MIN, kq = LONG_MIN;
	for (int i = 1; i < n; i++) {
		if (i > 1) kq = max(kq,ijmax + a[i]);
		ijmax = max(ijmax,ij[i]);
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
