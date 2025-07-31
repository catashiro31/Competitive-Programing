#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, W;
	cin >> N >> W;
	int w[N+1];
	long int v[N+1];
	for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];
	long int f[N+1][W+1];
	memset(f,0,sizeof(f));
	for (int i = 1; i <= N; i++) {
		for (int s = 1; s <= W; s++) {
			f[i][s] = f[i-1][s];
			if (s >= w[i])
				f[i][s] = max(f[i][s],f[i-1][s-w[i]]+v[i]);
		}
	}
	cout << f[N][W];
}