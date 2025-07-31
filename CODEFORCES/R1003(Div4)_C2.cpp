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
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<long> a(n), b(m);
		for (long &x : a) cin >> x;
		for (long &x : b) cin >> x;
		sort(b.begin(),b.end());
		bool kq = true;
		for (int i = 0; i < n; i++) {
			if (!i) a[i] = min(a[i],b[0]-a[i]);
			else {
				auto it = lower_bound(b.begin(),b.end(),a[i]+a[i-1]);
				if (it != b.end()) {
					if (a[i] > *it - a[i] || a[i] < a[i-1]) a[i] = *it - a[i];
				} else {
					if (a[i] < a[i-1]) {
						kq = false;
						break;
					}
				}
			}
		}
		if (kq) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
