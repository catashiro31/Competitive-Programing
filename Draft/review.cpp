#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 300005

void solve() {
	int n; cin >> n;
	vector<int> arr(n);
	for (int &x : arr) cin >> x;
	stack<pair<int,int>> st;
	int kq = 0;
	for (int i = 0; i < n; i++) {
		if (!st.empty() && arr[st.top().fi] == arr[i]) {
			auto [v,sl] = st.top(); st.pop();
			st.push({v,sl+1});	
			continue;
		}
		while(!st.empty() && arr[st.top().fi] < arr[i]) {
			auto [v,sl] = st.top();
			kq += sl;
			st.pop();
		}
		if (!st.empty()) st.push({i,1});
		else st.push({i,2});
	}
	while(!st.empty()) st.pop();
	for (int i = n-1; i >= 0; i--) {
		if (!st.empty() && arr[st.top().fi] == arr[i]) {
			auto [v,sl] = st.top(); st.pop();
			st.push({v,sl+1});	
			continue;
		}
		while(!st.empty() && arr[st.top().fi] < arr[i]) {
			auto [v,sl] = st.top();
			kq += sl;
			st.pop();
		}
		if (!st.empty()) st.push({i,1});
		else st.push({i,1});
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
