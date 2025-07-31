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
	int X; cin >> X;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	sort(a.begin(),a.end());
	int sl = 0, i = 0;
	while (X >= a[i] && i < n) {
		X -= a[i];
		i++;
		sl++;
	}
	cout << sl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
