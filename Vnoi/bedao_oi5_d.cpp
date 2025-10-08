#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll BASE = 31; // base lớn, tùy chọn

int main() {
    freopen("vastr.inp", "r", stdin);
    freopen("vastr.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string str; cin >> str;

    // 1) power & prefix hash (1-based)
    vector<ll> pw(n+1, 1);
    for (int i = 1; i <= n; ++i) pw[i] = (pw[i-1] * BASE) % MOD;

    vector<ll> H(n+1, 0), HR(n+1, 0);
    for (int i = 0; i < n; ++i) {
        int val = (str[i] - 'a' + 1);
        H[i+1] = (H[i] * BASE + val) % MOD;
    }
    string rstr = str; reverse(rstr.begin(), rstr.end());
    for (int i = 0; i < n; ++i) {
        int val = (rstr[i] - 'a' + 1);
        HR[i+1] = (HR[i] * BASE + val) % MOD;
    }
    auto getH = [&](const vector<ll>& P, int l, int r) -> ll { // [l..r], 0-index
        int len = r - l + 1;
        ll res = (P[r+1] - (P[l] * pw[len]) % MOD + MOD) % MOD;
        return res;
    };

    long long kq = 0;

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = i; k < j; k++) {
                for (int h = j; h > k; h--) {
                    // X = S[i..k], Y = S[h..j]
                    int Lx=i, Rx=k, Ly=h, Ry=j;
                    int lenX = Rx-Lx+1, lenY = Ry-Ly+1;

                    // hash(T) = hash(X)*B^{|Y|} + hash(Y)
                    ll hX = getH(H, Lx, Rx);
                    ll hY = getH(H, Ly, Ry);
                    ll hT = ( (hX * pw[lenY]) % MOD + hY ) % MOD;

                    // rev(T) = rev(Y) + rev(X) (lấy trên chuỗi đảo)
                    // Y = S[Ly..Ry] -> trên rstr là [n-1-Ry .. n-1-Ly]
                    // X = S[Lx..Rx] -> trên rstr là [n-1-Rx .. n-1-Lx]
                    int lY = n-1-Ry, rY = n-1-Ly;
                    int lX = n-1-Rx, rX = n-1-Lx;
                    ll rYh = getH(HR, lY, rY);
                    ll rXh = getH(HR, lX, rX);
                    ll hRevT = ( (rYh * pw[lenX]) % MOD + rXh ) % MOD;

                    if (hT == hRevT) ++kq;
                }
            }
        }
    }

    cout << kq << '\n';
    return 0;
}
