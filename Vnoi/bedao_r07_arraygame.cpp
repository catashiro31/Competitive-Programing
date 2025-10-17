#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
deque<int> dq;
vector<bool> visited;
int n;
int kq1= -1, kq2 = -1;
void backtrack(int u, int dst, const vector<int> &a) {
	if (u == dst) {
		int i = 0;
		int res1 = 0, res2 = 0;
		deque<int> tmp = dq;
		while (!tmp.empty()) {
			int cmax = max(tmp.front(), tmp.back());
			if (cmax == tmp.front()) tmp.pop_front();
			else tmp.pop_back();
			if (i&1) res2+=cmax;
			else res1+=cmax;
			i++;
		}
		if (res2 > kq2) kq2 = res2, kq1 = res1;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		dq.push_back(a[i]);
		backtrack(u+1,dst,a);
		dq.pop_back();
		visited[i] = false;
	}
}
void solve() {
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	visited.assign(n,0);
	backtrack(0,n,a);
	cout << kq2 << " " << kq1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
