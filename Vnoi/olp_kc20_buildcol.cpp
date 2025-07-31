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
#define fod(i,a,b) for(int i=(b); i >= (a); --i)
#define rep(i,n) for(int i= 0; i < (n); ++i)
#define repd(i,n) for(int i= (n)-1; i >= 0; --i)
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	ll m; cin >> m;
	vl a(n);
	long L = LONG_MAX, H = LONG_MIN;
	for (long &x : a) {
		cin >> x;
		L = min(x,L);
		H = max(x,H);
	}
	long kq = -1;
	while (L <= H) {
		long mid = (L+H)/2;
		vl MaxL(n,max(a[0],mid)), MaxR(n,max(a[n-1],mid));
		fo(i,1,n-1) MaxL[i] = max({mid,MaxL[i-1],a[i]});
		fod(i,0,n-2) MaxR[i] = max({mid,MaxR[i+1],a[i]});
		ll sum = 0;
		fo(i,1,n-2) {
			long tmp  = min(MaxL[i-1],MaxR[i+1]);
			long res = max(0*1L,tmp-max(a[i],mid));
			sum += res;
		}
		if (sum >= m) {
			kq = max(kq,mid);
			L = mid +1;
		} else H = mid - 1;
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
