#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, m; cin >> n >> m;
	long k; cin >> k;
	vector<long> a(n);
	for (long &x : a) cin >> x;
	vector<long> b(m);
	for (long &x : b) cin >> x;
	sort(b.begin(),b.end());
	sort(a.begin(),a.end());
	int j = 0, sl = 0;
	for (int i = 0; i < n; i++) {
		while(j < m && a[i] > b[j]+k) j++;
		if (j == m) break;
		else {
			if (a[i] >= b[j]-k) sl++,j++;
		}
	}
	cout << sl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
