#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
ll GCD(ll a, ll b) {
	if (b == 0) return a;
	else return GCD(b,a%b);
}
void solve() {
	ll L, R, A, K; cin >> L >> R >> A >> K;
	K /= GCD(K,A);
	if (A % K == 0) cout << R - L + 1;
	else {
		R -= R % K;
		if (L % K) L = L + (K - L%K);
		cout << (R-L)/K + 1;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
