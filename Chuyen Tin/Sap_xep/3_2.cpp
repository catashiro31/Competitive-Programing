#include <iostream>
using namespace std;
void Binary_SearchA(int arr[], int x, int start, int end) {
	int mid, tmp = -arr[x];
	mid = (end-start)/2+start;
	if (arr[mid] == tmp and mid != x) cout << x+1 << " " << mid+1 << endl;
	if (start != end) {
		if (start <= mid-1) Binary_SearchA(arr,x,start,mid-1);
		if (end >= mid+1) Binary_SearchA(arr,x,mid+1,end);
	}
	return;
}
void A(int arr[], int n) {
	int count = 0;
	while (arr[count] <= 0) {
		Binary_SearchA(arr,count,0,n-1);
		count++;
	}
	return; 
}
void Binary_SearchB(int arr[],int start, int end,const int kq1,const int kq2) {
	int mid, tmp = arr[kq1] + arr[kq2];
	mid = (end-start)/2+start;
	if (arr[mid]+tmp == 0 and mid != kq2) cout << kq1+1 << " " << kq2+1 <<  " " << mid+1 << endl;
	if (start != end) {
		if (start <= mid-1) Binary_SearchB(arr,start,mid-1,kq1,kq2);
		if (end >= mid+1) Binary_SearchB(arr,mid+1,end,kq1,kq2);
	}
	return;	
}
void B(int arr[], int n) {
	for (int i = 0; i < n-2; i++) {
		for (int j = i+1; j < n-1; j++) {
			Binary_SearchB(arr,j+1,n-1,i,j);
		}
	}
	return;
}
void C(int arr[], int size) {
	int L,H;
	for (int i = 0; i < size-1; i++) {
		if (arr[i] < 0 and arr[i+1] >= 0) {
			L = i;
			H = i+1;
			break;
		}
	}
	int dem1,dem2;
	while (0 <= L and H <= size-1) {
		if (arr[H] == -arr[L]) {
			dem1 = arr[H];
			dem2 = H;
			while (-arr[L] == dem1 and L >= 0) {
				H = dem2;
				while (arr[H] == dem1 and H <= size-1) {
					cout << L+1 << " " << H+1 << endl;
					H++;
				}
				L--;
			}
			continue;
		}
		if (arr[H] > -arr[L]) L--;
		if (arr[H] < -arr[L]) H++;
	}
	return;
}
void D(int arr[], int size) {
	int sum, L, H,dem1,dem2,dem3;
	for (int i = 0; i < size-2; i++) {
		L = i+1;
		H = size-1;
		while (L < H) {
			dem1 = arr[L];
			dem2 = arr[H];
			dem3 = H;
			sum = arr[i] + arr[L] + arr[H];
			if (sum == 0) {
				while (arr[L] == dem1) {
					H = dem3;
					while (arr[H] == dem2) {
						cout << i+1 << " " << L+1 << " " << H+1 << endl;
						H--;
					}
					L++;
				}
			}
			if (sum < 0) L++;
			if (sum > 0) H--;
		}
	}
}
int main() {
	int n;
	cin >> n;
	int arr[n] = {};
	for (int i = 0 ; i < n; i++) {
		cin >> arr[i];
	}
	cout << "A\n";
	A(arr,n);
	cout << endl;
	cout << "B\n";
	B(arr,n);
	cout << endl;
	cout << "C\n";
	C(arr,n);
	cout << endl;
	cout << "D\n";
	D(arr,n);	
}