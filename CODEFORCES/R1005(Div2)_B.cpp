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
		vector<int> a(n),sl(n+1,0);
		for (int &x : a) {
			cin >> x;
			sl[x]++;
		}
		int l = 0, r = -1;
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			if (sl[a[i]] == 1) continue;
			if (i - tmp > r - l) l = tmp, r = i-1;
			tmp = i+1;
		}
		if (n - tmp > r - l) l = tmp, r = n-1;
		if (r - l == -1) cout << 0 << endl;
		else cout << l+1 << " " << r+1 << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
 