#include <bits/stdc++.h>
#define m 1000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int arr[n];
	for (int &x : arr) cin >> x;
	map<int,int> g;
	set<int> st;
	for (int i = 0; i < n; i++) {
		g[arr[i]]++;
		st.insert(arr[i]);
	}
	long long kq = 0;
	for (int x : st) {
		kq += (g[x]*(g[x]-1)/2)%m;
		kq %= m;
	}
	cout << kq;
	cerr << "\nTime elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
}
