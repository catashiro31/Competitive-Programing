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
#define ppf pop_front
#define psf push_front
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 1;
const string NoF = "Name_of_File";
    
void solve() {
    deque<int> qu1, qu2;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        qu1.push_back(x);
    }
    int kq = 0;
    while(!qu1.empty()) {
        if (!qu2.empty()) {
            qu2.psb(qu1.front());
            qu1.ppf();
        } else if (qu2.front() > qu1.back() && qu1.front() > qu1.back()) {
            if (qu2.front() < qu1.front()) {
                qu1.psb(qu2.front());
                qu2.ppf();
            } else if (qu2.front() > qu1.front()) {
                qu1.psb(qu1.front());
                qu1.ppf();
            }
        } else if (qu1.front() > qu1.back() && qu1.front() > qu1.back()) {
            if (qu1.back() < qu2.back()) qu2.psb(qu1.front());
            else if (qu1.back() > qu2.back()) qu1.psb(qu1.front());
            qu1.ppf();
        } else if (qu1.front() > qu1.back() || qu2.front() > qu1.back()) {
            if (qu1.front() > qu1.back() && qu2.front() > qu1.back()) {
                if (qu1.front() > qu2.front()) {
                    qu1.psb(qu1.front());
                    qu1.ppf();
                } else if (qu1.front() < qu2.front()) {
                    qu1.psb(qu2.front());
                    qu2.ppf();
                }
            } else if (qu1.front() >= qu1.back()) {
                qu1.psb(qu2.front());
                qu2.ppf();
            } else {
                qu1.psb(qu1.front());
                qu1.ppf();
            }
        } else if (qu1.front() > qu2.back() || qu1.front() > qu1.back()) {
            if (qu1.front() > qu2.back() && qu1.front() > qu1.back()) {
                if (qu1.back() < qu2.back()) {
                    qu1.psb(qu1.front());
                    qu1.ppf();
                } else if (qu1.back() > qu2.back()) {
                    qu2.psb(qu1.front());
                    qu1.ppf();
                }
            } else if (qu1.front() < qu1.back()) {
                qu2.psb(qu1.front());
                qu1.ppf();
            } else if (qu1.front() < qu2.back()) {
                qu1.psb(qu1.front());
                qu1.ppf();
            }
        } else {
            if (qu1.front() < qu2.front()){
                qu1.psb(qu1.front());
                qu1.ppf();
            } else if (qu1.front() > qu2.front()) {
                qu1.psb(qu2.front());
                qu2.ppf();
            }
        }
        kq++;
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