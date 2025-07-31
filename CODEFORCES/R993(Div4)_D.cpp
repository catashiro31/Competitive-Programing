#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
void solve() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> sl(n+1,0);
		vector<int> kq(n,-1);
		queue<int> q;
		int cmax = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			q.push(i);
			if (!cmax) {
				kq[q.front()] = x; q.pop();
				sl[x]++; cmax = 1;
			} else {
				while (sl[x] < cmax) {
					kq[q.front()] = x; q.pop();
					sl[x]++;
				}
				cmax = max(cmax,sl[x]);
			} 
		}
		int k = 1;
		while (!q.empty()) {
			if (!sl[k]) {
				kq[q.front()] = k; q.pop();
				k++;
			} else k++;
		}
		for (int i = 0; i < n; i++) cout << kq[i] << " ";
		cout << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
