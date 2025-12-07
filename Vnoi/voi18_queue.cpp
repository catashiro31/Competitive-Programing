#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

bool check(int k, int m, vector<pair<int,int>>& arr) {
    vector<pair<int,int>> tmp;
    for(int i=0; i<k; i++) tmp.push_back(arr[i]);

    sort(all(tmp));

    priority_queue<int, vector<int>, greater<int>> pq;

    int current_spot = 0;
    int i = 0;

    while(i < k || !pq.empty()) {
        if (pq.empty()) {
            current_spot = max(current_spot, tmp[i].fi);
        }

        while(i < k && tmp[i].fi <= current_spot) {
            pq.push(tmp[i].se);
            i++;
        }

        int deadline = pq.top();
        pq.pop();

        if (deadline < current_spot || current_spot > m) return false;

        current_spot++;
    }

    return true;
}

void solve() {
	int m, n; cin >> m >> n;
	vector<pair<int,int>> arr(n);
	for (int i = 0; i < n; i++) {
		int u, v; cin >> u >> v;
		arr[i] = {u,v};
	}
	int l = 1, r = n, kq = 0;
	while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid, m, arr)) {
            kq = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << kq << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
