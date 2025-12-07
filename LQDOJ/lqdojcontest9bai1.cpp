#include<bits/stdc++.h>
using namespace std;
#define psb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
int BIT[100005];
struct Querie {
	int x, l, r, id;	
};

void _update(int id) {
	for (; id < 100005; id += id&(-id)) BIT[id]++; 
}

int _get(int id) {
	int res = 0;
	for (; id; id -= id&(-id)) res += BIT[id];
	return res;
}

void solve() {
	vector<pair<int,int>> arr;
	arr.psb({0,1});
	for (int i = 2; i <= 1e5; i++) {
		int val = 0;
		for (int j = 1; j*j <= i; j++) {
			if (i%j != 0) continue;
			val += j;
			if (j != 1 && i/j != j) val += i/j;
		}
		arr.psb({val,i});
	}
	sort(arr.rbegin(),arr.rend());
	vector<Querie> query;
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r, x; cin >> l >> r >> x;
		query.psb({x,l,r,i});
	}
	sort(all(query),[](auto &a, auto &b){
		return a.x > b.x;
	});
	int p = 0;
	vector<int> kq(q);
	for (int i = 0; i < q; i++) {
		int limit_x = query[i].x;
		while (p < arr.size() && arr[p].fi > limit_x) {
			_update(arr[p].se); p++;
		}
		kq[query[i].id] = _get(query[i].r) - _get(query[i].l-1);
	}
	for (int i = 0; i < q; i++) cout << kq[i] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
	while(t--) solve();
}