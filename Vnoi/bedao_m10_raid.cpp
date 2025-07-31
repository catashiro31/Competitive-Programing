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
	vector<double> a(n);
	for (double &x : a) cin >> x;
	double l = 0, r = 1e9;
	double kq;
	while (l < r) {
		double m = (l+r)/2;
		double sum = 0;
		for (int i = 0; i < n; i++) sum += a[i] - m;
		double S = LONG_MIN, tmp = 0;
		for (int i = 1; i < n-1; i++) {
			tmp = max(a[i]-m,tmp+a[i]-m);
			S = max(S,tmp);
		}
		if (sum <= S) kq = m, r = m-1e-5;
		else l = m+1e-5;
	}
	cout << fixed << setprecision(3) << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
