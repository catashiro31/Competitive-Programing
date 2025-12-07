#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

int n, m;
string s[MAXN];
int child[MAXN*26][26], ok[MAXN*26];
int cnt = 0;
void Add(string s) {
	int u = 0;
	for (char c : s) {
		if (child[u][c-'a'] == 0) {
			child[u][c-'a'] = ++cnt;
		}
		u = child[u][c-'a'];
	}
	ok[u] = 1;
}

bool Ask(string s) {
	int u = 0;
	for (char c : s) {
		if (child[u][c-'a'] == 0) return 0;	
		u = child[u][c-'a'];
	}
	return ok[u];
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		Add(s[i]);
	}
	cin >> m;
	for (int i =1; i <= m; i++) {
		string t; cin >> t;
		cout << Ask(t);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
