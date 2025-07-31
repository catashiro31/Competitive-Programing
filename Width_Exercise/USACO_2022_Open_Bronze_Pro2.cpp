#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name of File";
void solve() {
	int n; cin >> n;
	vector<long> G, L;
	for (int i = 0; i < n; i++) {
		char x; cin >> x;
		long nub; cin >> nub;
		if (x == 'G') G.pb(nub);
		else L.pb(nub);
	}
	sort(L.begin(),L.end());
	sort(G.begin(),G.end());
	if (L.empty() || G.empty()) cout << 0;
	else {
		int kq = INT_MAX;
		for (int i = 0; i < L.size(); i++) {
			int tmp = G.end() - upper_bound(G.begin(),G.end(),L[i]);
			kq = min(kq,i + tmp);
		}
		cout << kq;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
