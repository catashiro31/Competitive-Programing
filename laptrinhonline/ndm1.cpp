#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;

        int x = a.length(), y = b.length();
        char last_a = a[x - 1], last_b = b[y - 1];

        if (last_a == last_b) {
            if (last_a == 'M') {
                cout << "=" << endl;
            } else if (last_a == 'S') {
                if (x < y) cout << ">" << endl;
                else if (x > y) cout << "<" << endl;
                else cout << "=" << endl;
            } else if (last_a == 'L') {
                if (x > y) cout << ">" << endl;
                else if (x < y) cout << "<" << endl;
                else cout << "=" << endl;
            }
        } else {
            if (last_a == 'S') cout << "<" << endl;
            else if (last_a == 'M') {
                if (last_b == 'S') cout << ">" << endl;
                else cout << "<" << endl;
            } else if (last_a == 'L') cout << ">" << endl;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}