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
		vector<long> a(n);
		for (long &x : a) cin >> x;
		long b; cin >> b;
		bool kq = true;
		for (int i = 0; i < n; i++) {
			if (!i) a[i] = min(b-a[i],a[i]);
			else {
				if (b - a[i] < a[i-1] && a[i] < a[i-1]) {
					kq = false; break;
				} else if (b - a[i] < a[i] && b - a[i] >= a[i-1]) a[i] = b - a[i];
				else if (a[i] < a[i-1] && b - a[i] >= a[i-1]) a[i] = b - a[i];
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
