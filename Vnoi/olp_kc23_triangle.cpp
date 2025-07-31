#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	long double u,v; cin >> u >> v;
	long double a = u+v;
	long double kq = (a/2)*(a/2) - u*(v/2);
	cout << fixed << setprecision(2) << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
