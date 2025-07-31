#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
void in(string &kq, int n, char val) {
	for (int i = 0; i < n; i++) kq += val;
}
void solve() {
	int t; cin >> t;
	while (t--) {
		string kq = "";
		int n, m, k; cin >> n >> m >> k;
		if (abs(n-m) > k || k > max(n,m)) cout << -1 << endl;
		else {
			bool c = false;
			int p = -1;
			while (true) {
				if (!c) {
					if (n >= m) {
						in(kq,k,'0');
						n -= k, p = 1;
					} else {
						in(kq,k,'1');
						m -= k, p = 0;
					}
					c = true;
				} else {
					if (p) m--, kq += '1';
					else n--, kq += '0';
					p = 1 - p;		
				}
				if (!m || !n) {
					in(kq,m+n,char(p+'0'));
					break;
				}
			}
			cout << kq << endl;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
