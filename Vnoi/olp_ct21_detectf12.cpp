#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, f0, d; cin >> n >> f0 >> d;
	vector<pair<ll,ll>> pos(n);
	for (int i = 0; i < n; i++) {
		ll x, y; cin >> x >> y;
		pos[i] = {x,y};
	}
	vector<int> f(n,-1); f[f0-1] = 0;
	queue<int> q; q.push(f0-1);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < n; i++) {
			long double kc = pow(pos[u].fi - pos[i].fi,2) + pow(pos[u].se - pos[i].se,2);
			kc = sqrt(kc);
			if (kc < d && f[i] == -1) {
				f[i] = f[u] + 1;
				if (f[i] < 2) q.push(i);
			} 
		}
	}
	int sl_f1 = 0, sl_f2 = 0;
	for (int i = 0 ; i < n; i++) {
		if (f[i] == 1) sl_f1 ++;
		if (f[i] == 2) sl_f2 ++;
	}
	cout << sl_f1 << " " << sl_f2;
}	
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
