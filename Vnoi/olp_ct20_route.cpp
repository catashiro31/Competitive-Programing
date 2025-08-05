#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define psb push_back
#define ppb pop_back
#define psf push_front
#define ppf pop_front
#define endl '\n'
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
const int MAXN = 2e5+1;
const int MOD = 1e9+7;
const string NoF = "Name_of_File";

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<pair<int,string>>> dp2(n,vector<pair<int,string>>(m,{0,""})), dp5(n,vector<pair<int,string>>(m,{0,""}));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x; cin >> x;
			while (x && x % 2 == 0) dp2[i][j].fr++, x/= 2;
			while (x && x % 5 == 0) dp5[i][j].fr++, x/= 5;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) continue;
			if (i == 0 && j != 0) {
				dp2[i][j] = {dp2[i][j-1].fr + dp2[i][j].fr, dp2[i][j-1].sc + "L"};
				dp5[i][j] = {dp5[i][j-1].fr + dp5[i][j].fr, dp5[i][j-1].sc + "L"};
				continue;
			}
			if (i != 0 && j == 0) {
				dp2[i][j] = {dp2[i-1][j].fr + dp2[i][j].fr, dp2[i-1][j].sc + "D"};
				dp5[i][j] = {dp5[i-1][j].fr + dp5[i][j].fr, dp5[i-1][j].sc + "D"};
				continue;
			}
			if (dp2[i-1][j].fr < dp2[i][j-1].fr) {
				dp2[i][j] = {dp2[i-1][j].fr + dp2[i][j].fr, dp2[i-1][j].sc + "D"};
			} else if (dp2[i-1][j].fr > dp2[i][j-1].fr) {
				dp2[i][j] = {dp2[i][j-1].fr + dp2[i][j].fr, dp2[i][j-1].sc + "L"};
			} else {
				if (dp2[i-1][j].sc + "D" <  dp2[i][j-1].sc + "L") {
					dp2[i][j] = {dp2[i-1][j].fr + dp2[i][j].fr, dp2[i-1][j].sc + "D"};
				} else {
					dp2[i][j] = {dp2[i][j-1].fr + dp2[i][j].fr, dp2[i][j-1].sc + "L"};
				}
			}
			if (dp5[i-1][j].fr < dp5[i][j-1].fr) {
				dp5[i][j] = {dp5[i-1][j].fr + dp5[i][j].fr, dp5[i-1][j].sc + "D"};
			} else if (dp5[i-1][j].fr < dp5[i][j-1].fr) {
				dp5[i][j] = {dp5[i][j-1].fr + dp5[i][j].fr, dp5[i][j-1].sc + "L"};
			} else {
				if (dp5[i-1][j].sc + "D" < dp5[i][j-1].sc + "L") {
					dp5[i][j] = {dp5[i-1][j].fr + dp5[i][j].fr, dp5[i-1][j].sc + "D"};
				} else {
					dp5[i][j] = {dp5[i][j-1].fr + dp5[i][j].fr, dp5[i][j-1].sc + "L"};
				}
			}
		}
	}
	if (dp2[n-1][m-1].fr <= dp5[n-1][m-1].fr) cout << dp2[n-1][m-1].fr << endl << dp2[n-1][m-1].sc;
	else cout << dp5[n-1][m-1].fr << endl << dp5[n-1][m-1].sc;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
