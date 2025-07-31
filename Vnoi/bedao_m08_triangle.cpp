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
	vector<ll> f(101,1);
	for (int i = 3; i <= 100; i++) f[i] = f[i-1] + f[i-2];
	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		n = f[min(n,100LL)];
		if (n <= k) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
