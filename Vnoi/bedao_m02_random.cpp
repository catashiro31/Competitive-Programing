#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int size = n/4;
        vector<int> sl(101,0);
    	while (n--) {
    		int x; cin >> x;
    		sl[x]++;
		}
		bool check = true;
		int sum = 0;
		vector<int> kq;
		for (int i = 100; i >= 0; i--) {
			sum += sl[i];
			if (sum > size) {
				check = false;
				break;
			}
			if (sum == size) {
				sum = 0;
				kq.push_back(i);
			}
		}
		if (check && kq.size() == 4) cout << kq[2] << " " << kq[1] << " " << kq[0];
		else cout << -1;
		cout << endl;
    }
    return 0;
}
