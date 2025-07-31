#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	vector<pair<long,long>> events(n);
	for (int i = 0; i < n; i++) {
		long a, b; cin >> a >> b;
		events[i] = {b,a};
	}
	sort(events.begin(),events.end());
	int sl = 0;
	long prv;
	for (int i = 0; i < n; i++) {
		if (sl == 0) {
			prv = events[i].fi;
			sl++;
		} else if (events[i].se >= prv) {
			prv = events[i].fi;
			sl++;
		}
	}
	cout << sl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
