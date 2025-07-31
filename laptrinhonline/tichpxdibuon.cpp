#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
	vector<long> dp(m+1,0);
	for (int i = 0; i < n; i++) {
		for (int j = m; j >= 0; j--) {
			if (j < a[i]) continue;
			else dp[j] = max(dp[j],dp[j-a[i]] + a[i]*b[i]/100);
		}
	}
	cout << *max_element(dp.begin(),dp.end());
}
int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
