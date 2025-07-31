#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, m; cin >> n >> m;
	vector<int> arr(n);
	for (int &x : arr) cin >> x;
	set<int> s;
	for (int i = 0; i <= n; i++) s.insert(i);
	vector<int> sl(n,0);
	int kq = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (!sl[arr[i]]) s.erase(arr[i]); 
		sl[arr[i]]++;
		if (i == m-1) kq = min(kq,*s.begin());
		else if (i >= m) {
			sl[arr[i-m]]--;
			if (!sl[arr[i-m]]) s.insert(arr[i-m]);
			kq = min(kq,*s.begin());
		}
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
