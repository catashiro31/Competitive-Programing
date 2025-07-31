#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	ll S = 0;
	vector<long> arr(n);
	for (long &x : arr) {
		cin >> x;
		S += x;
	}
	S = S/(n-1);
	for (long x : arr) {
		cout << (char)(S-x);
	}
}
