#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = s.length();
		int p = 0, sl = 0;
		char k;
		for (int i = 0; i < n; i++) {
			if (i == 0) sl = 1, k = s[i];
			else {
				if (s[i] != k) {
					if (sl == 1) p = 1 - p;
					sl = 1, k = s[i];
				} else sl++;
			}
		}
		cout << p+1 << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt","r",stdin);
	solve();
}
