#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int le = 0;
	while (n--) {
		long x; cin >> x;
		if (x%2) le++;
	}
	if (le%2) cout << "NO";
	else cout << "YES"; 
}
