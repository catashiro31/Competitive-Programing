#include <bits/stdc++.h>
#define endl '\n'
#define INF 1e9
#define LINF 1e18
#define pii pair<int,int>
#define pli pair<long,int>
#define plli pair<ll,int>
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define sz(x) ((x).size())
#define vi vector<int>
#define vl vector<long>
#define vll vector<long long>
#define fo(i,a,b) for(int i=(a); i <= (b); ++i)
#define ford(i,a,b) for(int i=(b); i >= (a); --i)
#define rep(i,n) for(int i= 0; i < (n); ++i)
#define repd(i,n) for(int i= (n)-1; i >= 0; --i)
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, l; cin >> n >> l;
	vi w(n);
	for (int &x : w) cin >> x;
	sort(all(w));
	vector<pii> dp(n);
	dp[0] = {l-w[0],l-w[0]};
	fo(i,1,n-1) {
		if (dp[i-1].fi >= w[i]) dp[i].fi = dp[i-1].fi-w[i];
		else dp[i].fi = l-w[i];
		dp[i].se = max(dp[i-1].se,dp[i].fi);
	}
	cout << dp[n-1].se;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
