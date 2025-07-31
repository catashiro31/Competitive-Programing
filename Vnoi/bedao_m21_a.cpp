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
	while (t--) {
		int a, b, x, y; cin >> a >> b >> x >> y;
		int kq = b*y - a*x;
		int i = 0;
		while ((kq + i*(x+y) < 0) || (i*(x+y) + kq) % x != 0) i++;
		cout << i << " ";
		cout << (kq + i*(x+y))/x << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
