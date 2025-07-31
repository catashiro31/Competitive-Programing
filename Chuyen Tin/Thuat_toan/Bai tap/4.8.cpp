#include <bits/stdc++.h>
using namespace std;
int n;
int arr[10];
int check[10];
int dem = 0;
long int tong[1024];
void Backtracking(int i) {
	if (i == n) {
		long int sum = 0;
		for (int j = 0; j < n; ++j) {
			tong[dem]+= check[j]*arr[j];
		}
		dem++;
		return;
	}
	for (int j = 0; j <= 1; ++j) {
		check[i] = j;
		Backtracking(i+1);
	} 
	
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int k = pow(2,n);
	Backtracking(0);
	sort(tong,tong+k);
	int kq = 0;
	for (int i = 1; i < k; ++i) {
		if (tong[i] - kq == 1) kq++;
		if (tong[i] - kq > 1) {
			cout << kq ;
			return 0;
		}
	}
	cout << kq+1;
	return 0;
}