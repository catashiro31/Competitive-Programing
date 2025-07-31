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
	vector<long> a(n), b(m);
	for (long &x : a) cin >> x;
	for (long &x : b) cin >> x;
	long kq = LONG_MIN;
	vector<long> dist(n,LONG_MAX);
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j < m-1 && b[j+1] <= a[i]) j++;
		dist[i] = min(dist[i],abs(a[i]-b[j]));
	}
	j = m-1;
	for (int i = n-1; i >= 0; i--) {
		while (j > 0 && b[j-1] >= a[i]) j--;
		dist[i] = min(dist[i],abs(a[i]-b[j]));
	}
	cout << *max_element(dist.begin(),dist.end());
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
