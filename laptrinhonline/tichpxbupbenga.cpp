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
	vector<int> a(n);
	for (int &x : a) cin >> x;
	multiset<int> big;
	sort(a.begin(),a.end(),greater<>());
	long kq = 0;
	for (int x : a) {
		if (big.empty()) {
			big.insert(x); kq += x;
		} else {
			auto it = big.lower_bound(x+k);
			if (it == big.end()) {
				big.insert(x); kq += x;
			} else {
				big.erase(it);
				big.insert(x);
			}
		}
	}
	cout << big.size() << " " << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
