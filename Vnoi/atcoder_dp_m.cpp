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
#define fod(i,a,b) for(int i=(b); i >= 0; --i)
#define rep(i,n) for(int i= 0; i < (n); ++i)
#define repd(i,n) for(int i= (n)-1; i >= 0; --i)
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, k; cin >> n >> k;
	vi a(n);
	for(int &x : a) cin >> x;
	vector<vll> dp(n+1,vll(k+1,0));
	dp[0][0] = 1;
	fo(i,1,n) {
		vll prefix(k+1);
		prefix[0] = dp[i-1][0]%mod;
		fo(j,1,k) prefix[j] = (prefix[j-1] + dp[i-1][j])%mod;
		fo(j,0,k) {
			int st = j - a[i-1];
			if (st <= 0) dp[i][j] = prefix[j];
			else dp[i][j] = ((prefix[j] - prefix[st-1])%mod+mod)%mod;
		}
	}
	cout << dp[n][k];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
