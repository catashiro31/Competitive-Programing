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
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 1;
const string NoF = "Name_of_File";
    
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    sort(all(a));
    sort(all(b));
    int kq = 1;
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (a[i] <= b[j]) {
            while(j < n && b[j] <= a[i]) j++;
            if (j == n) kq--;
            else {
                while (i < n && a[i] <= b[j]) i++;
                j++;
                if (i < n && j < n) kq++;
            }
        } else {
            while(i < n && a[i] <= b[j]) i++;
            if (i == n) kq--;
            else {
                while (j < n && b[j] <= a[i]) j++;
                i++;
                if (i < n && j < n) kq++;
            }
        }
    }
    cout << kq;
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