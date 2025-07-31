#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<string> xau(n);
	for (string &x : xau) cin >> x;
	set<string> s;
	s.insert(xau[0]);
	int tmp = s.size();
	for (int i = 1; i < n; i++) {
		s.insert(xau[i]);
		if (xau[i-1].back() != xau[i].front() || tmp == s.size()) {
			if (i % 2) cout << "NO\n" << i+1;
			else cout << "NO\n" << i+1;	
			return 0;
		}
		tmp = s.size();
	} 
	cout << "YES";
}
