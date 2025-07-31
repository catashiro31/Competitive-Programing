#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int gcd(int a, int b) {
	if (!b) return a;
	else return gcd(b,a%b);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	set<pair<int,int>> s;
	while (n--) {
		int x, y; cin >> x >> y;
		int ucln = gcd(abs(x),abs(y));
		s.insert({x/ucln,y/ucln});
	}
	cout << s.size();
}
