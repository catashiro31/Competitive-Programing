#include <iostream>
using namespace std;
int main() {
	int q;
	cin >> q;
	long long n[q];
	int count,kq;
	long long tmp;
	for (int i = 0; i < q; ++i) cin >> n[i];
	for (int i = 0; i < q; ++i) {
		kq = 0;
		while (true) {
			tmp = n[i];
			count = 0;
			while (tmp != 0) {
				count += tmp%10;
				tmp = tmp/10;
			}
			if (n[i]%count == 0 and count%3 == 0) {
				kq+=n[i]/count;
				break;
			} else {
				n[i] = n[i]-count;
				kq++;
			}
		}
		cout << kq << " ";
	}
}