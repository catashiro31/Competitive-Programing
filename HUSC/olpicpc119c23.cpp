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

struct info {
	int l, r, x, id;
};

void solve() {
	int n, q; cin >> n >> q;
	vector<pair<int,int>> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i].fi;
		h[i].se = i+1;
	}
	sort(all(h),[](auto &a, auto &b){
		return a.fi > b.fi;	
	});
	vector<info> query(q);
	for (int i = 0; i < q; i++) {
		cin >> query[i].l >> query[i].r >> query[i].x;
		query[i].id = i;
	}
	sort(all(query),[](auto &a, auto &b){
		if (a.x != b.x) return a.x > b.x;
		return a.l < b.l;	
	});
	vector<int> BIT1(MAXN,0), BIT2(MAXN,0);
	
	auto update = [](vector<int> &BIT, int val) {
		for (; val < MAXN; val += val & (-val)) BIT[val]++;	
	};
	
	auto getv = [&](const vector<int> &BIT, int val) {
		int res = 0;
		for (; val; val -= val & (-val)) res += BIT[val];
		return res;
	};
	
	vector<bool> used(n+1,false);
	vector<int> kq(q);
	int j = 0;
	for (int i = 0; i < q; i++) {
		while (j < n && h[j].fi > query[i].x) {
			used[h[j].se] = true;
			update(BIT1,h[j].se);
			if (used[h[j].se-1]) update(BIT2,h[j].se-1);
			if (used[h[j].se+1]) update(BIT2,h[j].se);
			j++;
		}
		kq[query[i].id] = (getv(BIT1,query[i].r) - getv(BIT1,query[i].l-1)) - (getv(BIT2,query[i].r-1) - getv(BIT2,query[i].l-1));
	}
	for (int x : kq) cout << x << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
