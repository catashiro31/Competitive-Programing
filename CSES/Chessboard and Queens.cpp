#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
vector<vector<int>> c(8,vector<int>(8,0));
vector<bool> c1(16,false), c2(16,false);
ll kq = 0;
void Try(int i) {
	if (i == 8) {
		kq++;
		return;
	}
	for (int j = 0; j < 8; j++) {
		if (!c[j][i] && !c1[j+i+1] && !c2[j-i+8]) {
			for (int k = i; k < 8; k++) if (c[j][k] != -1) c[j][k] = 1; 
			c1[j+i+1] = true, c2[j-i+8] = true;
			Try(i+1);
			for (int k = i; k < 8; k++) if (c[j][k] != -1) c[j][k] = 0;
			c1[j+i+1] = false, c2[j-i+8] = false;
		}
	}
}
void solve() {
	for (int i = 0; i < 8; i++) {
		string x; cin >> x;
		for (int j = 0; j < x.size(); j++) {
			if (x[j] == '*') c[i][j] = -1;
		}
	}
	Try(0);
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
