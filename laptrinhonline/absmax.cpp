#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define INF INT_MAX
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<long> a(n);
	for (long &x : a) cin >> x;
	sort(a.begin(),a.end());
	cout << max(abs(a[0]+a[1]),abs(a[a.size()-1]+a[a.size()-2]));
}
