#include <iostream>
using namespace std;
int n;
long int arr[21][21];
long int bestarr = INT_MAX;
bool check[21];
long int d = 0;
int x[21];
long int best = INT_MAX;
void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (check[j] == true) {
			check[j] = false;
			x[i] = j;
			d += arr[x[i-1]][x[i]];
			if (i == n) {
				if (d+arr[x[i]][1] < best) best = d+arr[x[i]][1];
			} else {
				if (d+(n-i+1)*bestarr < best) Try(i+1);
			}
			check[j] = true;
			d-= arr[x[i-1]][x[i]];
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0 and arr[i][j] < bestarr) bestarr = arr[i][j];
		}
	}
	memset(check,true,sizeof(check));
	check[1] = false;
	x[1] = 1;
	Try(2);
	cout << best;
}