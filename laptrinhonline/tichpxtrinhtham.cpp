#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int size = log2(n);
	int spt[n][size+1];
	for (int i = 0; i < n; i++) cin >> spt[i][0];
	for (int i = 1; i <= size; i++) {
		for (int j = 0; j + (1<<i) <= n; j++) {
			spt[j][i] = max(spt[j][i-1],spt[j+(1<<(i-1))][i-1]);
		}
	}
	int kn = log2(k);
	for (int i = 0; i <= n-k; i++) {
		cout << max(spt[i][kn],spt[i+k-(1<<(kn))][kn]) << " ";
	} 
}
