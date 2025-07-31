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
	int q; cin >> q;
	set<long> s;
	map<long,vector<int>> pos;
	long tmp = 0;
	for (int i = 0; i < q; i++) {
		int t; cin >> t;
		if (t == 1) {
			int x; cin >> x;
			s.insert(x-tmp);
			pos[x-tmp].pb(i);
		} else if (t == 2) {
			int v; cin >> v;
			tmp += v;
		} else {
			int x; cin >> x;
			s.erase(x-tmp);
			pos[x-tmp] = {};
		}
	}
	vector<pair<long,int>> kq;
	for (long x : s) {
		for (int p : pos[x]) kq.pb({x+tmp,p});
	}
	sort(kq.begin(),kq.end(),[](auto a, auto b) {
		return a.se < b.se;
	});
	cout << kq.size() << endl;
	for (auto x : kq) cout << x.fi << " ";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
