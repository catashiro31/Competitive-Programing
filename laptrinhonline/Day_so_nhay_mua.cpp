#include <iostream>
using namespace std;
void Min_Search(int arr[],int L, int H, int &cmin) {
	if (L == H) {
		if (cmin > arr[L]) cmin = arr[L];
		return;
	} else {
		int mid = (L+H)/2;
		if (cmin > arr[mid]) cmin = arr[mid];
		Min_Search(arr,L,mid,cmin);
		Min_Search(arr,mid+1,H,cmin);
	}
}
void Max_Search(int arr[],int L, int H, int &cmax) {
	if (L == H) {
		if (cmax < arr[L]) cmax = arr[L];
		return;
	} else {
		int mid = (L+H)/2;
		if (cmax < arr[mid]) cmax = arr[mid];
		Max_Search(arr,L,mid,cmax);
		Max_Search(arr,mid+1,H,cmax);
	}
}
int dolechtoida(int arr[], int a, int b) {
	int min = arr[a], max = arr[a];
	Min_Search(arr,a,b,min);
	Max_Search(arr,a,b,max);
	return max-min;
}
int main() {
	int n;
	cin >> n;
	int arr[n] = {};
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n-i; j++) {
			sum += dolechtoida(arr, j, j+i);
		}
	}
	cout << sum;
}