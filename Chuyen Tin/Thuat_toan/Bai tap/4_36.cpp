#include <bits/stdc++.h>
using namespace std;
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	int n;
	inFile >> n;
	int arr[n];
	int prefixSum[n];
	for (int i = 0; i < n; i++) {
		inFile >> arr[i];
		if (i == 0) prefixSum[i] = arr[i];
		else prefixSum[i] = prefixSum[i-1] + arr[i];
	}
    inFile.close();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for (int len = 2; len <= n; len++) {
    	for (int i = 0; i <= n - len; i++){
    		int j = i + len - 1;
    		dp[i][j] = INT_MAX;
			for (int k = i; k <= j; k++) {
				if (i != 0) dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + prefixSum[j] - prefixSum[i-1]);
				else dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + prefixSum[j]);
			} 
		}
	}
	cout << dp[0][n-1];
}
