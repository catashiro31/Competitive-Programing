#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000009
using ll = long long;
using namespace std;

struct Matrix {
    int r, c;
    vector<vector<ll>> d;
    Matrix(int rows, int cols) : r(rows), c(cols), d(r, vector<ll>(c, 0)) {}

    friend Matrix operator*(Matrix a, Matrix b) {
        Matrix kq(a.r, b.c);
        for (int i = 0; i < a.r; i++) {
            for (int j = 0; j < b.c; j++) {
                for (int k = 0; k < a.c; k++) {
                    kq.d[i][j] = (kq.d[i][j] + a.d[i][k] * b.d[k][j]) % mod;
                }
            }
        }
        return kq;
    }

    static Matrix identity(ll n) {
        Matrix dv(n, n);
        for (int i = 0; i < n; ++i) dv.d[i][i] = 1;
        return dv;
    }

    Matrix Pow(ll exp) {
        Matrix base = *this;
        Matrix ans = identity(r);
        while (exp) {
            if (exp & 1) ans = ans * base;
            base = base * base;
            exp >>= 1;
        }
        return ans;
    }

    void print() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) cout << d[i][j] << " ";
            cout << endl;
        }
    }
};

void solve() {
    ll n; cin >> n;

    Matrix tmp(2, 2);
    tmp.d = {{1, 1}, {1, 0}};
    tmp = tmp.Pow(n);
    
    Matrix f(2,1);
    f.d = {{1},{1}};
    
    Matrix s = tmp * f;
    cout << (s.d[0][0] - 1 + mod) % mod << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}