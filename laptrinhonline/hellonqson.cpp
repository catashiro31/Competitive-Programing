#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int t; cin >> t;
	cin.ignore();
	while (t--) {
		string hoten;
		getline(cin,hoten);
		hoten = " " + hoten;
		string kq = "hello ";
		int k = 2;
		for (int i = 1; i < hoten.length(); i++) {
			if (hoten[i-1] == ' ' && hoten[i] != ' ') {
				kq += char(tolower(hoten[i]));
				k = i+1;
			}
		}
		for (int i = k; i < hoten.length(); i++) kq += tolower(hoten[i]);
		cout << kq << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
// 	freopen("input.txt","r",stdin);
	solve();
}