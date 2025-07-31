#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
string xau;
vector<bool> c;
string tmp = "";
set<string> kq;
void Try(int i) {
	if (i == xau.size()) {
		kq.insert(tmp);
		return;
	}
	for (int j = 0; j < xau.size(); j++) {
		if (!c[j]) {
			tmp += xau[j];
			c[j] = true;
			Try(i+1);
			tmp.pop_back();
			c[j] = false;
		}
	}
}
void solve() {
	cin >> xau;
	for (int i = 0; i < xau.size(); i++) c.pb(false);
	Try(0);
	cout << kq.size() << endl;
	for (string x : kq) cout << x << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
