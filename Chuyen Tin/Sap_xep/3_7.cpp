#include <iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int a[n] = {};
	int b[m] = {};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int c[n+m] = {};
	int i = 0, j = 0, count = 0;
	while (true) {
		if (i < n and j < m) {
			if (a[i] < b[j]) {
				c[count] = a[i];
				count++;
				i++;
				continue;
			}
			if (a[i] > b[j]) {
				c[count] = b[j];
				count++;
				j++;
				continue;
			}
			if (a[i] == b[j]) {
				c[count] = a[i];
				count++;
				c[count] = b[j];
				count++;
				i++;
				j++;
				continue;
			}
		}
		if (i >= n) {
			for (j; j < m;j++) {
				c[count] = b[j];
				count++;
			}
			break;
		}
		if (j >= m) {
			for (i; i < n; i++) {
				c[count] = a[i];
				count++;
			}
			break;
		}
	}
	for (int i = 0; i < n+m; i++) {
		cout << c[i] << " ";
	}
}