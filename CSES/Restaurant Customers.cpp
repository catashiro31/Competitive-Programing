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
	vector<pair<long,int>> prefix;
	for (int i = 0; i < n; i++) {
		long a, b; cin >> a >> b;
		prefix.pb({a,1});
		prefix.pb({b,-1});
	}
	sort(prefix.begin(),prefix.end());
	int kq = INT_MIN, sum = 0;
	for (auto [u,v] : prefix) sum += v, kq = max(kq,sum);
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
