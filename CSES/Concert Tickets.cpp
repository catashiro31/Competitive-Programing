#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, m; cin >> n >> m;
	multiset<long> h;
	for (int i = 0; i < n; i++) {
		long x; cin >> x;
		h.insert(x);
	}
	for (int i = 0; i < m; i++) {
		long x; cin >> x;
		auto it = h.upper_bound(x);
		if (it == h.begin()) cout << -1 << endl;
		else {	
			cout << *(--it) << endl;
			h.erase(it);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
