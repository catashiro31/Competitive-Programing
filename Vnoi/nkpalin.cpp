#include <bits/stdc++.h>
#define endl '\n'
#define INF 1e9
#define LINF 1e18
#define mod 1000000007
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
#define FOR(i,a,b) for(int i=(a); i <= (b); ++i)
#define FORD(i,a,b) for(int i=(b); i >= 0; --i)
#define REP(i,n) for(int i= 0; i < (n); ++i)
#define REPD(i,n) for(int i= (n)-1; i >= 0; --i)
using ll = long long;
using namespace std;
void solve() {
    string xau; cin >> xau;
    int n = xau.length();
    vector<vi> dp(n, vi(n, 0));
    REP(i, n) REP(j, n - i) {
        if (i == 0) dp[j][j + i] = 1;
        else {
            if (xau[j] == xau[j + i]) dp[j][j + i] = dp[j + 1][j + i - 1] + 2;
            else dp[j][j + i] = max(dp[j][j + i - 1], dp[j + 1][j + i]);
        }
    }
    string res;
    int i = 0, j = n - 1;
    while (i <= j) {
        if (i+1 < n && dp[i][j] == dp[i+1][j]) ++i;
        else if (j-1 >= 0 && dp[i][j] == dp[i][j-1]) --j;
        else {
            res += xau[i];
            ++i; --j;
        }
    }
    cout << res;
    if (!res.empty() && dp[0][n-1] % 2) res.pop_back();
    reverse(res.begin(), res.end());
    cout << res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
