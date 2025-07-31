#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_N = 100;
const int MAX_C = 100000 + 5;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int W, H;
    cin >> N >> W >> H;

    vector<pair<int, int>> items(N);
    vector<int> hand_items;

    int tol = 0;
    for (int i = 0; i < N; ++i) {
        int wi;
        int ci;
        cin >> wi >> ci;
        items[i] = {wi, ci};
        tol += ci;
        if (wi <= H) {
            hand_items.push_back(i);
        }
    }

    const int INF = 1e18;
    vector<int> dp(tol + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
        int wi = items[i].first;
        int ci = items[i].second;
        for (int v = tol; v >= ci; --v) {
            dp[v] = min(dp[v], dp[v - ci] + wi);
        }
    }

    int max_value = 0;
    for (int v = tol; v >= 0; --v) {
        if (dp[v] <= W) {
            max_value = v;
            break;
        }
    }

    for (int idx : hand_items) {
        vector<int> dp_no_i(tol + 1, INF);
        dp_no_i[0] = 0;

        for (int i = 0; i < N; ++i) {
            if (i == idx) continue; 
            int wi = items[i].first;
            int ci = items[i].second;
            for (int v = tol; v >= ci; --v) {
                dp_no_i[v] = min(dp_no_i[v], dp_no_i[v - ci] + wi);
            }
        }

        int mval_noi = 0;
        for (int v = tol; v >= 0; --v) {
            if (dp_no_i[v] <= W) {
                mval_noi = v;
                break;
            }
        }

        int tmp = mval_noi + items[idx].second;
        max_value = max(max_value, tmp);
    }

    cout << max_value << "\n";

    return 0;
}
