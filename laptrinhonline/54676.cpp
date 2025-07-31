#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	vector<pair<int,int>> ls;
	map<int,int> c1;
	map<int,int> c2;
	while (n--) {
		int x, y; cin >> x >> y;
		ls.pb({x,y});
		c1[x+y-1]++;
		c2[x-y+1000]++;
	}
	int sl = 0;
	for (auto k : ls) {
		int x = k.fi, y = k.se;
		if (c1[x+y-1] > 1 || c2[x-y+1000] > 1) sl++; 
	}
	cout << sl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}