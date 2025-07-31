#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int k; cin >> k;
	vector<ll> w;
	w.pb(1);
	int i = 0;
	while(true)	{
		if (w.size() >= k) break;
		if (w[i] % 2 == 1) w.pb(2LL*w[i]);
		if (w[i+1] == w[i]+1) w.pb(2LL*w[i]+1);
		i++;
	}
	cout << w[k-1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}