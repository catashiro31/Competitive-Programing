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
	int n; cin >> n;
	string s; cin >> s;
	bool c = true;
	for (int i = 0; 2*i < n; i++) {
		if (s[i] != s[n-1-i]) {
			c = false;
			break;
		}
	}
	if (!c) cout << n;
	else {
		bool d = false;
		for (int i = 1; i < n; i++)	{
			if (s[i] != s[i-1]) {
				d = true;
				break;
			}
		}
		if (!d) cout << 0;
		else cout << n-1;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
