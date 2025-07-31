#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	long k; cin >> k;
	priority_queue<long> pq;
	while(n--) {
		long x; cin >> x;
		pq.push(x);
	}
	while (k--) {
		long cmax = pq.top(); pq.pop();
		long tmp = round(1.0*cmax/2);
		pq.push(cmax-tmp);
		pq.push(tmp);
	}
	cout << pq.top();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
