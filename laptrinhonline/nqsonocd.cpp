#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	long arr[n];
	for (long &x : arr) cin >> x;
	int i = 0, j = n-1;
	long long sumr = arr[n-1], suml = arr[0];
	int ccount = 0;
	while (i < j) {
		if (sumr > suml) {
			i++;
			suml += arr[i];
		} else if (suml > sumr) {
			j--;
			sumr += arr[j];
		} else {
			i++; j--;
			ccount += 2;
			suml = arr[i];
			sumr = arr[j];
		}
	}
	if (i == j) ccount++;
	cout << ccount;
	return 0;
}
