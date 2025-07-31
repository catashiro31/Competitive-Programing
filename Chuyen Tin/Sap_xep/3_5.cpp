#include <iostream>
#include <string>
using namespace std;
int UCLN(int a, int b) {
	int tmp;
	while (b>0) {
		a%=b;
		tmp = a;
		a = b;
		b = tmp;
	}
	return a;
}
int main() {
	int N, K;
	cin >> N >> K;
	int size = 2+(N+1)*N/2;
	float arr[size][2] = {};
	arr[0][0] = 0;
	arr[0][1] = 1;
	arr[1][0] = 1;
	arr[1][1] = 1;
	int count = 2,uoc;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			uoc = UCLN(i,j);
			arr[count][0] = i/uoc;
			arr[count][1] = j/uoc;
			count++;
		}
	}
	cout << endl;
// Bubble_Sort
	int tmp1, tmp2;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size-1; j++) {
			if (arr[j][0]/arr[j][1] > arr[j+1][0]/arr[j+1][1]) {
				tmp1 = arr[j][0];
				tmp2 = arr[j][1];
				arr[j][0] = arr[j+1][0];
				arr[j][1] = arr[j+1][1];
				arr[j+1][0] = tmp1;
				arr[j+1][1] = tmp2; 
			}
		}
	}
	int z = 0;
	while (0 == 0) {
		if (z >= size) {
			cout << "K over limit";
			break;
		}
		if (arr[z][0]/arr[z][1] < arr[z+1][0]/arr[z+1][1]) {
			K--;
		}
		if (K == 0) {
			cout << to_string(int(arr[z][0])) + "/" + to_string(int(arr[z][1])) << endl;
			break;
		}
		z++;
	}
}