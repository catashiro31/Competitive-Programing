#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> a(n);
	for (int &vl : a) cin >> vl;
	vector<int> dp(n,1);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) dp[i] = max(dp[i],dp[j]+1); 
		}
	}
	cout << *max_element(dp.begin(),dp.end());
}
