#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> thongso(n);
    for (auto &x : thongso) {
        cin >> x.first.first >> x.first.second >> x.second;
    }
    sort(thongso.begin(), thongso.end(), [](const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
        return a.first > b.first;
    });
    vector<long> dp(n, 0);
    for (int i = 0; i < n; i++) {
        dp[i] = thongso[i].second;
        for (int j = 0; j < i; j++) {
            if (thongso[j].first.first >= thongso[i].first.first && thongso[j].first.second >= thongso[i].first.second) {
                dp[i] = max(dp[i], dp[j] + thongso[i].second);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}

