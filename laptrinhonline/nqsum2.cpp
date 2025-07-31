#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	sort(a.begin(),a.end());
	int i = 0, j = n-1;
	while (i < j) {
		if (a[i] + a[j] < x) i++;
		else if (a[i] + a[j] > x) j--;
		else {
			cout << min(a[i],a[j]) << " " <<  max(a[i],a[j]) << endl;
			i++; j--;
		}
	}
}
