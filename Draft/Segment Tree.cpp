#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
const int maxn = 1000000;	
int t[maxn*4], a[maxn];
void build(int id, int l, int r) {
	if (l == r) {
		t[id] = a[l];
		return;
	}
	int m = (l+r)/2;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	t[id] = t[id*2] + t[id*2+1];
}
int get(int id, int l, int r, int u, int v) {
	if (v < l || u > r) return 0; // Nam ngoai
	if (u <= l && v >= r) return t[id];  // Nam trong
	// Giao nhau 
	int m = (l+r)/2;
	int t1 = get(id*2,l,m,u,v);
	int t2 = get(id*2+1,m+1,r,u,v);
	return t1 + t2;
}
void update(int id, int l, int r, int pos, int value) {
	if (pos < l || pos > r) return;
	if (l == r) {
		t[id] = value;
		a[pos] = value;
		return;
	}
	int m = (l+r) >> 1;
	update(id*2,l,m,pos,value);
	update(id*2+1,m+1,r,pos,value);
	t[id] = t[id*2] + t[id*2+1];
}
void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int u = 3, v = 7;
	build(1,1,n);
	cout << get(1,1,n,u,v) << endl;
	int p, val; cin >> p >> val;
	update(1,1,n,p,val);
	cout << get(1,1,n,u,v) << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
