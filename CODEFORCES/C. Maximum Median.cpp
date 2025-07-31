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
    ll k; 
    cin >> k;      
    vector<ll> a(n);
    ll l = LLONG_MAX, r = LLONG_MIN;
    for (ll &x : a) {
        cin >> x;
        l = min(x, l);      
        r = max(x + k, r);  
    }

    if (n == 1) {
        cout << a[0] + k << endl;
        return;
    }

    sort(a.begin(), a.end()); 
    ll kq = 0;

    while (l <= r) 	{
        ll m = l + (r - l) / 2;
        ll o = 0;

        for (int i = n / 2; i < n; i++) {
            if (m > a[i]) o += m - a[i];
            if (o > k) break; 
        }

        if (o > k) {
            r = m - 1; 
        } else {
            l = m + 1;
            kq = m;
        }
    }

    cout << kq << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}