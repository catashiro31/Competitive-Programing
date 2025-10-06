#include <bits/stdc++.h>
using namespace std;

int n, k;
int ln[3011];
set<pair<int,int>> colored;

inline bool inside(int i, int j) {
    return (1 <= i && i <= n && 1 <= j && j <= ln[i]);
}

pair<int,int> norm(int a,int b,int c){
    return { c, b*2 - (a+b+c+n+1)%2 };
}

// Kiểm toàn bộ vùng tam giác NGỬA (đỉnh (i,j), cỡ t)
bool okUp(int i,int j,int t){
    for (int r = 0; r <= t-1; ++r) {
        int row = i - r;
        int L = j - r;           // center = j + r, span 2r
        int R = j + 3*r;
        for (int c = L; c <= R; ++c) {
            if (!inside(row,c) || colored.count({row,c})) return false;
        }
    }
    return true;
}

// Kiểm toàn bộ vùng tam giác ÚP (đỉnh (i,j), cỡ t)
bool okDown(int i,int j,int t){
    for (int r = 0; r <= t-1; ++r) {
        int row = i + r;
        int L = j - 3*r;         // center = j - r, span 2r
        int R = j + r;
        for (int c = L; c <= R; ++c) {
            if (!inside(row,c) || colored.count({row,c})) return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    // Hàng 1 rộng nhất, xuống dưới hẹp dần (giống DP của bạn)
    ln[n] = 1;
    for (int i = n-1; i >= 1; --i) ln[i] = ln[i+1] + 2;

    for (int z = 0; z < k; ++z) {
        int a,b,c; cin >> a >> b >> c;
        auto p = norm(a,b,c);
        if (inside(p.first, p.second)) colored.insert(p);
    }

    long long res = 0;

    // Duyệt mọi đỉnh (i,j), đếm mọi kích cỡ t
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= ln[i]; ++j) {
            if (colored.count({i,j})) continue;

            if (j & 1) {
                // tam giác NGỬA
                for (int t = 1; ; ++t) {
                    if (!okUp(i,j,t)) break;
                    ++res;
                }
            } else {
                // tam giác ÚP
                for (int t = 1; ; ++t) {
                    if (!okDown(i,j,t)) break;
                    ++res;
                }
            }
        }
    }

    cout << res << '\n';
    return 0;
}
