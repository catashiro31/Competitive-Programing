#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, K; cin >> n >> K;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	vector<bool> dp(K+1,0);
	for (int i = 1; i <= K; i++) {
		for (int x : a) {
			if (x <= i && !dp[i-x]) dp[i] = 1;
		}
	}
	cout << (dp[K] ? "First" : "Second");
}
