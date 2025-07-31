#include <bits/stdc++.h>
using namespace std;
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	int N;
	inFile >> N;
	vector<int> A(N);
	for (int &x : A) inFile >> x;
	vector<int> L(N,1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] < A[j]) {
				L[i] = max(L[i],L[j]+1);
			}
		}
		if (i != 0) L[i] = max(L[i],L[i-1]);
	}
	cout << L[N-1];
	inFile.close();
}