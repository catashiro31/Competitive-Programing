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
	long x[n], y[n];
	long kq = 0;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n; i++) cin >> y[i];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			long tmp = pow(x[i]-x[j],2) + pow(y[i]-y[j],2);
			kq = max(kq,tmp);
		}
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	solve();
}
