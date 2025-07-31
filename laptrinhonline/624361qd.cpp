#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int m, n, q; cin >> m >> n >> q;
	vector<long> a(m), b(n);
	for (long &x : a) cin >> x;
	for (long &x : b) cin >> x;
	vector<pair<long,long>> mna(m);
	for (int i = 0; i < m; i++) {
		if (i == 0) {
			mna[i].first = a[i];
			mna[i].second = a[i];
		} else {
			mna[i].first = max(a[i],mna[i-1].first);
			mna[i].second = min(a[i],mna[i-1].second);
		}
	}
	vector<pair<long,long>> mnb(n);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			mnb[i].first = b[i];
			mnb[i].second = b[i];
		} else {
			mnb[i].first = max(b[i],mnb[i-1].first);
			mnb[i].second = min(b[i],mnb[i-1].second);
		}
	}
	while (q--) {
		int u, v; cin >> u >> v;
		cout << max(1LL*mna[u-1].first*mnb[v-1].first,1LL*mna[u-1].second*mnb[v-1].second) << " ";
		cout << min(1LL*mna[u-1].first*mnb[v-1].second,1LL*mna[u-1].second*mnb[v-1].first) << endl;
	}
}
