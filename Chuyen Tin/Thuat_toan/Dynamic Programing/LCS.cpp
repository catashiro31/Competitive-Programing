#include <bits/stdc++.h>
using namespace std;
int cmax(int a, int b, int c) {
	if (c >= b and c >= a) return c;
	if (a >= b and a >= c) return a;
	return b;
}
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	int N, M;
	inFile >> N >> M;
	vector<int> a(N); 
	for (int &x : a) inFile >> x;
	vector<int> b(M);
	for (int &x : b) inFile >> x;
    inFile.close();
    vector<vector<int>> arr(N+1,vector<int>(M+1,0));
    int x;
    for (int i = 1; i <= N; i++) {
    	for (int j = 1; j <= M; j++) {
    		if (a[i-1] == b[j-1]) x = 1;
    		else x = 0;
    		arr[i][j] = cmax(arr[i-1][j],arr[i][j-1],arr[i-1][j-1]+x);
		}
	}
	cout << arr[N][M];
}
