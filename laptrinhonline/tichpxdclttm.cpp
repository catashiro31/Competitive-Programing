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
	vector<int> a(n);
	for (int &x : a) cin >> x;
	vector<long> prefix(n);
	for (int i = 0; i < n; i++) {
		if (!i) prefix[i] = a[i];
		else prefix[i] = prefix[i-1] + a[i];
	}
	multiset<long> ms; ms.insert(0);
	long kq = LONG_MIN;
	for (int i = 0; i < n; i++) {
		kq = max(kq,prefix[i] - *ms.begin());
		ms.insert(prefix[i]);
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
