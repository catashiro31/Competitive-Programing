#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
int n;
void solve() {
	cin >> n;
	vector<vector<string>> kq(n);
	kq[0] = {"0","1"};
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < kq[i-1].size(); j++) kq[i].pb("0"+kq[i-1][j]);
		for (int j = kq[i-1].size()-1; j >= 0; j--) kq[i].pb("1"+kq[i-1][j]);
	}
	for (string x : kq[n-1]) cout << x << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}