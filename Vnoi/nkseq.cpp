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
	vi arr(n+1);
	fo(i,1,n) cin >> arr[i];
	vll sum(n+1,0);
	fo(i,1,n) sum[i] = arr[i] + sum[i-1];
	vll minL(n+1); minL[1] = sum[1];
	fo(i,2,n) minL[i] = min(sum[i],minL[i-1]);
	vll minR(n+1); minR[n] = sum[n];
	fod(i,1,n-1) minR[i] = min(minR[i+1],sum[i]);
	int kq = 0;
	fo(i,1,n) {
		if (minR[i] - sum[i-1] > 0 && minL[i] + sum[n] - sum[i-1] > 0) kq++; 
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
