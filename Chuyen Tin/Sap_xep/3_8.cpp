#include <iostream>
using namespace std;
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void Quick_Sort(int arr[], int L, int H) {
	int pivot = (H+L)/2;
	if (arr[L] > arr[H]) swap(arr[L],arr[H]);
	if (arr[pivot] < arr[L]) swap(arr[pivot],arr[L]);
	if (arr[pivot] > arr[H]) swap(arr[pivot],arr[H]);
	int i = L, j = H; 
	do {
		while (arr[i] < arr[pivot]) i++;
		while (arr[j] > arr[pivot]) j--;
		if (i <= j) {
			swap(arr[i],arr[j]);
			i++; j--;
		}
	} while(i <= j);
	if (L < j) Quick_Sort(arr,L,j);
	if (i < H) Quick_Sort(arr,i,H);
	return;
}
int main() {
	int n;
	cin >> n;
	int arr[n] = {};
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	Quick_Sort(arr,0,n-1);
	int count = arr[int(n/2)-1];
	if (n % 2 != 0) {
		cout << arr[int(n/2)];
	} else {
		while (count <= arr[int(n/2)]) {
			cout << count << " ";
			count++;
		}
	}
}