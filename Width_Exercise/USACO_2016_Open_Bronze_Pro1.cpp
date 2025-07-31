#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "diamond";
void solve() {
	int n, k; cin >> n >> k;
	vector<int> arr(n);
	for (int &x : arr) cin >> x;
	sort(arr.begin(),arr.end());
	int kq = 0;
	for (int i = 0; i < n; i++) {
		int j = i+1, sl = 1;
		while (j < n && abs(arr[i]-arr[j]) <= k) sl++, j++;
		kq = max(kq,sl);
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen((NoF + ".in").c_str(),"r",stdin);
	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
