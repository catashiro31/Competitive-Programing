#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	multiset<long> ms;
	while(n--) {
		long x; cin >> x;
		auto it = ms.upper_bound(x);
		if (it != ms.end()) ms.erase(it);
		ms.insert(x); 
	}
	cout << ms.size();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
