#include <iostream>
using namespace std;
// Tìm kiếm nhị phân - Sử dụng khi dãy đã được sắp xếp - Độ phức tạp O(log(n))
int Binary_Search(int arr[], int x, int size) {
	int start = 0, end = size-1;
	int mid;
	while (start != end) {
		mid = int((end-start)/2) + start;
		if (arr[mid] < x) {
			start = mid + 1;
		}
		if (arr[mid] > x) {
			end = mid - 1;
		}
		if (arr[mid] == x) {
			return mid+1;
		}
	}
	return start+1;
}
void Advanced_Binary_Search(int arr[], int x, int start, int end) {
	int mid = (end-start)/2+start;
	if (arr[mid] == x) cout << mid+1 << endl;
	if (start != end) {
		if (start <= mid-1) Advanced_Binary_Search(arr,x,start,mid-1);
		if (end >= mid+1) Advanced_Binary_Search(arr,x,mid+1,end);
	}
	return;
}
// Tìm kiếm tuần tự/Tìm kiếm tuyến tính - Độ phức tạp O(n)
int Linear_Search(int arr[],int x, int size) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == x) return i+1;
	}
	return 0;
}
//
int main() {
	int n,x;
	cin >> n >> x;
	int arr[n] = {};
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	Advanced_Binary_Search(arr,x,0,n-1);
}