#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
bool check(vector<int> tmp, int M) {
	bool c = true;
	for (int i = 0; i < 5; i++) {
		if (tmp[i] < M) {
			c = false;
			break;
		}
	}
	return c;
}
void solve() {
	string s; cin >> s;
	int M; cin >> M;
	int n = s.length();
	int l = 1, r = n;
	int kq = -1;
	while (l < r) {
		int m = (l+r)/2;
		vector<int> tmp(5,0);
		bool c = false;
		for (int i = 0; i < n; i++) {
			if (s[i]-'a' < 5) tmp[s[i]-'a']++;
			if (i >= m && s[i-m]-'a' < 5) tmp[s[i-m]-'a']--;
			if (i >= m-1) c = check(tmp,M);
			if (c) break;
		}
		if (!c) l = m+1;
		else kq = m, r = m;
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
