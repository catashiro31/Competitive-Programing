#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

void solve() {
    int n; 
    cin >> n;

    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ll x; 
        cin >> x;
        prefix[i] = x + prefix[i - 1];
    }

    vector<bool> sang(n + 1, true);
    sang[0] = sang[1] = false; 
    for (int i = 2; i * i <= n; i++) {
        if (sang[i]) {
            for (int j = i * i; j <= n; j += i) {
                sang[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (sang[i]) primes.pb(i);
    }

    ll kq = LLONG_MIN;
    for (size_t i = 0; i < primes.size(); i++) {
        for (size_t j = i + 1; j < primes.size(); j++) {
            kq = max(kq, prefix[primes[j]] - prefix[primes[i] - 1]);
        }
    }

    cout << kq;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    solve();
}