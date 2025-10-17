#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

#define sz(x) (int)(x).size()
#define fi first
#define se second

int timer;

void dfs(int u, int par, const vector<vector<int>> &adjList, vector<pair<int,int>> &euler) {
    euler[u].fi = timer++;
    for (int v : adjList[u]) {
        if (v != par) {
            dfs(v, u, adjList, euler);
        }
    }
    euler[u].se = timer - 1;
}

void updatev(vector<double> &BIT, int x, double val) {
    for (; x < sz(BIT); x += x & (-x)) {
        BIT[x] += val;
    }
}

double get_prefix_sum(const vector<double> &BIT, int x) {
    double res = 0;
    for (; x > 0; x -= x & (-x)) {
        res += BIT[x];
    }
    return res;
}

double get_range_sum(const vector<double> &BIT, int l, int r) {
    if (l > r) return 0.0;
    return get_prefix_sum(BIT, r) - get_prefix_sum(BIT, l - 1);
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<double> val(n + 1, 1.0);
    vector<pair<int,int>> euler(n + 1);
    
    vector<double> BIT(n + 5, 0.0);
    
    timer = 1;
    dfs(1, 0, adjList, euler);

    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            
            double diff = log10(y) - log10(val[x]);
            
            updatev(BIT, euler[x].fi, diff);
            
            val[x] = y;

        } else {
            int x, y;
            cin >> x >> y;
            
            double subtree_x_log_sum = get_range_sum(BIT, euler[x].fi, euler[x].se);
            double subtree_y_log_sum = get_range_sum(BIT, euler[y].fi, euler[y].se);
            double log_ratio = subtree_x_log_sum - subtree_y_log_sum;

            if (log_ratio >= 9) {
                cout << fixed << setprecision(10) << 1e9 << endl;
            } else {
                cout << fixed << setprecision(10) << pow(10, log_ratio) << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}