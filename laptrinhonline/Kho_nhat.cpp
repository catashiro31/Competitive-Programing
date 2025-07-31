#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int k;
	int arr[32] = {};
	for (int i = 0; i <= 32; i++) {
		arr[i] = 1;
	}
	for (int i = 2; i <= 32; i++) {
		if (arr[i] == 0) {
			continue;
		}
		for (int j = i*i; j <= 32; j+=i) {
			arr[j] = 0; 
		}
	}
	
}