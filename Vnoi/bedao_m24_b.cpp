#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
pair<long,long> Go(pair<long,long> p, char d) {
	if (d == 'L') return {p.fi-1,p.se};
	else if (d == 'R') return {p.fi+1,p.se};
	else if (d == 'U') return {p.fi,p.se-1};
	else if (d == 'D') return {p.fi,p.se+1};
	return p;
}
pair<long,long> RGo(pair<long,long> p, char d) {
	if (d == 'L') return {p.fi+1,p.se};
	else if (d == 'R') return {p.fi-1,p.se};
	else if (d == 'U') return {p.fi,p.se+1};
	else if (d == 'D') return {p.fi,p.se-1};
	return p;
}
void solve() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		pair<long,long> s, e;
		cin >> s.fi >> s.se >> e.fi >> e.se;
		string S; cin >> S;
		bool c = false;
		for (int i = n-1; i >= k; i--) e = RGo(e,S[i]);
		for (int i = 0; i <= n-k; i++) {
//			cout << s.fi << " " << s.se << endl;
//			cout << e.fi << " " << e.se << endl;
			long tmp = abs(e.fi-s.fi) + abs(e.se-s.se);
			if (tmp <= k) c = true;
			if (i == n-k) break;
			s = Go(s,S[i]);
			e = Go(e,S[i+k]);
		}
		if (c) cout << "YES" << endl;
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
