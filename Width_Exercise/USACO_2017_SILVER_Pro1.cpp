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
	long T; cin >> T;
	vector<long> arr(n);
	for (long &x : arr) cin >> x;
	int l = 1, r = n;
	int kq = 0;
	while (l <= r) {
		int m = (r+l)/2;
		priority_queue<long,vector<long>,greater<>> pq;
		int i = 0;
		long cmax = LONG_MIN;
		while (i < m) {
			pq.push(arr[i]);
			cmax = max(cmax,arr[i]);
			i++;
		}
		while (i < n) {
			long value = pq.top(); pq.pop();
			pq.push(value+arr[i]);
			cmax = max(value+arr[i],cmax);
			i++;
		}
		if (cmax > T) l = m+1;
		else {
			kq = m;
			r = m-1;
		}
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("cowdance.in","r",stdin);
	freopen("cowdance.out","w",stdout);
	solve();
}
