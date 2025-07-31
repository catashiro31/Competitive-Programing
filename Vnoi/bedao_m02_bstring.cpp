#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	string xau; cin >> xau;
	string c = xau;
	sort(c.begin(),c.end());
	int tmp1 = 0, tmp2 = 0;
	for (int i = 0; i < n; i++) {
		if (xau[i] != c[i]) tmp1++;
	}
	reverse(c.begin(),c.end());
	for (int i = 0; i < n; i++) {
		if (xau[i] != c[i]) tmp2++; 
	}
	cout << min(tmp1,tmp2)/2;
}
