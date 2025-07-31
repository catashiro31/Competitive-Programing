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
	queue<long> q;
	for (int i = 0; i < n; i++) {
		long x; cin >> x;
		q.push(x);
	}
	vector<long> kq;
	while (!q.empty()) {
		q.push(q.front()); q.pop();
		kq.pb(q.front()); q.pop();
	}
	for (long x : kq) cout << x << " ";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
