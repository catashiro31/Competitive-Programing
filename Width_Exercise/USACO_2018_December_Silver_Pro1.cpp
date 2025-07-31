#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, M, c; cin >> n >> M >> c;
	vector<long> t(n);
	for (long &x : t) cin >> x;
	sort(t.begin(),t.end());
	long l = 0, r = 1e9;
	long kq = 0;
	while (l <= r) {
		long m = (l+r)/2;
		long sl = 0 , ct = 0, p = 0;
		for (int i = 0; i < n; i++) {
			if (!i) ct++, sl++, p = t[i];
			else {
				if (t[i] - p <= m) {
					if (ct == c) sl++, ct = 1, p = t[i];
					else ct++;
				} else sl++, ct = 1, p = t[i];
			}
		}
		if (sl <= M) kq = m, r = m-1;
		else l = m+1;
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("convention.in","r",stdin);
	freopen("convention.out","w",stdout);
	solve();
}
