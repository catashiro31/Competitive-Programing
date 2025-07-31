#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	while (n--) {
		int g, w, r, t; cin >> g >> w >> r >> t;
		int sum = g+w+r;
		int tmp = t%sum;
		if (tmp < g) cout << "Guiding Beat" << endl;
		else if (tmp < g+w) cout << "Warning Beat" << endl;
		else if (tmp < g+w+r) cout << "Resting Phase" << endl;
	}
}
