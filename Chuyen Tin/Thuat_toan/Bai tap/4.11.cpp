#include <bits/stdc++.h>
using namespace std;
int N; 
int dem = 0;
int isSNT(int a) {
	if (a == 1) return 0;
	for (int i = 2; i <= sqrt(a); ++i) {
		if (a % i == 0) return 0;
	}
	return 1;
}
//int Sochuso(int a) {
//	int dem = 0;
//	while (a/10 == 0) {
//		dem++;
//		a/=10;
//	}
//	return dem;
//}
int kq = 0;
void Backtracking(int i) {
	if (i == N) {
		dem++;
		cout << kq << endl;
		return;
	}
	for (int j = 0; j < 10; ++j) {
		if (j == 0 and i == 0) continue;
		kq = kq*10+j;
		if (isSNT(kq) == 1) Backtracking(i+1);
		kq/=10;
	}
}
int main() {
	cin >> N;
	Backtracking(0);
	cout << dem;
}