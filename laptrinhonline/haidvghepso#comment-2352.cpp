#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string x, y; cin >> x >> y;
//	int i = 0, j = 0;
//	string zmin = "";
//	while (i < x.length() && j < y.length()) {
//		if (x[i] > y[j]) {
//			zmin = zmin + y[j];
//			j++;
//		} else {
//			zmin = zmin + x[i];
//			i++;
//		}
//		if (i == x.length()) {
//			for (j; j < y.length(); j++) zmin = zmin + y[j];
//		} else {
//			for (i; i < x.length(); i++) zmin = zmin + x[i];
//		}
//	}
//	cout << zmin << endl;
//	i = 0; j = 0;
//	string zmax = "";
//	while (i < x.length() && j < y.length()) {
//		if (x[i] > y[j]) {
//			zmax = zmax + x[i];
//			i++;
//		} else {
//			zmax = zmax + y[j];
//			j++;
//		}
//		if (i == x.length()) {
//			for (j; j < y.length(); j++) zmax = zmax + y[j];
//		} else {
//			for (i; i < x.length(); i++) zmax = zmax + x[i];
//		}
//	}
//	cout << zmax;
	cout << x << " " << y;
}
