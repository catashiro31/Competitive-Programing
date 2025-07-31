#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	vector<int> arr(n);
	for(int &x : arr) cin >> x;
	vector<int> dp(n,1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) dp[i] = max(dp[i],dp[j]+1);
		}
	}
	cout << *max_element(dp.begin(),dp.end());
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
