#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
long LEFT(vector<long> arr, int n) {
	vector<long> prefix(n);
	for (int i = 0; i < n; i++) {
		if (i) prefix[i] = prefix[i-1] + arr[i];
		else prefix[i] = arr[i];
	}
	long ans = LONG_MAX, base = 0;
	for (int i = 0; i < n; i++) {
		long tmp = base;
		int m = (n-1+i)/2;
		if (i == 0) tmp += ((m-i+1)*arr[m] - prefix[m]) + ((prefix[n-1] - prefix[m]) - (n-1-m)*arr[m]);
		else tmp += ((m-i+1)*arr[m] - (prefix[m] - prefix[i-1])) + ((prefix[n-1] - prefix[m]) - (n-1-m)*arr[m]);
		ans = min(ans,tmp);
		base += abs(arr[i]);
	}
	return ans;
}
long RIGHT(vector<long> arr, int n) {
	vector<long> prefix(n);
	for (int i = n-1; i >= 0; i--) {
		if (i != n-1) prefix[i] = prefix[i+1] + arr[i];
		else prefix[i] = arr[i];
	}
	long ans = LONG_MAX, base = 0;
	for (int i = n-1; i >= 0; i--) {
		long tmp = base;
		int m = i/2;
		if (i == n-1) tmp += (prefix[m] - (i-m+1)*arr[m]) + (-(prefix[0] - prefix[m]) + m*arr[m]);
		else tmp += ((prefix[m] - prefix[i+1]) - (i-m+1)*arr[m]) + (-(prefix[0] - prefix[m]) + m*arr[m]);
		ans = min(ans,tmp);
		base += abs(arr[i]);
	}
	return ans;
}
void solve() {
	int n; cin >> n;
	vector<long> arr(n);
	for (long &x : arr) cin >> x;
	sort(arr.begin(),arr.end());
	long kq = LONG_MAX, base = 0;
	kq = min(kq,LEFT(arr,n));
	kq = min(kq,RIGHT(arr,n));
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
