#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl "\n"
#define int long long

const int MAXN = 101;

struct Fenwick3D {
    int n;
    vector<vector<vector<int>>> tree;

    Fenwick3D(int size) {
        n = size;
        tree.resize(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));
    }

    void update(int i, int j, int k, int delta) {
        for(int x = i; x <= n; x += (x & -x)) {
            for(int y = j; y <= n; y += (y & -y)) {
                for(int z = k; z <= n; z += (z & -z)) {
                    tree[x][y][z] += delta;
                }
            }
        }
    }

    int query(int i, int j, int k) {
        int res = 0;
        for(int x = i; x > 0; x -= (x & -x)) {
            for(int y = j; y > 0; y -= (y & -y)) {
                for(int z = k; z > 0; z -= (z & -z)) {
                    res += tree[x][y][z];
                }
            }
        }
        return res;
    }

    int query(int x1, int y1, int z1, int x2, int y2, int z2) {
        return query(x2, y2, z2) 
             - query(x1 - 1, y2, z2) 
             - query(x2, y1 - 1, z2) 
             - query(x2, y2, z1 - 1) 
             + query(x1 - 1, y1 - 1, z2) 
             + query(x1 - 1, y2, z1 - 1) 
             + query(x2, y1 - 1, z1 - 1) 
             - query(x1 - 1, y1 - 1, z1 - 1);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    Fenwick3D fenwick(n);
    vector<vector<vector<int>>> val(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0))); // lưu giá trị hiện tại

    while(m--) {
        string s;
        cin >> s;

        if(s == "UPDATE") {
            int x, y, z, W;
            cin >> x >> y >> z >> W;

            // Tính delta
            int delta = W - val[x][y][z];
            val[x][y][z] = W;
            fenwick.update(x, y, z, delta);
        } 
        else if(s == "QUERY") {
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            cout << fenwick.query(x1, y1, z1, x2, y2, z2) << endl;
        }
    }
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}