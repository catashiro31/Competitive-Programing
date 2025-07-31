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
	vector<long> p(n);
	for (long &x : p) cin >> x;
	sort(p.begin(),p.end());
	long pos = p[n/2];
	ll kq = 0;
	for (int i = 0; i < n; i++) kq += abs(pos-p[i]);
	cout << kq; 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
