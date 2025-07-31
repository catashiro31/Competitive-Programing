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
	vector<pair<pair<long,int>,int>> arr;
	for (int i = 0; i < n; i++) {
		long a, b; cin >> a >> b;
		arr.pb({{a,-1},i});
		arr.pb({{b,1},i});
	}
	sort(arr.begin(),arr.end());
	
	priority_queue<int,vector<int>,greater<>> pq;
	for (int i = 0; i < n; i++) pq.push(i);
	vector<int> p(n);
	int kq = 0, tmp = 0;
	for (auto x : arr) {
		tmp += x.fi.se;
		kq = max(kq,-tmp);
		if (x.fi.se == -1) {
			p[x.se] = pq.top();
			pq.pop();
		} else pq.push(p[x.se]);
	}
	cout << kq << endl;
	for (int i = 0 ; i < n; i++) cout << p[i]+1 << " ";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
