#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
ll multiply_mod(ll a, ll b, ll m) {
    a %= m, b %= m;
    ll result = 0;
    while (b) {
        if (b % 2 == 1) result = (result + a) % m;
        a = (a * 2) % m;
        b = (b / 2) % m;
    }
    return result;
}
void solve() {

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
