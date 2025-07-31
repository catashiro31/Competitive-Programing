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
	long x, y; cin >> x >> y;
	if (x == y) cout << 0 << " " << 0;
	else {
		long i = 1, kq = 0;
		long p = x;
		while (true) {
			long tmp = pow(-1,i)*pow(2,i-1);
			if (p < y && y <= x+tmp) {
				kq += y-p;
				break;
			}
			if (y < p && x+tmp <= y) {
				kq += p-y;
				break;
			}
			kq += abs(p-x-tmp);
			p = x+tmp;
			i++;
		}
		cout << i << " " << kq;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
