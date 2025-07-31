#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	vector<int> sl(1e6+1,0);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		sl[x]++;
	}
	cout << *max_element(sl.begin(),sl.end());
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("CAU2.INP","r",stdin);
//	freopen("CAU2.OUT","w",stdout);
	solve();
}
