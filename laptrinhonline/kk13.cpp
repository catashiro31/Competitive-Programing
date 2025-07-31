#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, q; cin >> n >> q;
	vector<long> h(n);
	for (long &x : h) cin >> x;
	stack<long> stx;
	vector<long> sbnx(n);
	for (int j = n-1; j >= 0; j--) {
		while(!stx.empty() && stx.top() < h[j]) stx.pop();
		sbnx[j] = stx.size();
		stx.push(h[j]);
	}
	stack<long> stn;
	vector<long> sbnn(n);
	for (int i = 0; i < n; i++) {
		while (!stn.empty() && stn.top() < h[i]) stn.pop();
		sbnn[i] = stn.size();
		stn.push(h[i]);
	}
	while (q--) {
		int x; cin >> x;
		cout << max(sbnx[x-1],sbnn[x-1]) << endl;
	}
}