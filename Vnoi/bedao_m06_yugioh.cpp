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
	int n, X; cin >> n >> X;
	vector<bool> snt(X+1,true);
	snt[0] = false, snt[1] = false;
	for (int i = 2; i*i <= X; i++) {
		if (!snt[i]) continue;
		for (int j = i*i; j <= X; j+=i) snt[j] = false;
	}
	int sl = 0;
	vector<long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > 0 && a[i] <= X && snt[a[i]]) sl++;
	}
	int tmp = 0, kq = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0 && a[i] <= X && snt[a[i]]) tmp++;
		if (i == sl-1) {
			kq = min(kq,sl-tmp);
		}
		if (i >= sl) {
			if (a[i-sl] > 0 && a[i-sl] <= X && snt[a[i-sl]]) tmp--;
			kq = min(kq,sl-tmp);
		}
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
