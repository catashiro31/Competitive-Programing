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
	vi a(n);
	for(int &x : a) cin >> x;
	vll prefix_s(n);
	prefix_s[0] = a[0];
	fo(i,1,n-1) prefix_s[i] = prefix_s[i-1] + a[i];
	vll sum2(n); sum2[0] = 0;
	fo(i,1,n-1) sum2[i] = (sum2[i-1] + 1LL * a[i] * prefix_s[i-1])%mod;
	vll sum3(n); 
	sum3[0] = 0, sum3[1] = 0;
	fo(i,2,n-1) sum3[i] = (sum3[i-1] + 1LL * a[i] * sum2[i-1])%mod;
	cout << sum3[n-1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt","r",stdin);
	solve();
}
