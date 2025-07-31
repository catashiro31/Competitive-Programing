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
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	sort(a.begin(),a.end());
	if (n < 3) cout << "Khong the tao ra day thoa man";
	else {
		int kq = 0;
		int i = 0, j = 2;
		while (j < n) {
			if (a[i] + a[i+1] > a[j]) kq = max(kq,j-i+1), j++;
			else i++, j++;
		}
		if (kq) cout << kq << endl;
		else cout << "Khong the tao ra day thoa man";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
