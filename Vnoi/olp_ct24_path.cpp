#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
ll modulo(ll base, ll exp) {
	ll kq = 1;
	while (exp/=2) {
		if (exp % 2) kq = (kq*base) % mod;
		base = (base*base) % mod;
	}
	return kq;
}
void solve() {
	int m, n, k; cin >> m >> n >> k;
	vector<vector<ll>> grid(1e3,vector<ll> (1e3,0));
	for (int i = 0; i < k; i++) {
		int x,y; cin >> x >> y;
		grid[--x][--y] = -1;
	}
	
	for (int x = 0; x < 1e3; x++) {
		for (int y = 0; y < 1e3; y++) {
			if (grid[x][y] == -1) {
				grid[x][y] = 0;
				continue;
			}
			if (x == 0 && y == 0) grid[x][y] = 1;
			else if (x == 0) grid[x][y] = grid[x][y-1] % mod;
			else if (y == 0) grid[x][y] = grid[x-1][y] % mod;
			else grid[x][y] = (grid[x][y-1] + grid[x-1][y]) % mod;
		}
	} 
	
	int px = m-1, py = n-1;
	ll kq = 0;
	if (px >= 1e3 && py < 1e3) {
		for (int y = 0; y <= py; y++) {
			ll tmp = grid[1e3-1][y];
			ll nub1 = 1 , nub2 = 1, nub3 = 1;
			for (int i = 2; i <= px-1e3+py-y; i++) {
				nub1 *= i; nub1 %= mod;
				if (nub2 <= px-1e3) nub2 *= i; nub2 %= mod;
				if (nub3 <= py-y) nub3 *= i; nub3 %= mod;
			}
			nub2 = modulo(nub2,mod-2);
			nub3 = modulo(nub3,mod-2);
			tmp = (tmp * nub1)%mod;
			tmp = (tmp * nub2)%mod;
			tmp = (tmp * nub3)%mod;
			kq =(kq+tmp)%mod;
		}
	} else if (px < 1e3 && py >= 1e3) {
		for (int x = 0; x <= px; x++) {
			ll tmp = grid[x][1e3-1];
			ll nub1 = 1, nub2 = 1, nub3 = 1;
			for (int i = 1; i <= px-x+py-1e3; i++) {
				nub1 *= i; nub1 %= mod;
				if (nub2 <= px-x) nub2 *= i; nub2 %= mod;
				if (nub3 <= py-1e3) nub3 *= i; nub3 %= mod;
			}
			nub2 = modulo(nub2,mod-2);
			nub3 = modulo(nub3,mod-2);
			tmp = (tmp * nub1)%mod;
			tmp = (tmp * nub2)%mod;
			tmp = (tmp * nub3)%mod;
			kq = (kq+tmp)%mod;
		}	
	} else if (px < 1e3 && py < 1e3) kq = grid[px][py];
	else {
		for (int x = 0; x < 1e3; x++) {
			ll tmp = grid[x][1e3-1];
			ll nub1 = 1, nub2 = 1, nub3 = 1;
			for (int i = 1; i <= px-x+py-1e3; i++) {
				nub1 *= i; nub1%=mod;
				if (nub2 <= px-x) nub2 *= i; nub2%=mod;
				if (nub3 <= py-1e3) nub3 *= i; nub3%mod;
			}
			nub2 = modulo(nub2,mod-2);
			nub3 = modulo(nub3,mod-2);
			tmp = (tmp * nub1)%mod;
			tmp = (tmp * nub2)%mod;
			tmp = (tmp * nub3)%mod;
			kq = (kq+tmp)%mod;
		}
		kq = (kq*2)%mod;
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
