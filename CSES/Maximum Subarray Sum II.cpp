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
	int a,b; cin >> a >> b;
	vector<ll> arr(n);
	for (ll &x : arr) cin >> x;
	vector<ll> prefix(n+1,0);
	for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + arr[i-1];
	multiset<ll> ms;
	ll kq = LLONG_MIN;
	for (int i = 1; i <= n; i++) {
		if (i == a) {
			kq = max(kq,prefix[i]-prefix[i-a]);
			ms.insert(prefix[i-a]);
		} else if (i > a) {
			ms.insert(prefix[i-a]);
			if (i > b) ms.erase(ms.find(prefix[i-b-1]));
			kq = max(kq,prefix[i] - *ms.begin());
		} 
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
