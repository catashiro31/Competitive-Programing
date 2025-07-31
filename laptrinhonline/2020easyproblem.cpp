#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define INF INT_MAX
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<long> bp;
	for (int i = 2; pow(i,2) <= mod-7; i++) bp.push_back(i*i);
	int t; cin >> t;
	while (t--) {
		long x; cin >> x;
		int z = 1;
		int i = upper_bound(bp.begin(),bp.end(),x) - bp.begin()-1;
		for (i; i >= 0; i--) {
			if (x%bp[i] == 0) {
				z *= sqrt(bp[i]);
				x /= bp[i];
				i = upper_bound(bp.begin(),bp.end(),x) - bp.begin() -1;
			}
		}
		cout << z << " " << x << endl;
	} 
}
