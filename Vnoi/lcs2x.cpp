#include<bits/stdc++.h>
using namespace std;
#define psb push_back
#define all(x) x.begin(), x.end()
int BIT[1505][1505];
int m, n, sz;

void update(int x, int y, int val) {
	for (x; x <= n; x += x&(-x)) { // Dùng global n
		for (y; y <= sz; y += y&(-y)) BIT[x][y] = max(BIT[x][y],val); // Dùng global sz
	}
}

int query(int x, int y) {
	int res = 0;
	for (x; x > 0; x -= x&(-x)) {
		for (y; y > 0; y -= y&(-y)) res = max(res, BIT[x][y]);
	}
	return res;
}

void solve() {
    // 1. Dùng memset nhanh hơn
	memset(BIT, 0, sizeof(BIT));
    
	cin >> m >> n;
    
    // 2. Dùng vector là C++ chuẩn
	vector<int> a(m + 1), b(n + 1);
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
    
	vector<int> arr (b.begin() + 1, b.end()) ; // Cách khởi tạo vector từ vector
	sort(all(arr));
	arr.erase(unique(all(arr)),arr.end());
	sz = arr.size(); // Set global sz
    
	int kq = 0;
	for (int i = 1; i <= m; i++) {
		vector<tuple<int, int, int>> buffer;	
		for (int j = 1; j <= n; j++) {
			if (a[i] != b[j]) continue;
			int rank_query = upper_bound(all(arr),a[i]/2) - arr.begin() ;
			int cur = query(j-1,rank_query);
			kq = max(kq, cur+1);
			int rank_update = lower_bound(all(arr),a[i]) - arr.begin()+1;
			buffer.psb({j,rank_update,cur+1});
			
		}
		for (auto& [j, rank, val] : buffer) {
			update(j, rank, val);
		}
	}
	cout << kq << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1; cin >> t;
	while(t--) solve();
}