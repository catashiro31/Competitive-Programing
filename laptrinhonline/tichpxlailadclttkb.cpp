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
	vector<long> a(n);
	map<long,int> vt;
	for (long &x : a) {
		cin >> x;
		vt[x] = -1;
	}
	vector<int> l(n);
	int pos = -1;
	for (int i = 0; i < n; i++) {
		l[i] = i - max(vt[a[i]],pos);
		if (vt[a[i]] != -1) pos = max(pos,vt[a[i]]);
		vt[a[i]] = i;
	}
//	for (int x : l) cout << x << " ";
	cout << *max_element(l.begin(),l.end());
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
// 	freopen("input.txt","r",stdin);
	solve();
}
