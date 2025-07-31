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
	vector<int> arr(n);
	for (int &x : arr) cin >> x;
	vector<bool> c(n+2,false);
	c[n+1] = true;
	int kq = 0;
	for (int i = 0; i < n; i++) {
		if (c[arr[i]+1]) kq++;
		c[arr[i]] = true;
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
