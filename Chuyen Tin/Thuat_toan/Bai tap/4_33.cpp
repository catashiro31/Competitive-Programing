#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
void Merge(int L, int mid, int H) {
	int tmp[H-L+1];
	int count = 0;
	int i = L, j = mid+1;
	while (true) {
		while (arr[i] <= arr[j] and i <= mid) {
			tmp[count] = arr[i];
			++i;
			++count;
		}
		if (i > mid) {
			while (j <= H) {
				tmp[count] = arr[j];
				++j;
				++count;
			}
			break;
		}
		while (arr[i] >= arr[j] and j <= H) {
			tmp[count] = arr[j];
			++j;
			++count;
		}
		if (j > H) {
			while (i <= mid) {
				tmp[count] = arr[i];
				++i;
				++count;
			}
			break;
		}
	}
	for (int x = L; x <= H; x++) {
		arr[x] = tmp[x-L];
	}
}
void Merge_Sort(int L, int H) {
	if (L < H) {
		int mid = (L+H)/2;
		Merge_Sort(L,mid);
		Merge_Sort(mid+1,H);
		Merge(L,mid,H);
	}
}
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	int n, k;
	inFile >> n >> k;
	for (int i = 0; i < n; i++) {
		int tmp;
		inFile >> tmp;
		arr.push_back(tmp);
	}
    inFile.close();
    Merge_Sort(0,n-1);
    cout << arr[k-1];
}
