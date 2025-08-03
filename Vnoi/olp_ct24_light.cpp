#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define psb push_back
#define ppb pop_back
#define endl '\n'
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MOD = 1e9 + 7;
const int MAXN = 555;
const string NoF = "Name_of_File";
const int STEP = 62;
const int dx[3] = {1, 0, -1};
const int dy[3] = {0, 1, -1};

int n, k;
vector<bool> blocked(MAXN * MAXN / 2, false);
bool ok[MAXN][MAXN];
long long mask[MAXN][MAXN][3];

bool inside(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= x;
}

void init(void) {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        blocked[x] = true;
    }
    int t = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) ok[i][j] = !blocked[++t];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int d = 0; d < 3; d++) {
                ll tmpmask = 0;
                for (int r = 0; r < STEP; r++) {
                    int x = i + dx[d] * r;
                    int y = j + dy[d] * r;
                    if (!inside(x,y)) break;
                    if (!ok[x][y]) continue;
                    tmpmask |= (1LL << r);
                }
                mask[i][j][d] = tmpmask;
            }
        }
    }
}
void process(void) {
    ll result = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int s = 1; i+s <= n; s++) {
                int x[3], y[3];
                x[0] = i; y[0] = j;

                x[1] = x[0] + dx[0] * s;
                y[1] = y[0] + dy[0] * s;

                x[2] = x[1] + dx[1] * s;
                y[2] = y[1] + dy[1] * s;
                int remp = s;
                while (remp > 0) {
                    ll tmpmask = (1LL << min(remp,STEP))- 1;
                    for (int d = 0; d < 3; d++) tmpmask &= mask[x[d]][y[d]][d];
                    result += __builtin_popcountll(tmpmask);
                    remp -= STEP;
                    for (int t = 0; t < 3; t++) {
                        x[t] += dx[t] * STEP;
                        y[t] += dy[t] * STEP;
                    }
                }
            }
        }
    }
    cout << result << endl;
}
void solve() {
    init();
    process();
}
    
int main() {
#ifndef ONLINE_JUDGE
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}