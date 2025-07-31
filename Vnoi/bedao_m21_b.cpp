#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
bool check(int x) {
	long long tmp = 1LL*x*x;
	vector<int> sl(10,0);
	while (tmp) {
		sl[tmp%10]++;
		tmp/=10;
	}
	while (x) {
		sl[x%10]++;
		x/=10;
	}
	for (int i = 0; i <= 9; i++) {
		if (sl[i] > 2) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> trv;
	for (int i = 1; i <= 4*1e6; i++) {
		if (check(i)) trv.push_back(i);
	}
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		auto it = lower_bound(trv.begin(),trv.end(),n);
		if (it != trv.end()) cout << *it << endl;
		else cout << -1 << endl; 
	}
}
