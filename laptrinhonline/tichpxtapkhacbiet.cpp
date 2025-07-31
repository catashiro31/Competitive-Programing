#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	vector<long> a(n);
	for (long &x : a) cin >> x;
	vector<int> l(n,1);
	int pos = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i-1; j >= pos; j--) {
			if (a[i] == a[j]) {
				pos = j+1;
				break;
			}
			else l[i]++;
		}
	}
	cout << *max_element(l.begin(),l.end());
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
// 	freopen("input.txt","r",stdin);
	solve();
}
