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
#define ford(i,a,b) for(int i=(b); i >= 0; --i)
#define rep(i,n) for(int i= 0; i < (n); ++i)
#define repd(i,n) for(int i= (n)-1; i >= 0; --i)
#define mod 2111992
using ll = long long;
using namespace std;
void solve() {
	int n, k; cin >> n >> k;
	vl dp(n+1,1);
	fo(i,1,n) dp[i] = (i > k ? dp[i-1]+dp[i-k-1]: dp[i-1]+1)%mod;
	cout << dp[n];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
