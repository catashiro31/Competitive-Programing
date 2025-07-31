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
	int res1 = 0, res2 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') res2++;
		else res2--;
		if (res2 == -1) res1++, res2++;
	}
	for (int i = 0; i < res1; i++) cout << "(";
	cout << s;
	for (int i = 0; i < res2; i++) cout << ")";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
