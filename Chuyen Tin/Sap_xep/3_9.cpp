#include <iostream>
using namespace std;
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
	return;
}
void Quick_Sort(int arr[],int L, int H) {
	int pivot = (H+L)/2;
	int i = L, j = H;
	if (arr[L] > arr[H]) swap(arr[L],arr[H]);
	if (arr[L] > arr[pivot]) swap(arr[L],arr[pivot]);
	do {
		while (arr[i] < arr[pivot]) i++;
		while (arr[j] > arr[pivot]) j--;
		if (i <= j) {
			swap(arr[i],arr[j]);
			i++; j--;
		} 
	} while (i <= j);
	while (L < j) Quick_Sort(arr,L,j);
	while (i < H) Quick_Sort(arr,i,H);
}
int main() {
	int N;
	cin >> N;
	int x[N] = {};
	int y[N] = {};
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}
	cout << endl;
	Quick_Sort(x,0,N-1);
	Quick_Sort(y,0,N-1);
	if (N%2 != 0) {
		cout << x[int(N/2)] << " " << y[int(N/2)];
	} else {
		for (int i = x[int(N/2)-1]; i <= x[int(N/2)]; i++) {
			for (int j = y[int(N/2)-1]; j <= y[int(N/2)]; j++) {
				cout << i << " " << j << endl;
			}
		}
	}
}