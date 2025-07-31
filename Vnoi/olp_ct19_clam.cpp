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
	int n, m; cin >> n >> m;
	vector<vector<long>> ngh(n,vector<long>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> ngh[i][j];
	}
	long t, rl; cin >> t >> rl;
	while (t--) {
		int k; cin >> k;
		if (k == 1) {
			long C, c1, r1, c2, r2; cin >> C >> c1 >> r1 >> c2 >> r2;
			c1--, r1--, c2--, r2--;
			bool c = true;
			for (int i = r1; i <= r2; i++) {
				for (int j = c1; j <= c2; j++) {
					if (ngh[i][j] < rl) c = false;
				}
				if (!c) break;
			}
			if (c) {
				long sl = 0;
				for (int i = r1; i <= r2; i++) {
					if (i % 2) {
						for (int j = c2; j >= c1; j--) {
							if (sl + ngh[i][j] - rl < C) {
								sl += ngh[i][j] - rl;
								ngh[i][j] = rl;
							} else {
								ngh[i][j] -= (C-sl);
								sl = C;
								break; 
							}
						}
						if (sl == C) break;
					} else {
						for (int j = c1; j <= c2; j++) {
							if (sl + ngh[i][j] - rl < C) {
								sl += ngh[i][j] - rl;
								ngh[i][j] = rl;
							} else {
								ngh[i][j] -= (C-sl);
								sl = C;
								break; 
							}
						}
						if (sl == C) break;
					}
				}
//				for (int i = r1; i <= r2; i++) {
//					for (int j = c1; j <= c2; j++) cout << ngh[i][j] << " ";
//					cout << endl;
//				}
				cout << sl << endl;
			} else cout << 0 << endl;
		} else {
			long x; cin >> x;
			rl = x;
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
