#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	stack<int> st;
	vector<int> left(n), right(n);
	for (int i = 0; i < n; i++) {
		while (!st.empty() && a[st.top()] >= a[i]) st.pop();
		if (st.empty()) left[i] = 0;
		else left[i] = st.top()+1;
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for (int i = n-1; i >= 0; i--) {
		while (!st.empty() && a[st.top()] >= a[i]) st.pop();
		if (st.empty()) right[i] = n-1;
		else right[i] = st.top()-1;
		st.push(i);
	}
	int kq = 0;
	for (int i = 0; i < n; i++) kq = max(kq, (right[i]-left[i]+1)*a[i]);
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
