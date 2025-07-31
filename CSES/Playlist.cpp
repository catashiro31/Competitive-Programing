#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	vector<long> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	map<long,int> p;
	for (int i = n-1; i >= 0; i--) p[arr[i]] = i;
	int l = 0, r = 0;
	int kq = 0;
	while (r < n) {
		if (p[arr[r]] != r) {
			while (l <= p[arr[r]]) l++;
			p[arr[r]] = r;
		}
//		cout << l << " " << r << endl;
		kq = max(kq,r-l+1);
		r++;
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
