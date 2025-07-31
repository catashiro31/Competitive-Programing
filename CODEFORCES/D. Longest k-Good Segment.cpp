#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	vector<int> sl(1e6+1,0);
	set<int> s;
	int i = 0, j = 0;
	int kq = 0, l = 0, r = 0;
	while (j < n) {
		s.insert(a[j]);
		sl[a[j]]++;
		while (s.size() > k) {
			sl[a[i]]--;
			if (!sl[a[i]]) s.erase(a[i]);
			i++;
		}
		if (s.size() <= k && j-i+1 > kq) kq = j-i+1, l = i+1, r = j+1;
		j++;
	}
	cout << l << " " << r;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	solve();
}
