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
	long x; cin >> x;
	vector<pair<long,int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].fi;
		a[i].se = i+1;
	}
	sort(a.begin(),a.end());
	for (int l = 0; l+2 < n; l++) {
		int m = l+1, r = n-1;
		ll check = a[l].fi + a[m].fi + a[r].fi; 
		while (m < r) {
			if (check == x) {
				cout << a[l].se << " " << a[m].se << " " << a[r].se;
				return;
			} else if (check < x) {
				check -= a[m].fi;
				check += a[++m].fi;
			}
			else {
				check -= a[r].fi;
				check += a[--r].fi;
			}
		}
	}
	cout << "IMPOSSIBLE";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}