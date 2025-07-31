#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	if (n == 1) {
		cout << 1; 
		return;
	}
	if (n <= 3) {
		cout << "NO SOLUTION";
		return;
	}
	vector<int> le;
	vector<int> chan;
	for (int i = 1; i <= n; i++) {
		if (i % 2) le.pb(i);
		else chan.pb(i);
	}
	reverse(le.begin(),le.end());
	reverse(chan.begin(),chan.end());
	for (int x : le) cout << x << " ";
	for (int x : chan) cout << x << " ";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
