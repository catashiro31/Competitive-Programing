#include <bits/stdc++.h>
using namespace std;
int Sosanh(int w1, int w2, int d1, int d2) {
	if (w1 > w2) return 1;
	if (w1 < w2) return -1;
	if (d1 < d2) return 1;
	if (d1 > d2) return -1;
	return 0;
}
void QuickSort(int d[], int w[], int L, int H) {
	if (L == H) return;
	int mid = (L+H)/2;
	if (Sosanh(w[mid],w[L],d[mid],d[L]) == -1) {
		swap(w[mid],w[L]);
		swap(d[mid],d[L]);
	} 
	if (Sosanh(w[mid],w[H],d[mid],d[H]) == 1) {
		swap(w[mid],w[H]);
		swap(d[mid],d[H]);
	}
	int i = L, j = H;
	do {
		while (Sosanh(w[i],w[mid],d[i],d[mid]) == 1) i++;
		while (Sosanh(w[j],w[mid],d[j],d[mid]) == -1) j--;
		if (i <= j) {
			swap(w[i],w[j]);
			swap(d[i],d[j]);
			i++; j--;
		}
	} while (i <= j);
	if (L < j) return QuickSort(d,w,L,j);
	if (i < H) return QuickSort(d,w,i,H);
}
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	int N;
	inFile >> N;
	int d[N], w[N];
	for (int i = 0; i < N; i++) inFile >> d[i] >> w[i];
    inFile.close();
    QuickSort(d,w,0,N-1);
    for (int i = 0; i < N; i++) cout << d[i] << " " << w[i] << endl;
}
