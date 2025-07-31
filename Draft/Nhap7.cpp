#include <bits/stdc++.h>
using namespace std;
int dp[10000] ={};
int fibo(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (dp[n] != 0) return dp[n];
	return dp[n] = fibo(n-1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << f
}

