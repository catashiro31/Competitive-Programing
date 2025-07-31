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
	long x; cin >> x;
	vector<long> p(n);
	for (long &vl : p) cin >> vl;
	sort(p.begin(),p.end());
	int i = 0, j = n-1;
	int kq = 0;
	while (i <= j) {
		kq++;
		long value = x - p[i];
		while (j > i && p[j] > value) j--, kq++;
		if (j > i) j--;
		i++;
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}