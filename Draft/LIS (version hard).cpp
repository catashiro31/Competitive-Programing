#include <bits/stdc++.h>
using namespace std;
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	int n; inFile >> n;
	vector<int> a(n);
	for (int &x : a) inFile >> x;
	vector<int> b(n+1, INT_MAX);
	b[0] = INT_MIN;
	int result = 0;
	for (int x : a) {
		int k = lower_bound(b.begin(),b.end(),x) - b.begin();
		b[k] = x;
		result= max(result,k);
	}
	cout << result << endl;
	for (int i = 1; i <= result; i++) cout << b[i] << " ";
    inFile.close();
}
