#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	long x; cin >> x;
	multiset<long> ms;
	ms.insert(0), ms.insert(x);
	multiset<long> kq;
	kq.insert(x);
	int n; cin >> n;
	while (n--) {
		long k; cin >> k;
		auto it1 = ms.upper_bound(k);
		auto it2 = prev(it1);
		auto it = kq.find(*it1 - *it2);
		kq.erase(it);
		kq.insert(*it1 - k);
		kq.insert(k - *it2);
		ms.insert(k);
		cout << *kq.rbegin() << " ";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
