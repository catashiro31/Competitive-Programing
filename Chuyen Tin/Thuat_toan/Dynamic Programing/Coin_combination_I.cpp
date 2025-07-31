#include <bits/stdc++.h>
using namespace std;
int main() {
	long int Mod = pow(10,9)+7;
	int n, x;
	cin >> n >> x;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr,arr+n);
	int f[x+1];
	f[0] = 1;
	for (int s = 1; s <= x; s++) {
		f[s] = 0;
		for (int i = 0; i < n; i++) {
			if (s >= arr[i]) {
				f[s] = (f[s]+f[s-arr[i]]) % Mod;
			}
		}
	}
	cout << f[x];
}