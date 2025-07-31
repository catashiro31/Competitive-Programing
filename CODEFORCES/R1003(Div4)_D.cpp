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
		ll n, m; cin >> n >> m;
		vector<pair<ll,ll>> sc_s(n,{0,0});
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ll x; cin >> x;
				sc_s[i].fi += (m-j) * x;
				sc_s[i].se += x;
			}
		}
		sort(sc_s.begin(),sc_s.end(),[](auto a, auto b) {
			return a.se > b.se;	
		});
		ll kq = 0, tmp = 0;
		for (int i = 0; i < n; i++) {
			kq += sc_s[i].fi + tmp * m;
			tmp += sc_s[i].se; 
		}
		cout << kq << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}