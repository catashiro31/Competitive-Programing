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
		reverse(s.begin(),s.end());
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'q') cout << 'p';
			else if (s[i] == 'p') cout << 'q';
			else cout << 'w';
		}
		cout << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
