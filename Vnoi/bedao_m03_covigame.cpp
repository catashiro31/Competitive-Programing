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
	vector<int> a(n);
	for (int &x : a) cin >> x;
	vector<int> low(n), high(n);
	low[0] = -1, high[n-1] = -1;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i-1]) low[i] = low[i-1];
		else low[i] = a[i-1];
	}
	for (int i= n-2; i >= 0; i--) {
		if (a[i] == a[i+1]) high[i] = high[i+1];
		else high[i] = a[i+1];
	}
	map<int,int> sl;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i-1] && low[i] != -1 && high[i] != -1) {
			if (abs(low[i]-high[i]) > k) sl[a[i]] ++;
		}
	}
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (abs(a[i]-a[i+1]) > k) tmp++, sl[a[i]]--;
		} else if (i == n-1) {
			if (abs(a[i]-a[i-1]) > k) tmp++, sl[a[i]]--;
		} else {
			if (abs(a[i]-a[i-1]) > k) tmp++, sl[a[i]]--;
			if (abs(a[i]-a[i+1]) > k) sl[a[i]]--;
		}
	} 
	int ans = INT_MAX, kq;
	for (int i = 0; i < n; i++) {
		if (tmp+sl[a[i]] < ans) ans = tmp+sl[a[i]], kq = a[i];
		else if (tmp+sl[a[i]] == ans) kq = min(kq,a[i]);
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
