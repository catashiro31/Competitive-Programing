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
	long n, k, m; cin >> n >> k >> m;
	vector<long> a(n);
	for (long &x : a) cin >> x;
	int i = 0, j = 0;
	long kq = 0;
	while (j < n) {
		long tmp = 0;
		while (j <= i && j < n && tmp < m) {
			if (tmp + a[j] > m) a[j] = tmp + a[j] - m, tmp = m;
			else tmp += a[j], j++;
		}
		kq += tmp;
		while (j+k <= i+1) j++;
		i++;
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}