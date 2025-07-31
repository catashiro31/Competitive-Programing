#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int m, n, p; cin >> m >> n >> p;
	vector<int> a(m),b(n);
	for (int &x : a) cin >> x;
	for (int &x : b) cin >> x;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end()); 
	vector<string> t(p);
	vector<int> kq;
	for (string &s : t) cin >> s;
	for (int i = p-1; i >= 0; i--) {
		if (t[i] == "PUSH_B") {
			kq.pb(b[b.size()-1]);
			b.pop_back();
		} else if (t[i] == "PUSH_A") {
			kq.pb(a[a.size()-1]);
			a.pop_back();
		} else if (t[i] == "POP_A") {
			a.pb(b[b.size()-1]);
			b.pop_back();
		} else if (t[i] == "POP_B") {
			b.pb(a[a.size()-1]);
			a.pop_back();
		}
	}
	reverse(kq.begin(),kq.end());
	for (int x : kq) cout << x << " ";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
