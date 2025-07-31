#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	long arr[n];
	for (long &x : arr) cin >> x;
	stack<pair<long,int>> mst;
	vector<int> kq(n,-1);
	for (int i = 0; i < n; i++) {
		if (kq[i] != -1) continue;
		if (mst.size() > 1)	{
			while(!mst.empty() && mst.top().first > arr[i]) {
				kq[mst.top().second] = i;
				mst.pop();
			}
		} else {
			while(!mst.empty() && mst.top().first < arr[i]) {
				kq[mst.top().second] = i;
				mst.pop();
			}
		}
		mst.push({arr[i],i});
	}
	while (!mst.empty()) {
		kq[mst.top().second] = n-1;
		mst.pop();
	}
	long sum = 0;
	for (int i = 0; i < n; i++) sum += kq[i]-i;
	cout << sum;
}
