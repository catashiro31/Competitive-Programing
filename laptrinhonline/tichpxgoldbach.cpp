#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	vector<bool> c(n+1,true);
	c[0] = false, c[1] = false;
	for (int i = 2; i*i <= n; i++) {
		if (!c[i]) continue;
		for (int j = i*i; j <= n; j += i) c[j] = false;
	}
	vector<int> snt;
	for (int i = 0; i <= n; i++) if (c[i]) snt.pb(i);
	int kq = 0;
	for (int i = 0; i < snt.size() && snt[i] <= n/3; i++) {
		for (int j = i; j < snt.size() && snt[j] <= (n - snt[i])/2; j++) {
			if (c[n-snt[i]-snt[j]]) kq++;
		}
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
