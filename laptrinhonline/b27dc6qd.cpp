#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	string s; cin >> s;
	int n = s.length();
	vector<int> sl(9,0);
	sl[0] = 1;
	ll kq = 0;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += s[i] - '0';
		kq += sl[sum%9];
		kq %= mod;
		sl[sum%9]++;
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
// 	freopen("input.txt","r",stdin);
	solve();
}
