#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void Try(int n, int a, int b) {
	if (n == 1) cout << a <<  " " << b << endl;
	else {
		for (int c = 1; c <= 3; c++) {
			if (c != a && c != b) {
				Try(n-1,a,c);
				cout << a << " " << b << endl;
				Try(n-1,c,b);
			}
		}
	}
	return;
}
void solve() {
	int n; cin >> n;
	cout << (1 << n)-1 << endl;
	Try(n,1,3);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
