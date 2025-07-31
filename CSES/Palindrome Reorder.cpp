#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	string xau; cin >> xau;
	int n = xau.size();
	vector<int> sl(26,0);
	for (char x : xau) sl[x-'A']++;
	int s = 0; 
	char c;
	for (int i = 0; i < 26; i++) if (sl[i]%2) s++, c = i;
	if (s > 1) cout << "NO SOLUTION" << endl;
	else {
		string tmp = "";
		for (int i = 0; i < 26; i++) {
			for (int j = 1; j*2 <= sl[i]; j++) tmp += char(i+'A'); 
		}
		cout << tmp;
		if (n%2) cout << char(c+'A');
		reverse(tmp.begin(),tmp.end());
		cout << tmp;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
