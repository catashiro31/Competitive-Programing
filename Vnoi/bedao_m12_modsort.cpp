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
		int n; cin >> n;
		long k; cin >> k;
		vector<long> a(n+1);
		for (int i = 1; i <= n; i++) cin >> a[i];
		map<long,int> p;
		bool c = true;
		for (int i = 1; i <= n; i++) {
			if (p[a[i]%k] != 0 && a[p[a[i]%k]] > a[i]) c = false;
			p[a[i]%k] = i;
		}
		if (!c) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
