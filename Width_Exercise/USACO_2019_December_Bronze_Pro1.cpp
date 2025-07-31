#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "gymnastics";
void solve() {
	int k, n; cin >> k >> n;
	vector<vector<int>> p(n,vector<int>(k));
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			int x; cin >> x;
			x--;
			p[x][i] = j;
		}
	}
	int kq = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i-1; j >= 0; j--) {
			int c = 0;
			for (int z = 0; z < k; z++) {
				if (p[i][z] > p[j][z]) c++;
			}
			if (!c || c == k) kq++;
		}
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen((NoF + ".in").c_str(),"r",stdin);
	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
