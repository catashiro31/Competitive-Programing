#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

int powup(int base, int exp, int p) {
	int res = 1 % p;
    base %= p;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % p;
        base = (base * base) % p;
        exp >>= 1;
    }
    return res;
}

void solve() {
	int n, k, m, p; cin >> n >> k >> m >> p;
	int z = (n-k-m+1) % p;
	int kq = (max(0LL,z)*powup(m,k-1,p)) % p;
	int tmp = 0;
	if (m*(m+1) % 6 == 0) tmp = ((m*(m+1)/6)%p*(m+2))%p;
	else tmp = (m*(((m+1)*(m+2)/6)%p))%p;
	int base = 1;
	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
