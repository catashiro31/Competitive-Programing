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
	int n, q; cin >> n >> q;
	vector<int> sl(3,0);
	vector<int> kq(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		x--; sl[x]++;
		if (sl[0] == 2) sl[1]++, sl[0]-=2;
		if (sl[1] == 2) sl[2]++, sl[1]-=2;
		kq[i] = sl[0] + sl[1] + sl[2];
	}
	while (q--) {
		int i; cin >> i;
		i--;
		cout << kq[i] << " ";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
