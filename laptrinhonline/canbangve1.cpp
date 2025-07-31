#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<long> a(n);
		for (long &x : a) cin >> x;
		ll kq = 0;
		int status = 1;
		bool check = false;
		for (int i = 0; i < n; i++) {
			kq += abs(abs(a[i]) - 1);
			if (a[i] < 0) status = 1 - status;
			else if (a[i] == 0) check = true;
		}
		if (status) cout << kq << endl;
		else {
			if (check) cout << kq << endl;
			else cout << kq + 2 << endl;
		}
	}
	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
// 	freopen("input.txt","r",stdin);
	solve();
}
