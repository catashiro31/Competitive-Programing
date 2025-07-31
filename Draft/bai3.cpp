#include <iostream>
using namespace std;
int main() {
	int n,x,y1,y2,z;
	cin >> n >> x >> y1 >> y2 >> z;
	int arr[3]={n*x, n*y1+y2, z};
	int kq = 0;
	for (int i = 0; i < 3; i++) {
		if (arr[i] > kq) {
			kq = arr[i];
		}
	} 
	cout << kq;
	return 0;
}