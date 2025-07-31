#include <bits/stdc++.h>
using namespace std;
#define int long long

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
                chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    const int mod = 1e9 + 7;

    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int &a : A)
            cin >> a;

        unordered_map<int, int, custom_hash> dp;

        for (int a : A) {
            unordered_map<int, int, custom_hash> n_dp = dp;
            n_dp[a] = (n_dp[a] + 1) % mod;
            for (auto &p : dp) {
                int l = p.first;
                int cnt = p.second;
                int new_lcm = lcm(l, a);
                n_dp[new_lcm] = (n_dp[new_lcm] + cnt) % mod;
            }
            dp = move(n_dp);
        }

        int res = 0;
        for (auto &p : dp) {
            int l = p.first % mod;
            int cnt = p.second % mod;
            res = (res + l * cnt) % mod;
        }

        cout << res << '\n';
    }

    return 0;
}
