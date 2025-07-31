#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int arr[n];
	for (int &x : arr) cin >> x;
	int j = 0;
	long long kq= 0;
	for (int i = 0; i < n; i++) {
		if (!arr[i]) {
			kq += i-j;
			j++;
		}
	}
	cout << kq;
}
