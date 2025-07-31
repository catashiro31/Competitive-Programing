#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
string bit(ll x) {
	string ans = "";
	while (x) {
		if (x%2) ans = "1" + ans;
		else ans = "0" + ans;
		x/=2;
	}
	return ans;
}
void solve() {
	ll a, b; cin >> a >> b;
	string bita = bit(a), bitb = bit(b);
	while(bita.length() < bitb.length()) bita = "0"+bita;
	while(bitb.length() < bita.length()) bitb = "0"+bitb;
	int kq = 0;
	for (int i = 0; i < bita.length(); i++) {
		if (bita[i] != bitb[i]) kq++;
	} 
	if (kq%2) cout << -1;
	else cout << kq/2;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
