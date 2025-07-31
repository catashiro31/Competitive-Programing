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
	long k; cin >> k;
	map<long,int> c;
	c[0] = 1;
	for (long i = 1; i*i <= k; i++) c[i*i] = 1;
	long sl = 0;
	for (long i = 1; i*i <= k; i++) {
		if (c[k-i*i]) sl++; 
	}
	cout << sl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
