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
	int n, k; cin >> n >> k;
	vector<string> S;
	for (int i = 0; i < n; i++) {
		string x, tmp; cin >> x;
		if (x.length() < k) continue;
		else if (x.length() == k) {
			tmp = x.substr(0,k);
			for (int j = k-1; j >= 0; j--) tmp += x[j];
			tmp += "00";
		} else {
			tmp = x.substr(0,k);
			for (int j = 0; j < k; j++) tmp += x[x.length()-1-j];
			tmp += x[k];
			tmp += x[x.length()-1-k];
		}
		S.pb(tmp);
	}
	sort(S.begin(),S.end());
	long kq = 0;
	int tmp = 1, same = 0;
	for (int i = 1; i < S.size(); i++) {
		string now = S[i].substr(0,2*k), last = S[i-1].substr(0,2*k);
		if (now != last) tmp = 1, same = 0;
		else {
			if (S[i] == S[i-1] && S[i].substr(2*k,2) != "00") same++;
			else same = 0;
			kq += tmp - same;
			tmp++;
		} 
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