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
	int m, n; cin >> m >> n;
	vector<pair<int,int>> kt[26];
	for (int i = 0; i < m; i++) {
		string x; cin >> x;
		for (int j = 0; j < n; j++) {
			kt[x[j]-'a'].pb({i,j});
		}
	}
	for (int i = 0; i < 26; i++) {
		sort(kt[i].begin(),kt[i].end(),[](auto a, auto b) {
			return pow(a.fi,2) + pow(a.se,2) < pow(b.fi,2) + pow(b.se,2);
		});
	}
	int kq = INT_MAX;
	for (int i = 0; i < 26; i++) {
		if (kt[i].size() < 2) continue;
		for (int j = 1; j < kt[i].size(); j++) kq = min(kq,abs(kt[i][j].fi-kt[i][j-1].fi) + abs(kt[i][j].se-kt[i][j-1].se));
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
