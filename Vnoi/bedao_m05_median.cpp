#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
void solve() {
	int n; cin >> n;
	long x; cin >> x;
	vector<long> a(n);
	for (long &k : a) cin >> k;
	sort(a.begin(),a.end());
	if (a[(n-1)/2] == x) cout << 0;
	else if (a[(n-1)/2] > x) {
		int i = upper_bound(a.begin(),a.end(),x) - a.begin() - 1;
		cout << n-2-2*i;
	} else {
		int i = lower_bound(a.begin(),a.end(),x) - a.begin();
		cout << 2*i-n+1;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
