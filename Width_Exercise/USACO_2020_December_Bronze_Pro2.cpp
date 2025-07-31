#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name of File";
void solve() {
	int n; cin >> n;
	int arr[n];
	for (int &x : arr) cin >> x;
	int kq = 0;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = i; j < n; j++) {
			tmp += arr[j];
			if (tmp % (j-i+1)) continue;
			for (int k = i; k <= j; k++) {
				if (arr[k] == (tmp/(j-i+1))) {
					kq++;
					break;
				}
			}
		}
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
