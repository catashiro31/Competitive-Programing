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
	vl a(n);
	for (long &x : a) cin >> x;
	vll kq(n); 
	ll tmp = 0;
	rep(i,n) {
		int sl = n-1-i;
		if (sl) {
			kq[i] = (a[i]+tmp)%sl;
			tmp += (a[i]+tmp)/sl;
		} else kq[i] = a[i]+tmp;
	}
	rep(i,n) cout << kq[i] << " ";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt","r",stdin);
	solve();
}
