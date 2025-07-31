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
	vector<string> s(n);
	for (string &x : s) cin >> x;
	vector<int> sl(1e6+2,0);
	for (string x : s) {
		int tmp = 0;
		int k = x.length();
		for (int i = 0; i < min(k,5); i++) {
			tmp = tmp * 10 + x[i] - '0';
			if (tmp < 1e6+2) sl[tmp]++;
		} 
	}
	for (int i = 1; i < 1e6+2; i++) {
		if (sl[i] == 0) {
			cout << i;
			break;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
