#include <bits/stdc++.h>
#define endl '\n'
#define INF 1e9
#define LINF 1e18
#define mod 1000000007
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
#define FOR(i,a,b) for(int i=(a); i <= (b); ++i)
#define FORD(i,a,b) for(int i=(b); i >= 0; --i)
#define REP(i,n) for(int i= 0; i < (n); ++i)
#define REPD(i,n) for(int i= (n)-1; i >= 0; --i)
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	vector<pii> arr(n);
	for (auto &x : arr) cin >> x.fi >> x.se;
	sort(all(arr));
	vi dp(n+1,0);
	FOR(i,1,n) REP(j,i) {
		int p = arr[i-1].fi, k = arr[i-1].se;
		if (j == 0) dp[i] = k-p;
		else {
			int b = arr[j-1].fi, e = arr[j-1].se;
			if (p >= e) dp[i] = max(dp[i],dp[j]+k-p);
		}
	}
	cout << *max_element(all(dp));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
