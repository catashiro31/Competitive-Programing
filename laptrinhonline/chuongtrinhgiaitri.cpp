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
	vector<pair<int,int>> arr;
	for (int i = 0; i < n; i++) {
		int s, t; cin >> s >> t;
		arr.pb({s,(i+1)});
		arr.pb({t,-(i+1)});
	}
	sort(arr.begin(),arr.end());
	set<int> st;
	long kq = 0, tmp = 0;
	for (auto [x,p] : arr) {
		if (p < 0) {
			tmp--;
			kq += tmp;
		} else tmp++;
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
