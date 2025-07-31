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
	priority_queue<long> pq;
	while (n--) {
		long x; cin >> x;
		pq.push(x);
	}
	queue<long> q;
	while (!pq.empty()) {
		q.push(pq.top()); pq.pop();
		q.push(q.front()); q.pop();
	}
	vector<long> kq;
	while (!q.empty()) {
		kq.pb(q.front()); q.pop();
	}
	reverse(kq.begin(),kq.end());
	for (long x : kq) cout << x << " ";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
