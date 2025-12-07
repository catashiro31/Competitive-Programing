#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

int n, k, a[305];
int memo[305][305][155];
const int NEG_INF = -1e18;

int recurse(int l, int r, int cnt) {
    if (cnt == 0) return 0;
    if (l > r || (r - l + 1 < 2 * cnt)) {
        return NEG_INF;
    }
    if (memo[l][r][cnt] != -1) {
        return memo[l][r][cnt];
    }
    int res = max({
        abs(a[l]-a[r]) + recurse(l+1,r-1,cnt-1),
        abs(a[l]-a[l+1]) + recurse(l+2,r,cnt-1),
        abs(a[r]-a[r-1]) + recurse(l,r-2,cnt-1),
        recurse(l,r-1,cnt),
        recurse(l+1,r,cnt)
    });
	return memo[l][r][cnt] = res;	
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
    memset(memo, -1, sizeof(memo));
	cout << recurse(1,n,k);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}