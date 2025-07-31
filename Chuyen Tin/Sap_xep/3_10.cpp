#include <iostream>
using namespace std;
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void Quick_Sort(int arr[], int L, int H, int d[]) {
	int pivot = (H+L)/2;
	if (arr[L] > arr[H]) {
		swap(arr[L],arr[H]);
		swap(d[L],d[H]);
	}
	if (arr[L] > arr[pivot]) {
		swap(arr[L],arr[pivot]);
		swap(d[L],d[pivot]);
	}
	int i = L, j = H;
	do {
		while (arr[i] < arr[pivot]) i++;
		while (arr[j] > arr[pivot]) j--;
		if (i <= j) {
			swap(arr[i],arr[j]);
			swap(d[i],d[j]);
			i++; j--;
		}
	} while (i <= j);
	if (L < j) Quick_Sort(arr,L,j,d);
	if (i < H) Quick_Sort(arr,i,H,d);
}
int main() {
	int N;
	cin >> N;
	int x[N] = {};
	int d[N] = {};
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> d[i];
	}
	Quick_Sort(x,0,N-1,d);
	int kq = 0;
	for (int i = 0; i < N; i++) {
		if (i < N-1) {
			if (x[i]+d[i] <= x[i+1]) kq+=d[i];
			if (x[i]+d[i] > x[i+1]) {
				kq += x[i+1]-x[i];
				if (x[i]+d[i]-d[i+1]-x[i+1] > 0) {
					d[i+1] = x[i]-x[i+1]+d[i];
				}
			}
 		} else {
			kq+=d[i];
		}
	}
	cout << kq;
}