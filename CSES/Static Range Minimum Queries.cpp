#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, q; cin >> n >> q;
	vector<vector<long>> table(log2(n)+1,vector<long>(n,0));
	for (int i = 0; i < n; i++) {
		cin >> table[0][i]; 
	}
	for (int i = 1; i <= log2(n); i++) {
		for (int j = 0; j <= n - (1 << i); j++) {
			table[i][j] = min(table[i-1][j],table[i-1][j + (1 << (i-1))]);
		}
	}
//	for (int i = 0; i <= log2(n); i++) {
//		for (int j = 0; j < n; j++) cout << table[i][j] << " ";
//		cout << endl;
//	}
	while (q--) {
		int a, b; cin >> a >> b;
		--a, --b;
		int k = log2(b-a+1);
		cout << min(table[k][a],table[k][b-(1<<k)+1]) << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
