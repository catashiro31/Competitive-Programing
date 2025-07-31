#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void cong(vector<int> &a, int x) {
	if (x == 4) a[2] += 2;
	else if (x == 6) a[2]++, a[3]++;
	else if (x == 8) a[2] += 3;
	else if (x == 9) a[3] += 2;
	else a[x] ++;
}
void tru(vector<int> &a, int x) {
	if (x == 4) a[2] -= 2;
	else if (x == 6) a[2]--, a[3]--;
	else if (x == 8) a[2] -= 3;
	else if (x == 9) a[3] -= 2;
	else a[x] --;
}
void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	
	vector<vector<int>> sl(n+1,vector<int>(10,0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 9; j++) sl[i][j] = sl[i-1][j];
		tru(sl[i],a[i-1]);
		cong(sl[i],b[i-1]);
	}
	while (q--) {
		int l,r; cin >> l >> r;
		vector<int> tmp(10);
		for (int i = 2; i <= 9; i++) {
			tmp[i] = sl[r][i] - sl[l-1][i];
		}
		bool c = true;
		for (int i = 2; i <= 9; i++) {
			if (i != 2 && i != 5 && tmp[i] > 0) {
				c = false;
				break;
			}
		}
		if (c) cout << "Y" << endl;
		else cout << "N" << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt","r",stdin);
	solve();
}
