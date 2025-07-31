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
	while(t--) {
		int n; cin >> n;
		vector<int> sl(n+2,0);
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			sl[x]++;
		}
		bool kq = true;
		for (int i = 1; i <= n; i++) {
			if (!sl[i]) continue;
			if (sl[i] == 1) { kq = false; break; }
			sl[i+1] += sl[i] - 2;
		}
		if (sl[n+1] % 2) kq = false;
		if (kq) cout << "YES" << endl;
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
