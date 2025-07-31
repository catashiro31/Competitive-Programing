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
OST<pair<int,int>> ost;
map<int,pair<int,int>> mp;
void Turn_on(int id, int x, int y) {
    ost.insert({pow(x,2)+pow(y,2),id});
    mp[id] = {x,y};
}
void Turn_off(int id) {
    auto [x,y] = mp[id];
    auto it = ost.find({pow(x,2)+pow(y,2),id});
    ost.erase(it);
    mp[id] = {0,0};
}
void update_location(int id, int x, int y) {
    auto [u,v] = mp[id];
    auto it = ost.find({pow(u,2)+pow(v,2),id});
    ost.erase(it);
    mp[id] = {x,y};
    ost.insert({pow(x,2)+pow(y,2),id});
}
int get_min_distance(int x, int y) {
    int kc = pow(x,2)+pow(y,2);
    auto it = ost.lower_bound({kc,INT_MIN});
    if (it == ost.end()) {
        it--;
        int id_it = (*it).se;
        return abs(mp[id_it].fi-x)+abs(mp[id_it].se-y);
    } else if (it == ost.begin()) {
        int id_it = (*it).se;
        return abs(mp[id_it].fi-x)+abs(mp[id_it].se-y);
    } else {
        auto itprv = it;
        itprv--;
        int id_it = (*it).se, id_itprv = (*itprv).se;
        int tmp1 = abs(mp[id_it].fi-x)+abs(mp[id_it].se-y), tmp2 = abs(mp[id_itprv].fi-x)+abs(mp[id_itprv].se-y);
        if (tmp1 <= tmp2) return tmp1;
        else return tmp2;
    }
}
void solve() {
    while(true) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int id, x, y; cin >> id >> x >> y;
            Turn_on(id,x,y);
        } else if (cmd == 2) {
            int id; cin >> id;
            Turn_off(id);
        } else if (cmd == 3) {
            int id, x, y; cin >> id >> x >> y;
            update_location(id,x,y);
        } else if (cmd == 4) {
            int x, y; cin >> x >> y;
            cout << get_min_distance(x,y) << endl;
        } else break;
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen((NoF + ".in").c_str(), "r", stdin);
    freopen((NoF + ".out").c_str(), "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}