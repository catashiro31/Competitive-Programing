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
	int n, M; cin >> n >> M;
	set<int> s;
	vector<int> w(n);
	for (int &x : w) cin >> x;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				if (w[i] + w[j] + w[k] <= M) s.insert(w[i]+w[j]+w[k]);
			}
			if (w[i] + w[j] <= M) s.insert(w[i] + w[j]);
		}
		if(w[i] <= M) s.insert(w[i]);
	}
	cout << s.size();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
