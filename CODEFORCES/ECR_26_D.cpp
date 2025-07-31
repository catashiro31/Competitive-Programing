#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const int MAX_SL = 12000;
pair<int,int> Two_Five(ll x) {
	pair<int,int> ans = {0,0};
	while (x % 2 == 0) ans.fi++, x /= 2;
	while (x % 5 == 0) ans.se++, x /= 5;
	return ans;
}
void solve() {
	int N, K; cin >> N >> K;
	
	vector<pair<int,int>> sl(N);
	for (int i = 0; i < N; i++) {
		ll x; cin >> x;
		sl[i] = Two_Five(x); 
	}
	
	vector<vector<int>> dp(K+1,vector<int>(MAX_SL+1,INT_MIN));
	dp[0][0] = 0;
	for (int i = 0; i < N; i++) {
		for (int k = K; k > 0; k--) {
			for (int j = MAX_SL; j >= sl[i].fi; j--) {
				if (dp[k-1][j-sl[i].fi] == INT_MIN) continue;
				dp[k][j] = max(dp[k][j],dp[k-1][j-sl[i].fi]+sl[i].se);
			}
		}
	}
	int kq = 0;
	for (int i = 0; i <= MAX_SL; i++) {
		kq = max(kq,min(i,dp[K][i]));
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	solve();
}
