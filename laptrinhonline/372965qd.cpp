#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
int len(long x) {
	int ans = 0;
	while (x) ans++, x/=10;
	return ans;
}
long tranl(string x) {
	reverse(x.begin(),x.end());
	long ans = 0, tmp = 1;
	for (int i = 0; i < x.length(); i++) {
		ans += tmp*(x[i] - '0');
		tmp *= 10;
	}
	return ans;
}
void solve() {
	vector<long> arr;
	while (true) {
		long x; cin >> x;
		if (x == -1) break;
		arr.pb(x);
	}
	int n = arr.size();
	ll kq = arr[0];
	long tmp = pow(10,len(arr[0]));
	for (int i = 1; i < n; i++) {
		arr[i] %= tmp;
		if (arr[i] > arr[i-1]) {
			string a = to_string(arr[i]), b = to_string(arr[i-1]);
			if (a[0] > b[0]) tmp/=10, a[0] = '0';
			else {
				for (int i = a.length()-1; i > 0; i--){
					string c = a; c[i] = '0';
					if (c < b) {
						a = c;
						break;
					}
				} 
			}
			arr[i] = tranl(a); 
		}
		kq += arr[i];
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
