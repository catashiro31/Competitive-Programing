#include <iostream>
using namespace std;
int main() {
	long int n,x,y1;
	long long y2,z;
	cin >> n >> x >> y1 >> y2 >> z;
	long long arr[3]={n*x, n*y1+y2, z};
	long long kq = n*x;
	for (long int i = 0; i < 3; i++) {
		if (arr[i] < kq) {
			kq = arr[i];
		}
	} 
	cout << kq;
	return 0;
}