#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
int n, p, k; 
vector<int> par;
int find_(int u) {
	if (par[u] == u) return u;
	return par[u] = find_(par[u]);
}

void union_(int u, int v) {
	int pu = find_(u), pv = find_(v);
	if (pu == pv) return;
	if (pu < pv) swap(pv,pu);
	par[pu] = pv;
	return;
}
string tmp = "", res = "";
void backtrack(int u, int dst, int len, int &z) {
	if (z == 0) return;
	if (u == dst) {
		bool check = true;
		int l = 1, r = len;
		while (l < r) {
			if (tmp[l-1] != tmp[r-1]) {
				check = false;
				break;
			}
			l++, r--;
		}
		if (r == l) check = false;
//		cout << tmp << " " << check << endl;
		if (check) return;
		if (z == 1) res = tmp;
		z--;
		return;
	}
	for (int i = 0; i < 26; i++) {
		tmp += char(i+'a');
		backtrack(u+1,dst,len,z);
		tmp.pop_back();
	}
}


void solve() {
	cin >> n >> p >> k;
	par.assign(n+1,0);
	for (int i = 0; i <= n; i++) par[i] = i;
	int len = n;
	while (p--) {
		int l = 1, r = len;
		while (l < r) {
			union_(l,r);
			l++, r--;
		}
		len = (len+1)/2;
	}
	for (int i = 1; i <= n; i++) par[i] = find_(par[i]);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (par[i] == i) cnt++;
	}
//	
	int sl = cnt-len;
	int base = pow(26,sl);
	int chia = k/base, mol = k%base;
	backtrack(0,len,len,chia);
	string show = res;
//	cout << res << endl;
	tmp = "", res = "";
	backtrack(0,sl,1,mol);
//	cout << res << endl;
	show += res;
//	backtrack(0,cnt,len);
	int t = 0;
	vector<char> kq(n+1);
	for (int i = 1; i <= n; i++) {
		if (par[i] == i) {
			kq[i] = show[t];
			t++;
		}
	}
	for (int i = 1; i <= n; i++) cout << kq[par[i]];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
