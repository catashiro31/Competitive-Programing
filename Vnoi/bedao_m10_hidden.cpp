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
	long a, T; cin >> a >> T;
	vector<long> snt;
	vector<bool> sang(1e5,true);
	for (int i = 2; i < 1e5; i++) {
        if (!sang[i]) continue;
        snt.push_back(i);
        for (long long j = 1LL * i * i; j < 1e5; j += i) 
            sang[j] = false;
    }
	int i = 0;
	while (i < snt.size() && T % snt[i]) i++;
	if (i == snt.size() || T % a) {
		cout << -1 ;
		return;
	}
	long x = 1;
	while (T % snt[i] == 0) T /= snt[i], x *= snt[i];
	cout << x << " " << T;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
