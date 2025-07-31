#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	vector<int> a_sort(n);
	a_sort = a; a_sort.push_back(0);
	sort(a_sort.begin(),a_sort.end());
	vector<long long> dp(k+1,0);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		int j = 0;
		while (a_sort[j] <= a[i]) {
			for (int q = k; q >= a_sort[j]; q--) {
				dp[q] = (dp[q]+dp[q-a_sort[j]])%mod; 
			}
		}
	}
	cout << dp[k];
}
