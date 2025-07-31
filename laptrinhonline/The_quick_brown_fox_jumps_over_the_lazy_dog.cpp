#include <bits/stdc++.h>
using namespace std;
int main() {
	string xau;
	getline(cin,xau);
	int arr[26];
	memset(arr,0,sizeof(arr));
	for (int i = 0; i < xau.length(); i++) {
		if (xau[i] >= 97 and xau[i] <= 122) {
			arr[xau[i]-97] ++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] == 0) {
			cout << "false";
			return 0;
		}
	}
	cout << "true";
	return 0;
}