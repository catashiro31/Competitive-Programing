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
	int n, k; cin >> n >> k;
	vector<long> a(n);
	for (long &x : a) cin >> x;
	map<long,int> sl;
	int kq = INT_MIN, tmp = 0;
	for (int i = 0; i < n; i++) {
		sl[a[i]]++;
		if (sl[a[i]] == 1) tmp++;
		if (i == k-1) kq = max(tmp,kq);
		if (i >= k) {
			sl[a[i-k]]--;
			if (sl[a[i-k]] == 0) tmp--;
			kq = max(kq,tmp);
		}
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
