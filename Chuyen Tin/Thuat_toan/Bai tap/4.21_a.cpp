#include <bits/stdc++.h>
using namespace std;
int N, D;
int sum = 0;
bool check[10];
int need = 1;
int kq = INT_MAX;
void Try (int i, vector<int> S) {
	if (i == N) {
		if (need < kq) kq = need;
		return;
	}
	for (int j = 0; j < N; j++) {
		if (check[j] == true) {
			check[j] = false;
			sum += S[j];
			if (need < kq) {
				if (sum > D) {
					int tmp = sum;
					sum = 0;
					need++;
					Try(i+1,S);
					need--;
					sum = tmp;
				} else {
					Try(i+1,S);
				}
			}
			sum -= S[j];
			check[j] = true;
		}
	}
}
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	inFile >> N >> D;
	vector<int> S (N);
	memset(check,true,sizeof(check));
	for (int i = 0; i < N; i++) {
		inFile >> S[i];
	}
    inFile.close();
    Try(0,S);
    cout << kq;
}
