#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	string s; cin >> s;
	int n = s.length();
	vector<int> prefix(n+1,0);
	for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + s[i] - '0';
	vector<int> sl(3,0);
	int d = prefix[n]%3;
	ll kq = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = prefix[i]%3;
		kq += sl[(tmp-d+3)%3];
		sl[prefix[i]%3]++;
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
