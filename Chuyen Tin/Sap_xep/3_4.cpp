#include <iostream>
#include <string>
using namespace std;
int main() {
	int N,k;
	cin >> N >> k;
	string xau ="";
	for (int i = 1; i <= N; i++) {
		xau += to_string(i);
	}
	int count = 0,tmp;
	while (k != 0) {
		char max = ' ';
		if (count+k == xau.length()) {
			xau.erase(count);
			break;
		}
		for (int i = count; i < count+k+1; i++) {
			if (xau[i] == '\0') {
				break;
			}
			if (xau[i] > max) {
				max = xau[i];
				tmp = i;
			}
		}
		k-= tmp-count;
		xau.erase(count,tmp-count);
		count++;
	}
	cout << xau;
}