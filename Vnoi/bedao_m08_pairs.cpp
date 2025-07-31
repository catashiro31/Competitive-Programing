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
	vector<int> sla(1e7+1,0);
	for (int i = 1; i*i <= 1e7; i++) {
		for (int j = i*(i+1); j <= 1e7; j+=i) sla[j]++;
	}
	cout << sla[10];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
