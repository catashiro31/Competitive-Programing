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
	vector<ll> a(n);
	for (ll &x : a) cin >> x;
	sort(a.begin(),a.end());
	vector<pair<int,ll>> kq;
	kq.pb({1,a[0]});
	for (int i = 1; i < n; i++) {
		if (a[i] == kq[kq.size()-1].se) kq[kq.size()-1].fi++;
		else kq.pb({1,a[i]});
	}
	sort(kq.begin(),kq.end());
	for (auto [sl,x] : kq) cout << x << " ";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
