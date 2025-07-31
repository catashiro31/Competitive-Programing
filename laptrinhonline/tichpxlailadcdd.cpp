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
	vector<long> arr(n);
	for (long &x : arr) cin >> x;
	vector<long> lis;
	for (int i = 0; i < n; i++) {
		if (!lis.empty()) {
			auto it = lower_bound(lis.begin(),lis.end(),arr[i]);
			if (it == lis.end()) lis.pb(arr[i]);
			else *it = arr[i];
		} else lis.pb(arr[i]);
	}
	cout << lis.size();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
