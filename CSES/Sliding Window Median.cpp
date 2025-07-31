#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, k; cin >> n >> k;
	vector<long> arr(n), tmp(k);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i < k) tmp[i] = arr[i];
	}
	if (k != 1) {
		sort(tmp.begin(),tmp.end());
		multiset<long> up,dw;
		for (int i = 0; i < k; i++) {
			if (i*2 < k) dw.insert(tmp[i]);
			else up.insert(tmp[i]); 
		}
		cout << *(dw.rbegin()) << " ";
		for (int i = k; i < n; i++) {
			if (arr[i - k] <= *dw.rbegin()) {
				dw.erase(dw.find(arr[i-k]));
				if (arr[i] >= *up.begin()) {
					dw.insert(*up.begin());
					up.erase(up.begin());
					up.insert(arr[i]);
				} else dw.insert(arr[i]);
			} else {
				up.erase(up.find(arr[i-k]));
				if (arr[i] < *dw.rbegin()) {
					up.insert(*dw.rbegin());
					dw.erase(--dw.end());
					dw.insert(arr[i]);
				} else up.insert(arr[i]);
			}
			cout << *(dw.rbegin()) << " ";
		}	
	} else {
		for (int i = 0; i < n; i++) cout << arr[i] << " ";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
