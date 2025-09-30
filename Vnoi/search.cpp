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
#define endl '\n'
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 1;
const string NoF = "Name_of_File";

void solve() {
    int m, n, p; cin >> m >> n >> p;
    vector<int> a(m), c(p);
    for (int &x : a) cin >> x;

    // neg dùng như một "set"
    unordered_map<int,int> neg; neg.reserve(n*2+1);
    for (int i = 0; i < n; i++) { int x; cin >> x; neg[x] = 1; }

    for (int &x : c) cin >> x;

    // -------- Tối ưu: chỉ đếm những giá trị cần từ a ----------
    // need[v] = số lần cần v trong a
    unordered_map<int,int> need; need.reserve(m*2+1);
    for (int x : a) ++need[x];

    // have[v] = số lần đã có v trong đoạn hiện tại (giữa hai mốc neg)
    unordered_map<int,int> have; have.reserve(need.size()*2+1);
    vector<int> touched; touched.reserve(need.size()); // các khóa đã đụng để reset nhanh

    int needKinds = (int)need.size();   // số loại khác nhau cần có
    int satisfied = 0;                   // số loại đã đạt đủ
    int kq = 0, l = 0;

    // Giữ nguyên hai vector này để "giữa nguyên tên biến" như yêu cầu,
    // nhưng không cần dùng trong bản tối ưu:
    vector<int> lprefix(m,0), rprefix(m,0);

    auto reset_block = [&](){
        // reset cục bộ chỉ những khóa đã chạm
        for (int v : touched) have[v] = 0;
        touched.clear();
        satisfied = 0;
    };

    for (int i = 0; i < p; ++i) {
        int x = c[i];
        if (neg.count(x)) {
            // đóng đoạn [l..i-1]
            if (satisfied == needKinds) kq = max(kq, i - l);
            // mở đoạn mới
            reset_block();
            l = i + 1;
        } else {
            auto it = need.find(x);
            if (it != need.end()) {
                int needX = it->second;
                int &hv = have[x];
                if (hv == 0) touched.push_back(x);  // lần đầu đụng khóa này trong đoạn
                if (hv < needX) {
                    ++hv;
                    if (hv == needX) ++satisfied;
                }
            }
        }
    }
    // đoạn đuôi [l..p-1]
    if (satisfied == needKinds) kq = max(kq, p - l);

    cout << kq;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) solve();
}