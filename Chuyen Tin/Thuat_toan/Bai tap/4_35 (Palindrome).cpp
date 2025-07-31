#include <bits/stdc++.h>
using namespace std;
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	string xau;
	inFile >> xau;
    inFile.close();
    int n = xau.length();
    xau = " " + xau;
    int arr[n+1][n+1];
    memset(arr,0,sizeof(arr));
    for (int len = 2; len <= n; len++) {
    	for (int i = 1; i <= n - len + 1; i++) {
    		int j = i + len - 1;
    		if (xau[i] == xau[j]) arr[i][j] = arr[i+1][j-1];
    		if (xau[i] != xau[j]) arr[i][j] = min(arr[i+1][j] + 1, arr[i][j-1] + 1);
		}
	}
	cout << arr[1][n];
}
