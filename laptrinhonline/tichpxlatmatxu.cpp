#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int t; cin >> t;
	while (t--) {
		int x; cin >> x;
		vector<int> st(x+1,1);
		for (int i = 1; i <= x; i++) {
			for (int j = i; j <= x+1; j+=i) st[j-1] = 1 - st[j-1];
		}
		int sl = 0;
		for (int i = 1; i <= x; i++) sl += st[i];
		cout << sl << endl; 
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
// 	freopen("input.txt","r",stdin);
	solve();
}
