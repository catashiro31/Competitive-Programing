#include <iostream> 
using namespace std;
long long UCLN(long long a, long long b) {
	if (a == 0) return b;
	if (b == 0) return a;
	return UCLN(b,a%b);
}
int main() {
	int n;
	cin >> n;
	long long arr[n] = {};
	long long kq;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];		
	}
	kq = arr[0];
	for (int i = 1; i < n; i++) {
		kq = UCLN(kq,arr[i]);
	}
	cout << kq;
	return 0;
}