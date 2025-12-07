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

void solve() {
	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, s; cin >> n >> m >> s;
	vector<vector<int>> prefix(n+1,vector<int>(m+1,0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x; cin >> x;
			prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + x;
		}
	}
	
	int kq = 0;
	for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int sz = kq + 1;
            
            if (i < sz || j < sz) continue;

            int val = prefix[i][j] - prefix[i-sz][j] - prefix[i][j-sz] + prefix[i-sz][j-sz];

            if (val <= s) kq++;
        }
    }
    
    cout << kq * kq;
}
