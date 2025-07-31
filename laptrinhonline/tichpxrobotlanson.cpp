#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> sl(m+1,0);
	while (n--) {
		int a, b; cin >> a >> b;
		sl[a]++, sl[b]--;
	}
	int kq = 0;
	for (int i = 0; i <= m; i++) {
		if (i > 0) sl[i] += sl[i-1];
		if (sl[i] >= k) kq++;
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
