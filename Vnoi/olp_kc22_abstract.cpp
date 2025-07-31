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
#define ford(i,a,b) for(int i=(b); i >= 0; --i)
#define rep(i,n) for(int i= 0; i < (n); ++i)
#define repd(i,n) for(int i= (n)-1; i >= 0; --i)
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vl> grid(n, vl(m));
    rep(i, n) rep(j, m) cin >> grid[i][j];
    vector<vector<bool>> c(n, vector<bool>(m, false));
    rep(i, n) {
        long max_val = -LINF;
        rep(j, m) {
            if (grid[i][j] && grid[i][j] > max_val) {
                max_val = grid[i][j];
                c[i][j] = true;
            }
        }
    }
    rep(i, n) {
        long max_val = -LINF;
        repd(j, m) {
            if (grid[i][j] && grid[i][j] > max_val) {
                max_val = grid[i][j];
                c[i][j] = true;
            }
        }
    }
    rep(j, m) {
        long max_val = -LINF;
        rep(i, n) {
            if (grid[i][j] && grid[i][j] > max_val) {
                max_val = grid[i][j];
                c[i][j] = true;
            }
        }
    }
    rep(j, m) {
        long max_val = -LINF;
        repd(i, n) {
            if (grid[i][j] && grid[i][j] > max_val) {
                max_val = grid[i][j];
                c[i][j] = true;
            }
        }
    }
    int result = 0;
    rep(i, n) rep(j, m) if (c[i][j]) result++;
    cout << result << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
