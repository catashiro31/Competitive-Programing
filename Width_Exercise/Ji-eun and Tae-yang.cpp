#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
void solve() {
    int t; cin >> t;
    for (int k = 0; k < t; k++) {
        long x; cin >> x;
        x *= 1e7;
        int n; cin >> n;
        vector<long> l(n);
        for (auto &x : l) cin >> x;
        sort(l.begin(),l.end());
        int i = 0, j = n-1;
        cout << "#" << k+1 << " ";
        while (i < j) {
            if (l[i] + l[j] == x) {
                cout << "yes " << l[i] << " " << l[j] << endl;
                break;
            } else if (l[i] + l[j] > x) j--;
            else i++;
        }
        if (i == j) cout << "danger" << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
//    freopen((NoF + ".in").c_str(),"r",stdin);
//    freopen((NoF + ".out").c_str(),"w",stdout);
    solve();
}