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
	vector<long> kq, w;
	for (int i = 0; i < n; i++) {
		long x; cin >> x;
		if (x >= n) kq.pb(x);
		else w.pb(x);
	}
	sort(w.begin(),w.end());
	for (int i = w.size()-1; i >= 0; i--) {
		if (kq.size() <= w[i]) kq.pb(w[i]);
	}
	cout << kq.size();
}	
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("lemonade.in","r",stdin);
	freopen("lemonade.out","w",stdout);
	solve();
}
