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
	vector<pair<long,long>> arr;
	for (int i = 0; i < n; i++) {
		long a, b; cin >> a >> b;
		arr.pb({b,a});
	}
	sort(arr.begin(),arr.end());
	int kq = 0, i = 0;
	while (i < n) {
		kq++;
		long tmp = arr[i].fi;
		i++;
		while (i < n && tmp >= arr[i].se) i++;
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
