#include <iostream>
using namespace std;
long int power(long int a, long int n) {
	long int tmp;
	if (n==1) {
		return a;
	} else {
		tmp = power(a,int(n/2));
		if (n % 2 == 1) return tmp*tmp*a;
		else return tmp*tmp;
	}
}
int main() {
	long int a,n;
	cin >> a >> n;
	cout << power(a,n);
}