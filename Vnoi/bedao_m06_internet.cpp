#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 727355608
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
void solve() {
	vector<int> sl(4);
	for (int &x : sl) cin >> x;
	sl[0] -= sl[1] + sl[2] + sl[3];
	int mid = -1;
	for (int i = 0; i < 4; i++) {
		if (sl[i] & 1) {
			if (mid == -1) mid = i, sl[i]--;
			else {
				cout << "Bedao!";
				return;
			}
		}
	}
	for (int i = 0; i < 4; i++) sl[i] /= 2;
	string s = "";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < sl[i]; j++) s += (i+'0');
	}
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '0') {
			swap(s[i],s[0]);
			break;
		}
	}
	if (s[0] == '0') {
		cout << "Bedao!";
		return;
	}
	string res = s;
	if (mid != -1) res += (mid+'0');
	reverse(s.begin(),s.end());
	res += s;
	ll kq = 0;
	for (char x : res) kq = (kq * 4 + (x-'0')) % mod;
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
