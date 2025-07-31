#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int s1 = 0, s2 = 0;
	int b1 = 0, b2 = 0;
	int a1 = 0, a2 = 0;
	while (n--) {
		string x; cin >> x;
		int s,b,a;
		cin >> s >> b >> a;
		s1 += s; b1 += b; a1 += a;
		int u,v,w;
		cin >> u >> v >> w;
		s2 += u; b2 += v; a2 += w;
	}
	int x = round(10000.00*s2/s1); string tmp1 = "00" + to_string(x%100);
	int y = round(10000.00*b2/b1); string tmp2 = "00" + to_string(y%100);
	int z = round(10000.00*a2/a1); string tmp3 = "00" + to_string(z%100);
	cout << "Service: " << x/100 << "," << tmp1.substr(tmp1.size()-2) << "%." << endl; 
	cout << "Block: " << y/100 << "," << tmp2.substr(tmp2.size()-2) << "%." << endl;
	cout << "Spike: " << z/100 << "," << tmp3.substr(tmp3.size()-2) << "%." << endl; 
}
