#include <bits/stdc++.h>
#define maxn 100006
#define MOD 1000000007
using namespace std;
int n;
int f[maxn];
int main() {
	cin >> n;
	f[0] = 1;
	for (int i=1 ; i<=n ; i++) {
		for (int j=max(0,i-6); j<=i-1; j++) {
			f[i] = (f[i]+f[j])%MOD;
		}
	}
	cout << f[n];
}