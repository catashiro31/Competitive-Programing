#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int a,b; cin >> a >> b;
	vector<bool> sang(200001,true);
	sang[0] = false, sang[1] = false;
	for (int i = 2; i <= sqrt(200000); i++) {
		if (sang[i]) {
			for (int j = i*i; j <= 200000; j += i) sang[j] = false;
		}
	}
	for (int i = a; i <= b; i++) {
		if (sang[i]) cout << i << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
