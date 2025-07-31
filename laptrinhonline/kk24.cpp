#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;

void solve() {
    ll n;
    cin >> n;

    ll m, k;
    cin >> m >> k;

    vector<ll> st(m);
    for (ll &x : st) cin >> x;

    vector<ll> pos(k);
    for (ll &x : pos) cin >> x;

    ll cmin = LLONG_MAX, cmax = LLONG_MIN;
    ll sum = 0;

    // Tính giá trị cmax và cmin
    for (ll x : st) {
        if (x == 1) {
            sum += 1;
            cmax = max(cmax, sum);
        } else {
            sum -= 1;
            cmin = min(cmin, sum);
        }
    }
    ll kc = cmax - cmin + 1;

    ll kq = 0;

    // Xử lý tính toán kq
    for (ll i = 0; i < k; i++) {
        if (i == 0) {
            kq += max(0LL, pos[i] - kc);
        } else {
            kq += max(0LL, pos[i] - pos[i - 1] - kc);
        }
    }

    // Xử lý đoạn cuối của chuỗi
    if (k > 0) {
        kq += max(0LL, n + 1 - pos[k - 1] - kc);
    } else {
        kq = max(0LL, n - kc); // Xử lý trường hợp k = 0
    }

    cout << kq << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}