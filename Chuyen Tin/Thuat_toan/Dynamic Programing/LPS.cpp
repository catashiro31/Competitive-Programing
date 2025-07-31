#include <bits/stdc++.h>
using namespace std;
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	string xau;
	inFile >> xau;
    inFile.close();
    int size = xau.length();
    int arr[size+1][size+1];
    int ans = 0;
    memset(arr,0,sizeof(arr));
    xau = " " + xau;
    for (int i = 1; i <= size; i++) arr[i][i] = 1;
    for (int len = 2; len <= size; len++) {
    	for (int i = 1; i <= size - len +1; i++) {
    		int j = i + len - 1;
    		if (len == 2 and xau[i] == xau[j])	{
				arr[i][j] = 1;
				ans = max(ans,len);
			}
    		if (len > 2 and xau[i] == xau[j] and arr[i+1][j-1] == 1) {
				arr[i][j] = 1;
				ans = max(ans,len);
			}
		}
	}
	cout << ans;
}
