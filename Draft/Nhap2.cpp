#include<stdio.h>
bool prime(int n);

int main() {
	int n; scanf("%d",&n);
	if (prime(n)) printf("%d la so nguyen to",n);
	else printf("%d khong la so nguyen to",n);
}

bool prime(int n) {
	if (n < 2) return false;
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}