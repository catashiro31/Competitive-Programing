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
	vector<int> nt;
	vector<bool> snt(1e6+1,true);
	for (int i = 2; i < 1e6+1; i++) {
		if (!snt[i]) continue;
		nt.pb(i);
		for (long j = 1L*i*i; j < 1e6+1; j+=i) snt[i] = false;
	}
	int t; cin >> t;
	while (t--) {
		ll a,b,x; cin >> a >> b >> x;
		if (a == 1) cout << -1 << endl;
		else {
			int res = 0;
			while (b%a == 0) b /= a, res++;
			if (b != 1) cout << -1 << endl;
			else {
				map<int,int> sl;
				for (int i = 0; i < nt.size(); i++) {
					while (x%nt[i] == 0) x /= nt[i], sl[nt[i]]++;
					while (res%nt[i] == 0) res /= nt[i], sl[nt[i]]++;
				}
				for (auto x : sl) cout << x.se << " ";
				cout << endl;
				for (auto x : sl) cout << x.fi << " ";
			}
		}
		
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
