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
	long t; cin >> t;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int l = 0, r = 0;
	long check = 0;
	int kq = 0;
	while (l < n && r < n) {
		check += a[r];
		while(check > t) {
			check -= a[l];
			l++;
		}
		if (l == 0) kq = max(kq,r+1);
		else kq = max(kq,r-l+1);
		r++;
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
