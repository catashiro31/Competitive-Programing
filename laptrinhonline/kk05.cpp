#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
int len(ll n) {
	int sl = 0;
	while (n) sl++, n/=10;
	return sl;
}
void solve() {
	ll t; cin >> t;
	ll kq = 0;
	while (t) {
		ll re = t/pow(10,len(t)-1);
		ll tmp = 1;
		while(len(tmp) != len(t)) tmp = tmp*10 + 1;
		if (abs(t-re*tmp) > abs(t-(re-1)*tmp) && abs(t-(re+1)*tmp) > abs(t-(re-1)*tmp)) re -= 1;
		else if (abs(t-(re+1)*tmp) < abs(t-re*tmp) && abs(t-(re+1)*tmp) < abs(t-(re-1)*tmp)) re += 1; 
		kq += re*(len(t));
		t -= re*tmp;
		t = abs(t);
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
// 	freopen("input.txt","r",stdin);
	solve();
}
	
