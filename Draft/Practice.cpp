#include<bits/stdc++.h>
using namespace std;
void exercise1() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int x; cin >> x;
			a.push_back(x);
		} else if (t == 2) {
			if (!a.empty()) a.pop_back();
		} else {
			int k; cin >> k;
			--k;
			cout << a[k] << endl;
		}
	}
}
void exercise2() {
	set<int> s;
	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int x; cin >> x;
			s.insert(x);
		} else if (t == 2) {
			int x; cin >> x;
			if (s.count(x)) s.erase(x);
		} else if (t == 3) {
			int x; cin >> x;
			auto it = s.upper_bound(x);
			if (it != s.end()) cout << *it << endl;
			else cout << -1 << endl;
		} else {
			int x; cin >> x;
			auto it = s.lower_bound(x);
			if (it != s.end()) cout << *it << endl;
			else cout << -1 << endl;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
//	exercise1();
	exercise2();
}