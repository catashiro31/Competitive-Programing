#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<vector<int>> sl(23);
	for (int i = 0; i < n; i++) {
		long a; cin >> a;
		sl[a%23].push_back(i);
	}
	long long kq = 0;
	for (int i = 0; i < 23; i++) {
		for (int x : sl[i]) {
			auto it = upper_bound(sl[i].begin(),sl[i].end(),x+5);
			if (it == sl[i].end()) break;
			else kq += sl[i].end() - it; 
		}
	}
	cout << kq;
}
