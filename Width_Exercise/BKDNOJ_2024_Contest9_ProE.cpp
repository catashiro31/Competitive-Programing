#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) (int)(x).size()
#define psb push_back
#define ppb pop_back
#define psf push_front
#define ppf pop_front
#define endl '\n'
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MAXN = 2e5+1;
const int MOD = 1e9+7;
const string NoF = "Name_of_File";

void solve() {
	ll n, k; cin >> n >> k;
	pair<ll,ll> mb[n+1];
	ll kq = 0;
	for (int i = 1; i <= n; i++) {
		ll a, b; cin >> a >> b;
		ll tmp = min(a/k,b/k);
		kq += 2*tmp;
		a -= k*tmp, b -= k*tmp;
		mb[i] = {a,b};
	}
	map<pair<ll,ll>,ll> dp[n+1];
	dp[0][{0,0}] = kq;
	for (int i = 1; i <= n; i++) {
		auto [a,b] = mb[i];
		if (a < k) {
			for (auto [x,v] : dp[i-1]) {
				auto [c,d] = x;
				for (int e = 0; e <= a; e++) {
					ll tmp = (e+b)/k;
					int f = a-e, h = (e+b)%k; 
					dp[i][{(f+c)%k,(h+d)%k}] = max(dp[i][{(f+c)%k,(h+d)%k}],v+tmp+(f+c)/k+(h+d)/k);
				}
			}
		} else {
			for (auto [x,v] : dp[i-1]) {
				auto [c,d] = x;
				for (int e = 0; e <= b; e++) {
					ll tmp = (e+a)/k;
					int h = b-e, f = (e+a)%k;
					dp[i][{(f+c)%k,(h+d)%k}] = max(dp[i][{(f+c)%k,(h+d)%k}],v+tmp+(f+c)/k+(h+d)/k);
				}
			}
		}
	}
	for (auto [x,v] : dp[n]) kq = max(kq,v);
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
