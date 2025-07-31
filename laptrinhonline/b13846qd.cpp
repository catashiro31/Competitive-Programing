#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int m, n; 
	cin >> m >> n;

	vector<long long> stp(m);
	for (long long &x : stp) {
		long u; 
		cin >> u;
		x = -u;
	}


	vector<long> consume(m - 1);
	for (long &x : consume) cin >> x;
	for (int i = 1; i < m; ++i) {
		stp[i] += stp[i - 1] + consume[i - 1];
	}

	vector<long> xe(n);
	for (long &x : xe) cin >> x;
	sort(xe.begin(), xe.end());
	vector<int> kq(m);
	auto tmp = xe.begin();
	
	for (int i = 0; i < m; ++i) {
		if (i < m - 1) {
			auto it = lower_bound(tmp, xe.end(), stp[i] + consume[i]);
			kq[i] = max(0, static_cast<int>(it - tmp));
			tmp = max(tmp,it); 
		} else kq[i] = static_cast<int>(xe.end() - tmp);
	}

	for (int x : kq) cout << x << " ";
}


