#include <bits/stdc++.h>
using namespace std;
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	int N;	inFile >> N;
	vector<int> A(N);
	for (int &x : A) inFile >> x;
	vector<int> Left(N,1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] < A[j]) {
				Left[i] = max(Left[i],Left[j]+1);
			}
		}
		if (i != 0) Left[i] = max(Left[i],Left[i-1]);
	}
	vector<int> Right(N,1);
	for (int i = N-1; i >= 0; i--) {
		for (int j = N-1; j > i; j--) {
			if (A[i] < A[j]) {
				Right[i] = max(Right[i],Right[j]+1);
			}
		}
		if (i != N-1) Right[i] = max(Right[i],Right[i+1]);
	}
	vector<int> MaxLoi(N);
	for (int i = 0; i < N; i++) MaxLoi[i] = Left[i] + Right[i];
	int kq = *max_element(MaxLoi.begin(),MaxLoi.end())-1 ;
	cout << kq;
	inFile.close();
}