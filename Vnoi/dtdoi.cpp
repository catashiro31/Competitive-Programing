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
	int n; cin >> n;
	long s; cin >> s;
	int coins[n];
	int cmax = INT_MIN;
	rep(i,n) {
		cin >> coins[i];
		cmax = max(cmax,coins[i]);
	}
	long add= 0;
	if (s >= 1000) { 
		add = (s-1000)/cmax;
		s -= add*cmax;
	}
	vl dp(s+1,INF); dp[0] = 0;
	rep(i,n) fo(j,0,s-coins[i]) {
		if (dp[j] != INF) dp[j+coins[i]] = min(dp[j+coins[i]],dp[j]+1);
	}
	cout << dp[s] + add;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}