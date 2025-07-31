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
#define fod(i,a,b) for(int i=(b); i >= 0; --i)
#define rep(i,n) for(int i= 0; i < (n); ++i)
#define repd(i,n) for(int i= (n)-1; i >= 0; --i)
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int s, k, n; cin >> s >> k >> n;
	vector<vi> a(n,vi(k));
	rep(i,n) rep(j,k) cin >> a[i][j];
	int dp[n][k+1][s+1];
	int trace_j[n][k+1][s+1];
    int trace_q[n][k+1][s+1];
	memset(dp, 0, sizeof(dp));
	rep(i,n) dp[i][0][0] = 1;
	fo(i,1,k) rep(j,n) fo(q,0,s) {
		if (q >= a[j][i-1]) {
			rep(p,n) {
				if (i == 1 || a[p][i-2] <= a[j][i-1]) 
					if (dp[p][i-1][q-a[j][i-1]]) {
						dp[j][i][q] = 1;
						trace_j[j][i][q] = p;
                        trace_q[j][i][q] = q - a[j][i-1];
					}
			}
		}
	}
	int end_j = -1;
    for (int j = 0; j < n; ++j) {
        if (dp[j][k][s]) {
            end_j = j;
            break;
        }
    }

    if (end_j == -1) {
        cout << "NO" << endl;
        return;
    }

    // Truy v?t
    vector<int> result(k);
    int current_j = end_j, current_q = s;

    for (int i = k; i >= 1; --i) {
        result[i-1] = a[current_j][i-1];
        int prev_j = trace_j[current_j][i][current_q];
        int prev_q = trace_q[current_j][i][current_q];
        current_j = prev_j;
        current_q = prev_q;
    }

    // In k?t qu?
    cout << "YES" << endl;
    for (int i = 0; i < k; ++i) {
        cout << result[i] << " ";
    }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
