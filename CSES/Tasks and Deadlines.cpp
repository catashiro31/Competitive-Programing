#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	vector<pair<int,int>> arr(n);
	for (int i = 0; i < n; i++) {
		int a, d; cin >> a >> d;
		arr[i] = {a,d};
	}
	sort(arr.begin(),arr.end());
	long time = 0, bonus = 0;
	for (int i = 0; i < n; i++) {
		time += arr[i].fi;
		bonus += arr[i].se - time;
	}
	cout << bonus;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
