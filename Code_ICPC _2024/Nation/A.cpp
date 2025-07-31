#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<long> arr(n);
		set<long> s;
		map<long,int> sl;
		for (long &x : arr){
			cin >> x;
			s.insert(x);
			sl[x]++;
		}
		sort(arr.begin(),arr.end());
		long long kq = 0;
		for (long x : s) {
			if (sl[x] >= 3) {
				kq += 1LL*sl[x]*(sl[x]-1)*(sl[x]-2)/6;
			}
			if (sl[x] >= 2) {
				int k = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
				kq += 1LL*sl[x]*(sl[x]-1)*k/2;
			}
		}
		cout << kq << endl;
	}
}
