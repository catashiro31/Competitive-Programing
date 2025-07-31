#include <bits/stdc++.h>
#define endl '\n'
#define INF 1e9
#define LINF 1e18
#define pii pair<int,int>
#define pli pair<long,int>
#define plli pair<ll,int>
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define sz(x) ((x).size())
#define vi vector<int>
#define vl vector<long>
#define vll vector<long long>
#define fo(i,a,b) for(int i=(a); i <= (b); ++i)
#define ford(i,a,b) for(int i=(b); i >= 0; --i)
#define rep(i,n) for(int i= 0; i < (n); ++i)
#define repd(i,n) for(int i= (n)-1; i >= 0; --i)
#define mod 1000000007
using ll = long long;
using namespace std;
int loga(long x, int base) {
	int kq = 0;
	while (x >= base) {
		x /= base;
		kq++;
	}
	return kq;
}
void solve() {
	int n, m; cin >> n >> m;
	vl arr(n);
	for (long &x : arr) cin >> x;
	sort(all(arr));
	vector<bool> c(n,0);
	rep(i,n) {
		long x = arr[i];
		int tmp1 = loga(x,2);
		int tmp2 = loga(x,3);
		int tmp3 = loga(x,5);
		if (pow(2,tmp1)==x || pow(3,tmp2)==x || pow(5,tmp3)==x) c[i] = 1;
	}
	vector<int> prefix_sum(n+1,0);
	fo(i,1,n) prefix_sum[i] = prefix_sum[i-1]+c[i-1];
	while (m--) {
		long l, h; cin >> l >> h;
		long st = lower_bound(all(arr),l)-arr.begin();
		long ed = upper_bound(all(arr),h)-arr.begin();
		cout << prefix_sum[ed] - prefix_sum[st] << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
