#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define INF INT_MAX
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	set<int> s;
	map<int,int> sl;
	for (int x : a) {
		sl[x]++;
		s.insert(x);
	}
	vector<pair<int,int>> kq;
	for (int x : s) {
		kq.push_back({-sl[x],x});
	}
	sort(kq.begin(),kq.end());
	cout << kq[0].second << " " << kq[1].second << " " << kq[2].second; 
}
