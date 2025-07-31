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
		long m, a, b, c; 
		cin >> m >> a >> b >> c;
		long kq = 0, tmp = 0;
		kq += min(m,a);
		tmp += m - min(m,a);
		kq += min(m,b);
		tmp += m - min(m,b);
		kq += min(tmp,c);
		cout << kq << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
