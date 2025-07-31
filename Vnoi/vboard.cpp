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
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<vector<pair<long,long>>> prefix_s_2d(n+1,vector<pair<long,long>>(n+1,{0,0}));
	fo(i,1,n) fo(j,1,n) {
		int x; cin >> x;
		prefix_s_2d[i][j] =  {x,x};
	}
	fo(i,1,n) fo(j,1,n) {
		if (i%2 == 0) {
			if (j%2 == 0) {
				prefix_s_2d[i][j].fi += prefix_s_2d[i][j-1].fi + prefix_s_2d[i-1][j].fi - prefix_s_2d[i-1][j-1].fi;
				prefix_s_2d[i][j].se = prefix_s_2d[i][j-1].se + prefix_s_2d[i-1][j].se - prefix_s_2d[i-1][j-1].se;
			} else {
				prefix_s_2d[i][j].se += prefix_s_2d[i][j-1].se + prefix_s_2d[i-1][j].se - prefix_s_2d[i-1][j-1].se;
				prefix_s_2d[i][j].fi = prefix_s_2d[i][j-1].fi + prefix_s_2d[i-1][j].fi - prefix_s_2d[i-1][j-1].fi;
			}
		} else {
			if (j%2) {
				prefix_s_2d[i][j].fi += prefix_s_2d[i][j-1].fi + prefix_s_2d[i-1][j].fi - prefix_s_2d[i-1][j-1].fi;
				prefix_s_2d[i][j].se = prefix_s_2d[i][j-1].se + prefix_s_2d[i-1][j].se - prefix_s_2d[i-1][j-1].se;
			} else {
				prefix_s_2d[i][j].se += prefix_s_2d[i][j-1].se + prefix_s_2d[i-1][j].se - prefix_s_2d[i-1][j-1].se;
				prefix_s_2d[i][j].fi = prefix_s_2d[i][j-1].fi + prefix_s_2d[i-1][j].fi - prefix_s_2d[i-1][j-1].fi;
			}
		}
	}
	int t; cin >> t;
	while (t--) {
		int x,y,u,v;
		cin >> x >> y >> u >> v;
		long white = prefix_s_2d[u][v].fi - prefix_s_2d[u][y-1].fi - prefix_s_2d[x-1][v].fi + prefix_s_2d[x-1][y-1].fi; 
		long black = prefix_s_2d[u][v].se - prefix_s_2d[u][y-1].se - prefix_s_2d[x-1][v].se + prefix_s_2d[x-1][y-1].se;
		cout << abs(white-black) << endl; 
	}
}
