#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, S;
	cin >> n >> S;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	int f[S+1];
	f[0] = 0;
	for (int i = 1; i <= S; i++) {
		f[i] = 1e9;
		for (int j = 0; j < n; j++) {
			if (i >= arr[j])
				f[i] = min(f[i],f[i-arr[j]]+1);
		}		
	}
	if (f[S] == 1e9) cout << "-1";
	else cout << f[S];
}