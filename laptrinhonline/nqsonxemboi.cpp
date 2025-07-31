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
    string s1, s2; cin >> s1 >> s2;
    if (s1 == "Moc") {
        if (s2 == "Hoa") cout << "Moc sinh Hoa";
        else if (s2 == "Tho") cout << "Moc khac Tho";
        else if (s2 == "Kim") cout << "Kim khac Moc";
        else if (s2 == "Thuy") cout << "Thuy sinh Moc";
    } else if (s1 == "Thuy") {
        if (s2 == "Moc") cout << "Thuy sinh Moc";
        else if (s2 == "Kim") cout << "Kim sinh Thuy";
        else if (s2 == "Hoa") cout << "Thuy khac Hoa";
        else if (s2 == "Tho") cout << "Tho khac Thuy";
    } else if (s1 == "Hoa") {
        if (s2 == "Tho") cout << "Hoa sinh Tho";
        else if (s2 == "Moc") cout << "Moc sinh Hoa";
        else if (s2 == "Kim") cout << "Hoa khac Kim";
        else if (s2 == "Thuy") cout << "Thuy khac Hoa";
    } else if (s1 == "Tho") {
        if (s2 == "Kim") cout << "Tho sinh Kim";
        else if (s2 == "Hoa") cout << "Hoa sinh Tho";
        else if (s2 == "Moc") cout << "Moc khac Tho";
        else if (s2 == "Thuy") cout << "Tho khac Thuy";
    } else if (s1 == "Kim") {
        if (s2 == "Hoa") cout << "Hoa khac Kim";
        else if (s2 == "Thuy") cout << "Kim sinh Thuy";
        else if (s2 == "Moc") cout << "Kim khac Moc";
        else if (s2 == "Tho") cout << "Tho sinh Kim";
    }
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