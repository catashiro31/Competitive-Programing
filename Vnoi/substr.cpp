#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	string a, b; cin >> a >> b;
	int n = a.length(), m = b.length();
	if (n >= m) {
		string s = "";
		vector<int> kq;
		for (int i = n-1; i >= 0; i--) {
			s = a[i] + s;
			if (s.length() > m) s.pop_back();
			if (s == b) kq.pb(i-m+3);
		}
		reverse(kq.begin(),kq.end());
		for (int x : kq) cout << x << " ";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
