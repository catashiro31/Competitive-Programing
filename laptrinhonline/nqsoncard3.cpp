#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	ll n; cin >> n;
	ll a = 1, b = n, d = 1;
	while (a != b) {
		ll sl = (b-a)/d+1;
		if (sl % 2) a+=d*2, d*= 2;
		else b-=d, d*=2;
	}
	cout << a;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}