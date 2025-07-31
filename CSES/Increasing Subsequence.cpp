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
	vector<long> kq;
	for (int i = 0; i < n; i++) {
		long x; cin >> x;
		if (kq.empty()) kq.pb(x);
		else {
			auto it = lower_bound(kq.begin(),kq.end(),x);
			if (it == kq.end()) kq.pb(x);
			else *it = x;
		}
	}
	cout << kq.size();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	solve();
}
