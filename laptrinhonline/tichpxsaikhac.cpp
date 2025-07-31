#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
void solve() {
	int n; cin >> n;
	vector<ll> arr(n);
	for (ll &x : arr) cin >> x;
	ll sl_am = 0, sl_duong = 0;
	ll t_am = 0, t_duong = 0;
	sort(arr.begin(),arr.end());
	ll kq = 0;
	for (int i = 0; i < n; i++) {
		if (i) kq += (arr[i]*sl_am + t_am) + (arr[i]*sl_duong - t_duong);
		if (arr[i] < 0) sl_am++, t_am -= arr[i];
		else sl_duong++, t_duong += arr[i];
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
