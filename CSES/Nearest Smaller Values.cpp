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
	long a[n];
	for (long &x : a) cin >> x;
	stack<long> st;
	int kq[n];
	for (int i = 0; i < n; i++) {
		while(!st.empty() && a[i] <= a[st.top()]) st.pop();
		if (st.empty()) kq[i] = 0;
		else kq[i] = st.top()+1;
		st.push(i);
	}
	for (int x : kq) cout << x << " ";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
