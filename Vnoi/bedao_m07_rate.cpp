#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
string kitu_nhiphan(int a) {
	string kq = "";
	while (a) {
		kq = to_string(a%2) + kq;
		a/=2;
	}
	return kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int l; cin >> l;
	string xau; cin >> xau;
	vector<string> ki(26);
	for (int i = 'a'; i <= 'z'; i++) {
		ki[i-'a'] = kitu_nhiphan(i);
	}
	int cmin = INT_MAX;
	vector<string> kq;
	kq.push_back("");
	for (char x : xau) {
		if (x == '#') {
			int size = kq.back().size();
			cmin = min(cmin,size);
			kq.push_back("");
		} else kq.back() += ki[x-'a'];
	}
	int size = kq.back().size();
	cmin = min(cmin,size);
	int tu = 0, mau = 0;
	for (string s: kq) {
		for (int i = 0; i < cmin; i++) {
			if (s[i] == '1') tu++;
			else mau++;
		}
	}
	cout << kq.size() << " " << cmin << endl;
	cout << fixed << setprecision(9) << 1.0*tu/mau;
}
