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
	double x, y; cin >> x >> y;
	double a = x+y - sqrt(x*x*2 + x*y*2);
	double b = y - a;
	double c = sqrt(pow(a,2)+pow(b,2));
	if (b < a) swap(a,b);
	cout << fixed << setprecision(9) << a << " ";
	cout << fixed << setprecision(9) << b << " ";
	cout << fixed << setprecision(9) << c;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
