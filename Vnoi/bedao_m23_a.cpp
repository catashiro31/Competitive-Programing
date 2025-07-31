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
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		if (s.length() == 1) cout << -1 << endl;
		else {
			bool c = false;
			for (int i = 1; i < s.length(); i++) {
				if (s[i] == s[i-1]) c = true; 
				if (i >= 2 && s[i] == s[i-2]) c = true;
			}
			if (c) cout << 0 << endl;
			else cout << 1 << endl;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
