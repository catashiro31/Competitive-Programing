#include <iostream>
using namespace std;
int main() {
	string xau;
	cin >> xau;
	int tk[26] = {};
	for (int i = 0; i < 26; i++) {
		tk[i] = 0;
	}
	int size = xau.length();
	for (int i = 0; i < size; i++) {
		tk[int(xau[i])-97]++;
	}
	int count = 0, max = 0;
	char tmp;
	for (int i = 0; i < 26; i++) {
		if (tk[i] != 0) count++;
		if (tk[i] > max) {
			max = tk[i];
			tmp = char(i+97);
		}
	}
	cout << "So luong ki tu xuat hien: " << count;
	cout << "\nKi tu xuat hien nhieu nhat: " << tmp << " " << max;
}