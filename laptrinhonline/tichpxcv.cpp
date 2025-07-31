#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	string s; cin >> s;
	int n = s.length();
	int x = 0,d = 0;
	vector<int> xd(1e6+1,INT_MAX),dx(1e6+1,INT_MAX);
	xd[0] = -1;
	vector<int> dis(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'X') x++;
		if (s[i] == 'D') d++;
		dis[i] = x-d;
		if (dis[i] >= 0) xd[dis[i]] = min(i,xd[dis[i]]);
		else dx[abs(dis[i])] = min(i,dx[abs(dis[i])]); 
	}
	int kq = 0;
	for (int i = 0; i < n; i++) {
		if (dis[i] >= 0) kq = max(kq,i-xd[dis[i]]);
		else kq = max(kq,i-dx[abs(dis[i])]);
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
// 	freopen("input.txt","r",stdin);
	solve();
}