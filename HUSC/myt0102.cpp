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
	int n, m; cin >> n >> m;
	vector<string> grid(n);
	for (int i = 0; i < n; i++) cin >> grid[i];
	vector<int> arr(m,0);
	int kq = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '*') arr[j] = 0;
			else arr[j]++;
		}
		stack<int> st;
		vector<int> left(m), right(m);
		for (int j = 0; j < m; j++) {
			while (!st.empty() && arr[st.top()] >= arr[j]) st.pop();
			if (st.empty()) left[j] = 0;
			else left[j] = st.top()+1;
			st.push(j);
		}
		while(!st.empty()) st.pop();
		for (int j = m-1; j >= 0; j--) {
			while (!st.empty() && arr[st.top()] >= arr[j]) st.pop();
			if (st.empty()) right[j] = m-1;
			else right[j] = st.top()-1;
			st.push(j);
		}
		for (int j = 0; j < m; j++) kq = max(kq, (right[j]-left[j]+1)*arr[j]);
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
