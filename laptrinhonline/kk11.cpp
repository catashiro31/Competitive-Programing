#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> R, G, B;
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') R.push_back(i);
        else if (s[i] == 'G') G.push_back(i);
        else B.push_back(i);
    }
	vector<int> sl(1e4+1,0);
	for (int x : B) sl[x] ++;
    ll kq = 0;

    for (int r : R) {
        for (int g : G) {
            int d = abs(g-r);
            int invalid = 0;
            // k = g + d
            if (g+d <= 1e4 && sl[g + d]) invalid++;
            // k = g - d
            if (g-d >= 0 && sl[g-d]) invalid++;
            // k = r + d
            if (r+d <= 1e4 && sl[r + d]) invalid++;
            // k = r - d
            if (r-d >= 0 && sl[r-d]) invalid++;
            // 2b = g + r
            if ((g + r) % 2 == 0) {
                int mid = (g + r) / 2;
                if (mid <= 1e4 && sl[mid]) invalid++;
            }
            kq += B.size() - invalid;
        }
    }
    cout << kq;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
